#include "player.h"

void movePlayer(Rectangle *player, int newX, int newY, Camera2D *cam, std::vector<Block> blocks){
    if (!checkCollision(player->x - newX, player->y - newY, blocks)) player->y -= newY;
    if (!checkCollision(player->x - newX, player->y - newY, blocks )) player->x -= newX;
    cam->target.y = player->y;
    cam->target.x = player->x;
}

bool checkCollision(int x, int y, std::vector<Block> blocks)
{
    for (Block bl : blocks){
        if (bl.getX() == x && bl.getY() == y) return true;
    }
    return false;
}
