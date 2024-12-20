#pragma once
#include "block.h"
#include "structures.h"
#include <filesystem>
#include <regex>
namespace fs = std::filesystem;

void showCurrentlySelectedBlock(std::string currentBlockName);
void loadTextureFiles(std::vector<TextureObject> *textures);
void generateTrees(int min, int max, int radius, std::vector<Block> *array);