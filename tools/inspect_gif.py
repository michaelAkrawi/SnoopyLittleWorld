from PIL import Image
import sys
from pathlib import Path


def inspect_gif(path: str):
    gif_path = Path(path)

    if not gif_path.exists():
        print(f"File not found: {gif_path}")
        sys.exit(1)

    image = Image.open(gif_path)

    print(f"File:       {gif_path.name}")
    print(f"Size:       {image.width}x{image.height}")
    print(f"Format:     {image.format}")
    print(f"Frames:     {image.n_frames}")
    print(f"Loop:       {image.info.get('loop', 'unknown')}")

    durations = []

    for frame_index in range(image.n_frames):
        image.seek(frame_index)
        durations.append(image.info.get("duration", 0))

    total_duration = sum(durations)

    print(f"Duration:   {total_duration} ms")

    if image.n_frames > 0:
        print(f"Avg frame:  {total_duration / image.n_frames:.1f} ms")

    if total_duration > 0:
        fps = image.n_frames / (total_duration / 1000)
        print(f"Approx FPS: {fps:.1f}")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 tools/inspect_gif.py <gif>")
        sys.exit(1)

    inspect_gif(sys.argv[1])