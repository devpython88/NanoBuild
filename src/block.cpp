#include "block.h"

void placeBlock(float x, float y, std::vector<Block> *array, Texture2D texture){
    std::cout << "Placing block at: (" << x << ", " << y << ")\n"; 

    Block block(x, y, DEFAULT_SIZE, DEFAULT_SIZE, texture);
    
    // Check if there is already a block here
    for (int i = 0; i < array->size(); i++){
        Block bl = array->at(i);
        if (bl.getX() == x && bl.getY() == y) return;
    }

    array->push_back(block);
}

Rectangle Block::getRect()
{
    return (Rectangle) { x, y, width, height };
}
