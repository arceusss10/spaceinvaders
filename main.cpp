#include <raylib.h>
#include "game.hpp"
#include<string>

std::string FormatWithLeadingZeros(int num, int wid){
  std::string numberText = std::to_string(num);
    int leadingzeros = wid - numberText.length();
   return numberText = std::string(leadingzeros, '0') + numberText; 
}

int main()
{
   Color grey = {29,29,27,255};
   Color yellow = {243, 216, 63, 255};
   int windowWidth = 800;
   int windowHeight = 800;
   InitWindow(windowWidth, windowHeight, "Space Invaders");

   Font font = LoadFontEx("font/monogram.ttf", 64, 0, 0);
   Texture2D spaceshipimg = LoadTexture("pictures/spaceship.png");
   SetTargetFPS(60);
 
   Game game;
   

   while(WindowShouldClose() == false){

    game.HandleInput();
    game.Update();
    BeginDrawing();
    ClearBackground(grey);
    DrawRectangleRoundedLines({10,10,780,780}, 0.18f, 20,2,yellow);
    DrawLineEx({25,730}, {775, 730}, 3, yellow);
    if(game.run){
      DrawTextEx(font, "LEVEL 01", {570, 740}, 34, 2, yellow);
    } else if(game.run == false && game.win == false){
      DrawTextEx(font, "GAME OVER", {570, 740}, 34, 2, yellow);
    } else {
      DrawTextEx(font, "GAME FINISHED, YOU WON!", {125, 300}, 50, 2, yellow);
      DrawTextEx(font, "(PRESS ENTER TO RESTART)", {125, 400}, 45, 2, yellow);
    }
    float x = 50.0;
    for(int i =0; i<game.lives; i++){
        DrawTextureV(spaceshipimg, {x,745}, WHITE);
        x += 50;
    }

    DrawTextEx(font, "SCORE",{50,15}, 34, 2, yellow);
    std:: string scoreText = FormatWithLeadingZeros(game.score, 5);
    DrawTextEx(font, scoreText.c_str(), {50,40}, 34, 2, yellow);

    DrawTextEx(font, "HIGH-SCORE", {570,15}, 34, 2, yellow);
    std::string highscoretext = FormatWithLeadingZeros(game.highscore, 5);
    DrawTextEx(font, highscoretext.c_str(), {655,40}, 34, 2, yellow);  

    

    game.Draw();
    
    EndDrawing();
   }

   CloseWindow();
    
}