#include "structures.h"

std::vector<Block> treeBase = std::vector<Block>();

void initStructureModule()
{
    treeBase = std::vector<Block>({
        Block(0.0f, 0.0f, DEFAULT_SIZE, DEFAULT_SIZE, LoadTexture(".\\assets\\wood.png")),
        Block(0.0f, -32.0f, DEFAULT_SIZE, DEFAULT_SIZE, LoadTexture(".\\assets\\wood.png")),
        Block(0.0f, -64.0f, DEFAULT_SIZE, DEFAULT_SIZE, LoadTexture(".\\assets\\wood.png")),
        Block(0.0f, -96.0f, DEFAULT_SIZE, DEFAULT_SIZE, LoadTexture(".\\assets\\leaves.png")),
        Block(-32.0f, -96.0f, DEFAULT_SIZE, DEFAULT_SIZE, LoadTexture(".\\assets\\leaves.png")),
        Block(32.0f, -96.0f, DEFAULT_SIZE, DEFAULT_SIZE, LoadTexture(".\\assets\\leaves.png")),
        Block(0.0f, -128.0f, DEFAULT_SIZE, DEFAULT_SIZE, LoadTexture(".\\assets\\leaves.png")),
    });
    // copy this array and adjust the values to make trees.
}

std::vector<Block> getTreeArray(float startX, float startY)
{  
    std::vector<Block> tree = treeBase;

    tree[0].setX(startX);
    tree[0].setY(startY);
    
    
    tree[1].setX(startX);
    tree[1].setY(startY - 32.0f);
    
    
    tree[2].setX(startX);
    tree[2].setY(startY - 64.0f);
    
    
    tree[3].setX(startX);
    tree[3].setY(startY - 96.0f);
    
    
    tree[4].setX(startX - 32.0f);
    tree[4].setY(startY - 96.0f);
    
    
    tree[5].setX(startX + 32.0f);
    tree[5].setY(startY - 96.0f);
    
    
    tree[6].setX(startX);
    tree[6].setY(startY - 128.0f);
    
    return tree;
}
