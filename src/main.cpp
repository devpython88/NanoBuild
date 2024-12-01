#include "player.h"
#include "block.h"
#include "other.h"
namespace fs = std::filesystem;

std::vector<Block> blocks;

float getCenterX(){
    return (GetScreenWidth() / 2) - DEFAULT_SIZE;
}
float getCenterY(){
    return (GetScreenHeight() / 2) - DEFAULT_SIZE;
}

/* DRAW BLOCKS */
void drawBlock(Block bl){
    DrawTextureRec(bl.texture, bl.getRect(), {bl.getX(), bl.getY()}, WHITE);
}

/* DESTROY BLOCKS */
void removeBlock(float x, float y){
    for (int i = blocks.size() - 1; i >= 0; i--){
        Block b = blocks.at(i);

        if (b.getX() == x && b.getY() == y){
            UnloadTexture(blocks[i].texture);
            blocks.erase(blocks.begin() + i);
            return;
        }
    }
}

int main(){
    std::vector<TextureObject> textures; // Key: Readable name, Value: Path
    loadTextureFiles(&textures);

    if (textures.empty()){
        std::cerr << "No textures were succesfully loaded. Aborting...\n";
        return -1;
    }
    
    /* INITIALISATION */
 
    InitWindow(800, 600, "Nano Build");
    SetTargetFPS(24);

    /* PLAYER AND CAMERA */

    Rectangle player = { 0, 0, DEFAULT_SIZE, DEFAULT_SIZE };

    Camera2D cam = { 0 };
    cam.target = { player.x, player.y };
    cam.zoom = 1.0f; 
    cam.rotation = 0;
    cam.offset = { getCenterX(), getCenterY() };

    /* CURRENT BLOCK AND SHI */
    std::string currentBlockTextureName = "Planks"; // dont fix, in the loop it'll use the if statement to set it to cobble
    int currentTextureIndex = 0;
    std::string oldBlockTextureName = currentBlockTextureName;
    while (!WindowShouldClose()){
        if (oldBlockTextureName != currentBlockTextureName){
            oldBlockTextureName = currentBlockTextureName;
        }

        if (currentBlockTextureName != textures[currentTextureIndex].getName()){
            currentBlockTextureName = textures[currentTextureIndex].getName();
        }
        /* PLAYER MOVEMENT */

        if (IsKeyPressed(KEY_W) && !IsKeyDown(KEY_LEFT_SHIFT)) movePlayer(&player, 0, DEFAULT_SIZE, &cam, blocks);
        if (IsKeyPressed(KEY_S) && !IsKeyDown(KEY_LEFT_SHIFT)) movePlayer(&player, 0, -DEFAULT_SIZE, &cam, blocks);
        if (IsKeyPressed(KEY_A) && !IsKeyDown(KEY_LEFT_SHIFT)) movePlayer(&player, DEFAULT_SIZE, 0, &cam, blocks);
        if (IsKeyPressed(KEY_D) && !IsKeyDown(KEY_LEFT_SHIFT)) movePlayer(&player, -DEFAULT_SIZE, 0, &cam, blocks);
        if (IsKeyPressed(KEY_RIGHT_SHIFT)) placeBlock(player.x, player.y, &blocks, LoadTexture(textures[currentTextureIndex].getPath().c_str()));
        if (IsKeyDown(KEY_LEFT_SHIFT)){
            if (IsKeyDown(KEY_W)) removeBlock(player.x, player.y - DEFAULT_SIZE);
            if (IsKeyDown(KEY_S)) removeBlock(player.x, player.y + DEFAULT_SIZE);
            if (IsKeyDown(KEY_A)) removeBlock(player.x - DEFAULT_SIZE, player.y);
            if (IsKeyDown(KEY_D)) removeBlock(player.x + DEFAULT_SIZE, player.y);
            // Else just remove the block under the player
            else removeBlock(player.x, player.y);
        }

        /* BLOCK SELECTION LOGIC */
        if (IsKeyPressed(KEY_TAB)){
            if (currentBlockTextureName == textures[textures.size() - 1].getName()){
                currentTextureIndex = 0;
                currentBlockTextureName = textures[currentTextureIndex].getName();
            }
            else {
                currentTextureIndex++;
                currentBlockTextureName = textures[currentTextureIndex].getName();
            }
        }

        /* DRAWING LOGIC */
        BeginDrawing();
        BeginMode2D(cam);
        ClearBackground(SKYBLUE);
        
        for (Block bl : blocks) drawBlock(bl);
        DrawRectangleRec(player, RED);

        EndMode2D();

        showCurrentlySelectedBlock(currentBlockTextureName);
      
        EndDrawing();
    }

    for (Block b : blocks){
        UnloadTexture(b.texture);
    }

    CloseWindow();
}