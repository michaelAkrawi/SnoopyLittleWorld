#include "AnimationPlayer.h"

namespace
{
    File gifFile;
    TFT_eSPI *tft = nullptr;

    void *GIFOpenFile(const char *filename, int32_t *size)
    {
        gifFile = LittleFS.open(filename, "r");

        if (!gifFile)
        {
            return nullptr;
        }

        *size = gifFile.size();
        return &gifFile;
    }

    void GIFCloseFile(void *handle)
    {
        File *file = static_cast<File *>(handle);

        if (file != nullptr)
        {
            file->close();
        }
    }

    int32_t GIFReadFile(GIFFILE *gifFileInfo, uint8_t *buffer, int32_t length)
    {
        File *file = static_cast<File *>(gifFileInfo->fHandle);

        if ((gifFileInfo->iSize - gifFileInfo->iPos) < length)
        {
            length = gifFileInfo->iSize - gifFileInfo->iPos - 1;
        }

        if (length <= 0)
        {
            return 0;
        }

        int32_t bytesRead = file->read(buffer, length);
        gifFileInfo->iPos = file->position();

        return bytesRead;
    }

    int32_t GIFSeekFile(GIFFILE *gifFileInfo, int32_t position)
    {
        File *file = static_cast<File *>(gifFileInfo->fHandle);

        file->seek(position);
        gifFileInfo->iPos = file->position();

        return gifFileInfo->iPos;
    }

    void GIFDraw(GIFDRAW *draw)
    {
        if (tft == nullptr)
            return;

        const int xOffset = draw->iX;
        const int y = draw->iY + draw->y;

        if (y < 0 || y >= tft->height() ||
            xOffset < 0 || xOffset >= tft->width())
            return;

        const int width = min(draw->iWidth, tft->width() - xOffset);

        if (width <= 0)
            return;

        const uint8_t *source = draw->pPixels;
        const uint16_t *palette = draw->pPalette;

        static uint16_t lineBuffer[320];

        if (draw->ucHasTransparency)
        {
            const uint8_t transparent = draw->ucTransparent;
            const bool restoreBackground = (draw->ucDisposalMethod == 2);

            int x = 0;

            while (x < width)
            {
                while (x < width &&
                       source[x] == transparent &&
                       !restoreBackground)
                {
                    x++;
                }

                const int start = x;
                int count = 0;

                while (x < width &&
                       (restoreBackground || source[x] != transparent))
                {
                    const uint8_t index =
                        (source[x] == transparent)
                            ? draw->ucBackground
                            : source[x];

                    lineBuffer[count++] = palette[index];
                    x++;
                }

                if (count > 0)
                {
                    tft->pushImage(
                        xOffset + start,
                        y,
                        count,
                        1,
                        lineBuffer);
                }
            }
        }
        else
        {
            for (int x = 0; x < width; x++)
            {
                lineBuffer[x] = palette[source[x]];
            }

            tft->pushImage(
                xOffset,
                y,
                width,
                1,
                lineBuffer);
        }
    }

}

void AnimationPlayer::begin(Display &display)
{
    this->display = &display;
    tft = &display.tft();

    if (!LittleFS.begin())
    {
        Serial.println("[AnimationPlayer] LittleFS mount FAILED");
        return;
    }

    Serial.println("[AnimationPlayer] LittleFS mounted");

    gif.begin(LITTLE_ENDIAN_PIXELS);

    Serial.println("[AnimationPlayer] Ready");
}

void AnimationPlayer::play(const char *filename)
{
    stop();

    currentFile = filename;

    Serial.print("[AnimationPlayer] Opening: ");
    Serial.println(filename);

    if (!LittleFS.exists(filename))
    {
        Serial.println("[AnimationPlayer] GIF file not found");
        return;
    }

    if (!gif.open(
            filename,
            GIFOpenFile,
            GIFCloseFile,
            GIFReadFile,
            GIFSeekFile,
            GIFDraw))
    {

        Serial.print("[AnimationPlayer] GIF open failed: ");
        Serial.println(gif.getLastError());
        return;
    }

    Serial.print("[AnimationPlayer] GIF size: ");
    Serial.print(gif.getCanvasWidth());
    Serial.print("x");
    Serial.println(gif.getCanvasHeight());

    playing = true;
}

void AnimationPlayer::stop()
{
    if (!playing)
    {
        return;
    }

    gif.close();

    playing = false;
    currentFile = "";

    Serial.println("[AnimationPlayer] Stopped");
}

void AnimationPlayer::update()
{

    static unsigned long lastCall = 0;

    unsigned long now = millis();

    if (lastCall != 0 && now - lastCall > 20)
    {
        Serial.printf(
            "[UPDATE] Gap: %lu ms\n",
            now - lastCall);
    }

    lastCall = now;

    if (!playing)
        return;

    static unsigned long nextFrameAt = 0;
    static unsigned long previousFrameAt = 0;
    static int frameNumber = 0;


    if (now < nextFrameAt)
        return;

    int frameDelay = 0;
    unsigned long frameStart = millis();

    bool hasFrame = gif.playFrame(false, &frameDelay);

    if (!hasFrame)
    {
        gif.reset();
        frameNumber = 0;
        nextFrameAt = millis();
        previousFrameAt = 0;
        return;
    }

    unsigned long drawTime = millis() - frameStart;
    unsigned long interval = previousFrameAt == 0
                                 ? 0
                                 : frameStart - previousFrameAt;

    Serial.printf(
        "[GIF] Frame %d | Interval: %lu | Draw: %lu | Delay: %d\n",
        frameNumber,
        interval,
        drawTime,
        frameDelay);

    previousFrameAt = frameStart;
    nextFrameAt = millis();
    frameNumber++;
}

bool AnimationPlayer::isPlaying() const
{
    return playing;
}