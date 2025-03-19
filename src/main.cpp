#include "raylib.h"
#include <vector>
#include <cstring>
#include <iostream>

const int screenWidth = 450;
const int screenHeight = 450;
const int gameWidth = 300;
const int gameHeight = 300;
const int tileWidth = 100;
const int tileHeight = 100;

const int tilesPerRow = gameWidth / tileWidth;
const int gamePositionX = (screenWidth - gameWidth) / 2;
const int gamePositionY = (screenHeight - gameHeight) / 2;

int LocateMouse(void) {
  int tileNumber = 1;  // Change the one to a zero
  int mouseX = GetMouseX() - gamePositionX;
  int mouseY = GetMouseY() - gamePositionY;

  /***** PUT YOUR WORK HERE *****/
  // Convert the mouse position (given in pixels) into the number of a specific tile.
  // Tiles are numbered like this:
  //          |     |     |     |
  //          |  0  |  1  |  2  |
  //          |     |     |     |
  //           =================
  //          |     |     |     |
  //          |  3  |  4  |  5  |
  //          |     |     |     |
  //           =================
  //          |     |     |     |
  //          |  6  |  7  |  8  |
  //          |     |     |     |
  // and they are 100 x 100 pixels.
  
  return tileNumber;
}

int main(void)
{


  InitWindow(screenWidth, screenHeight, "Lesson One");

  std::vector<Texture2D> tiles;
  for (int tilenumber = 0; tilenumber < 9; tilenumber++) {
    char tilepath[32];
    std::sprintf(tilepath, "resources/Tile_%d.png", tilenumber);
    tiles.push_back(LoadTexture(tilepath));
  }

  SetTargetFPS(15);
  while (!WindowShouldClose())
  {
    int selectedTile = 0;

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
      selectedTile = LocateMouse();
    }

    BeginDrawing();
    {
      ClearBackground(SKYBLUE);
      DrawRectangle(gamePositionX, gamePositionY, gameWidth, gameHeight, LIGHTGRAY);
      DrawRectangleLines(gamePositionX,
                         gamePositionY,
                         gameWidth,
                         gameHeight,
                         BLACK);
      for (int tilecounter = 0; static_cast<size_t>(tilecounter) < tiles.size(); tilecounter++)
      {
        int rowNumber = tilecounter / tilesPerRow;
        int colNumber = tilecounter % tilesPerRow;
        int x = gamePositionX + (colNumber * tileWidth);
        int y = gamePositionY + (rowNumber * tileHeight);
        if (tilecounter == selectedTile) 
        {
          DrawTexture(tiles.at(tilecounter), x, y, PINK);
        } else {
          DrawTexture(tiles.at(tilecounter), x, y, WHITE);
        }
      }

    }
    EndDrawing();
  }

  for (Texture2D tile: tiles) 
  {
    UnloadTexture(tile);
  }

  CloseWindow();

  return 0;
}



/**********************************************************************
 One possible solution:
 
 int LocateMouse(void) {
  int tileNumber = 0;
  int mouseX = GetMouseX() - gamePositionX;
  int mouseY = GetMouseY() - gamePositionY;

  if (mouseX > 0 && mouseX < gameWidth && mouseY > 0 && mouseY < gameHeight)
  {
    tileNumber = tilesPerRow * (mouseY / tileHeight) + (mouseX / tileWidth);
  }

  return tileNumber;
}
 **********************************************************************/
