#pragma once
#include "block.h"

/// @brief Moves player and camera
void movePlayer(Rectangle *player, int newX, int newY, Camera2D *cam, std::vector<Block> blocks);
bool checkCollision(int x, int y, std::vector<Block> blocks);