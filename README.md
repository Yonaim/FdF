# FDF - Wireframe 3D Model Viewer

FDF (\"Fil de Fer\") is a program that reads a map file and visualizes it as a wireframe 3D model. The name \"FDF\" is derived from the French phrase \"Fil de Fer,\" meaning \"wireframe model.\"

## Features

- **3D Wireframe Visualization:** Reads map files and generates interactive wireframe models.
- **Interactive Controls:** Independently manipulate object and camera position, zoom, rotation, and elevation.
- **Orthogonal Projection:** Offers orthogonal projections without perspective distortion.

## Controls

It's also written in the manual, which you can view by pressing the 'F1' button.

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
| `F1`                                | Toggle manual menu                            |

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

<img src="/assets/screenshot_42.png" width="800"/>
<img src="/assets/screenshot_mars.png" width="800"/>
<img src="/assets/screenshot_manual.png" width="800"/>

## Demo

The first two images are object manipulations, and the last two are camera manipulations, which can rotate and translate respectively.

#### object
<img src="/assets/object_rotation.gif" width="600"/>
<img src="/assets/object_translation.gif" width="600"/>

#### camera
<img src="/assets/camera_rotation.gif" width="600"/>
<img src="/assets/camera_translation.gif" width="600"/>

