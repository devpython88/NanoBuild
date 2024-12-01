set -e

cd /c/sadik/NanoBuild/build
/usr/bin/ccmake.exe -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
