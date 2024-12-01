#include "other.h"

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
