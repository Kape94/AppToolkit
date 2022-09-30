# AppToolkit

A simple library to develop graphical applications. 

This library creates a window context and handles user input with GLFW. Also, it has support for developing UI with ImGui. 

## Handling dependencies

This toolkit has the following dependencies:
- GLFW;
- glew;
- glm;
- Imgui;

You can create a installation script like this:

```
git clone https://github.com/Microsoft/vcpkg.git

cd vcpkg

call bootstrap-vcpkg.bat

vcpkg --triplet x64-windows install glfw3
vcpkg --triplet x64-windows install glew
vcpkg --triplet x64-windows install glm

vcpkg install imgui[core,glfw-binding,opengl3-binding]:x64-windows

vcpkg install glfw3
vcpkg install glew
vcpkg install glm

vcpkg install imgui[core,glfw-binding,opengl3-binding]
```

## Building and application with this toolkit

With the dependencies installed with vcpkg, you can create a build script like the following:

```
SET VCPKG_TOOLCHAIN=<path_to_vcpkg>/scripts/buildsystems/vcpkg.cmake

mkdir BUILD
cd BUILD

cmake ../Src -DCMAKE_TOOLCHAIN_FILE=../%VCPKG_TOOLCHAIN%
cmake --build . 

pause
```

...
