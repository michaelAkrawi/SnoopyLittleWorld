from PIL import Image
from pathlib import Path
import sys


TARGET_SIZE = (320, 240)


def process_gif(source_path: str, output_path: str):
    source = Path(source_path)
    output = Path(output_path)

    if not source.exists():
        print(f"File not found: {source}")
        sys.exit(1)

    output.parent.mkdir(parents=True, exist_ok=True)

    image = Image.open(source)

    frames = []
    durations = []

    for frame_index in range(image.n_frames):
        image.seek(frame_index)

        frame = image.convert("RGBA")
        frame = frame.resize(TARGET_SIZE, Image.Resampling.LANCZOS)

        frames.append(frame)
        durations.append(image.info.get("duration", 80))

    frames[0].save(
        output,
        save_all=True,
        append_images=frames[1:],
        duration=durations,
        loop=0,
        disposal=2,
        optimize=True,
    )

    print(f"Created: {output}")
    print(f"Size:    {TARGET_SIZE[0]}x{TARGET_SIZE[1]}")
    print(f"Frames:  {len(frames)}")
    print(f"Duration:{sum(durations)} ms")


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(
            "Usage: python3 tools/process_gif.py "
            "<source.gif> <output.gif>"
        )
        sys.exit(1)

    process_gif(sys.argv[1], sys.argv[2])