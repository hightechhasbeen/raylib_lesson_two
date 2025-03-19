#include "raylib.h"
#include <vector>
#include <cstring>
#include <iostream>

int main(void)
{
  const int screenWidth = 450;
  const int screenHeight = 450;
  const int gameWidth = 300;
  const int gameHeight = 300;
  const int tileWidth = 100;
  const int tileHeight = 100;

  const int tilesPerRow = gameWidth / tileWidth;
  const int gamePositionX = (screenWidth - gameWidth) / 2;
  const int gamePositionY = (screenHeight - gameHeight) / 2;

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
        DrawTexture(tiles.at(tilecounter), x, y, WHITE);
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
