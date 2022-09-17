SET VCPKG_TOOLCHAIN=vcpkg/scripts/buildsystems/vcpkg.cmake

mkdir BUILD
cd BUILD

cmake ../Src -DCMAKE_TOOLCHAIN_FILE=../%VCPKG_TOOLCHAIN%
cmake --build . 

pause