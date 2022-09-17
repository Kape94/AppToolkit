git clone https://github.com/Microsoft/vcpkg.git

cd vcpkg

call bootstrap-vcpkg.bat

vcpkg --triplet x64-windows install glfw3
vcpkg --triplet x64-windows install glew
vcpkg --triplet x64-windows install glm
vcpkg --triplet x64-windows install imgui

vcpkg install glfw3
vcpkg install glew
vcpkg install glm
vcpkg install imgui

pause