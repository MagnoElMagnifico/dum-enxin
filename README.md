# DumEnxin

Basic Doom Style Raycaster.

# Compilation

First clone the repository and open it in a terminal.

```sh
git clone https://github.com/MagnoElMagnifico/dum-enxin
cd dum-enxin
```

Before compiling, you should download the dependencies, in this case [SDL2].
Prebuilt binaries can be found under the [SDL2's Gihub Releases] page (note that
you will need the development version, which includes de header files). If you
are on Linux, it may be install with your package manager (package name
`libsdl2-dev`).

Extract the downloaded files under the `lib` directory.


We use [CMake] as our build system. You may download it from the [CMake
download] webpage.

```sh
mkdir build
cmake . -B build
cmake --build build
```

Note that you may also need to specify a generator:

```sh
# See what generators you have avaliable
cmake -G
# Use this command instead of `cmake . -B build`
cmake . -B build -G "generator name"
```

[SDL2]:                  https://www.libsdl.org/
[SDL2's Gihub Releases]: https://github.com/libsdl-org/SDL/releases
[CMake]:                 https://cmake.org/
[CMake download]:        https://cmake.org/download/
