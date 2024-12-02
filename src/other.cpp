#include "other.h"
#include <cmath>

void showCurrentlySelectedBlock(std::string currentBlockName)
{
      
    /* UI */
    std::string blockDisplayText = "Selected block: " + currentBlockName;
    DrawText(blockDisplayText.c_str(), 0, 0, 16, BLACK);
}

void loadTextureFiles(std::vector<TextureObject> *textures)
{
    for (const auto& file : fs::directory_iterator(".\\assets\\")){
        if (!file.is_regular_file()) continue;

        std::string fileName = file.path().filename().generic_string();
        fileName = std::regex_replace(fileName, std::regex(file.path().extension().generic_string()), "");
        fileName[0] = std::toupper(fileName[0]);
        
        textures->push_back(TextureObject(fileName, file.path().generic_string()));

        std::cout << fileName << ": " << file.path().generic_string() << "\n";
    }
}

void generateTrees(int min, int max, int radius, std::vector<Block> *array)
{
    initStructureModule();
    int amount = GetRandomValue(min, max);

    std::vector<std::vector<Block>> trees;

    for (int i = 0; i <= amount; i++){
        float x = (float) (std::round(GetRandomValue(-radius, radius) / 32.0f) * 32.0f);
        float y = (float) (std::round(GetRandomValue(-radius, radius) / 32.0f) * 32.0f);
        
        trees.push_back(getTreeArray(x, y));
    }


    for (std::vector<Block> tree : trees){
        for (Block block : tree){
            array->push_back(block);
        }
    }
}
