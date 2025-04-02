# FDF - Wireframe 3D Model Viewer

FDF (\"Fil de Fer\") is a program that reads a map file and visualizes it as a wireframe 3D model. The name \"FDF\" is derived from the French phrase \"Fil de Fer,\" meaning \"wireframe model.\"

## Features

- **3D Wireframe Visualization:** Reads map files and generates interactive wireframe models.
- **Interactive Controls:** Independently manipulate object and camera position, zoom, rotation, and elevation.
- **Orthogonal Projection:** Offers orthogonal projections without perspective distortion.

## Controls

| Control                             | Action                                        |
|-------------------------------------|-----------------------------------------------|
| `Mouse Scroll`                      | Zoom in / Zoom out                            |
| `+`, `-`                            | Adjust object elevation                       |
| `TAB`                               | Switch between OBJECT and CAMERA modes        |
| `ALT`                               | Toggle Axis display ON/OFF                    |
| `W`, `A`, `S`, `D`, `Z`, `X`        | Adjust Position (Object/Camera independently) |
| `I`, `O`, `K`, `L`, `<`, `>`        | Adjust Rotation (Object/Camera independently) |
| `R`                                 | Reset all transformations                     |
| `KEY 1~8`                           | Switch between various isometric views        |
| `NUMPAD 1~9`                        | Switch between general predefined views       |
| `F1`                                | Toggle manual/help menu                       |

## Libraries Used

- **libft** (custom):
  - A personal C library providing common utility functions such as string manipulation, memory management, and linked lists. Developed for reuse across multiple projects.

- **MiniLibX (mlx)**:
  - A graphical library provided by École 42 for simple graphics rendering, window management, and event handling.

## Installation

Clone the repository and compile using the provided Makefile:

```bash
git clone https://github.com/Yonaim/FdF.git
cd FdF
make
```

## Usage

Run the executable with a valid map file:

```bash
./fdf [map_file]
```

Example:

```bash
./fdf maps/42.fdf
```

## Screenshots

![FDF Screenshot_42](/assets/screenshot_42.png)
![FDF Screenshot_mars](/assets/screenshot_mars.png)
![FDF Screenshot_manual](/assets/screenshot_manual.png)

## Demo

![FDF Demo GIF Object Rotation](/assets/object_rotation.gif)
![FDF Demo GIF Object Translation](/assets/object_translation.gif)

![FDF Demo GIF Camera Rotation](/assets/camera_rotation.gif)
![FDF Demo GIF Camera Translation](/assets/camera_translation.gif)
