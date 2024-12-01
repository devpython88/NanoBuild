set -e

cd /c/sadik/NanoBuild/build
/usr/bin/cmake.exe --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
