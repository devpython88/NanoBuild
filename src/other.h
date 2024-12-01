#pragma once
#include "block.h"
#include <filesystem>
#include <regex>
namespace fs = std::filesystem;

void showCurrentlySelectedBlock(std::string currentBlockName);
void loadTextureFiles(std::vector<TextureObject> *textures);