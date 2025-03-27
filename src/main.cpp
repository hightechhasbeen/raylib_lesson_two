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
const int buttonWidth = 350;
const int buttonHeight = 108;

const int tilesPerRow = gameWidth / tileWidth;
const int gamePositionX = (screenWidth - gameWidth) / 2;
const int gamePositionY = ((screenHeight - buttonHeight) - gameHeight) / 2;
const int buttonPositionX = (screenWidth - buttonWidth) / 2;
const int buttonPositionY = (screenHeight - buttonHeight + gameHeight) / 2;

int LocateMouse(void) {
  int tileNumber = 0;
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
  bool stateDisplayImage = true;
  InitWindow(screenWidth, screenHeight, "Lesson Two");

  std::vector<Texture2D> numberedTiles;
  std::vector<Texture2D> imageTiles;
  for (int tilenumber = 0; tilenumber < 9; tilenumber++) {
    char tilepath[32];
    std::sprintf(tilepath, "resources/Tile_%d.png", tilenumber);
    numberedTiles.push_back(LoadTexture(tilepath));
    std::sprintf(tilepath, "resources/Image_%d.png", tilenumber);
    imageTiles.push_back(LoadTexture(tilepath));
  }
  std::vector<Texture2D> imageButton;
  imageButton.push_back(LoadTexture("resources/unpressed.png"));
  imageButton.push_back(LoadTexture("resources/pressed.png"));

  SetTargetFPS(15);
  while (!WindowShouldClose())
  {
    int selectedTile = 0;

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
      selectedTile = LocateMouse();
      if (selectedTile == 0) {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();

        if ((mouseY > buttonPositionY) &&
        (mouseY < buttonPositionY + buttonHeight) &&
        (mouseX > buttonPositionX) &&
        (mouseX < buttonPositionX + buttonWidth)) {
          stateDisplayImage = !stateDisplayImage;
        }
      }
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
      std::vector<Texture2D> chosenTiles = stateDisplayImage ? imageTiles : numberedTiles; 
      for (int tilecounter = 0; static_cast<size_t>(tilecounter) < chosenTiles.size(); tilecounter++)
      {
        int rowNumber = tilecounter / tilesPerRow;
        int colNumber = tilecounter % tilesPerRow;
        int x = gamePositionX + (colNumber * tileWidth);
        int y = gamePositionY + (rowNumber * tileHeight);
        if (tilecounter == selectedTile) 
        {
          DrawTexture(chosenTiles.at(tilecounter), x, y, LIGHTGRAY);
        } else {
          DrawTexture(chosenTiles.at(tilecounter), x, y, WHITE);
        }
      }


      if (stateDisplayImage) {
        DrawTexture(imageButton[0], buttonPositionX, buttonPositionY, WHITE);
      } else {
        DrawTexture(imageButton[1], buttonPositionX, buttonPositionY, WHITE);
      }

    }
    EndDrawing();
  }

  for (Texture2D tile: numberedTiles) 
  {
    UnloadTexture(tile);
  }

  for (Texture2D tile: imageTiles)
  {
    UnloadTexture(tile);
  }

  for (Texture2D button:imageButton) {
    UnloadTexture(button);
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
