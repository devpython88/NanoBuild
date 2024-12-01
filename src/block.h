#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>
#define DEFAULT_SIZE 50.0f

class Block {
    private:
    float x, y, width, height;
    // int type; upcoming

    public:
    Texture2D texture;
    Block(float x, float y, float width, float height, Texture2D texture):
    x(x), y(y), width(width), height(height), texture(texture){}
    float getX(){ return x; }
    float getY(){ return y; }
    float getWidth(){ return width; }
    float getHeight(){ return height; }
    Rectangle getRect();
};


class TextureObject {
    private:
    std::string name;
    std::string path;

    public:
    TextureObject(std::string name, std::string path): name(name), path(path){}
    std::string getName() { return name; }
    std::string getPath() { return path; }
};

void placeBlock(float x, float y, std::vector<Block> *array, Texture2D texture);