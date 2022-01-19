#include "MysticLevelData.hpp"
#include "MysticPlayer.hpp"
#include "MysticEnemy.hpp"
#include <iostream>
#include "string"

using namespace std;


// 2D Collision Function
int GetCollision(int x, int y , int w, int h, int x2 , int y2 , int w2 , int h2){
    if( y+h <= y2 )
    {
        return false;
    }

    if( y >= y2+h2 )
    {
        return false;
    }

    if( x+w <= x2 )
    {
        return false;
    }

    if( x >= x2+w2 )
    {
        return false;
    }

    return true;

}


// Level Drawing Function
static void MysticDrawLevel(wstring LevelData, int Level_Width , int Level_Height, wchar_t ShaderBlock1 , wchar_t ShaderBlock2 , wchar_t ShaderBlock3 , wchar_t ShaderBlock4 ){
    for (int x = (MysticCamera.XOffset) / 20; x <=  (MysticCamera.XOffset + 640) / 20 ;  x ++ ){
        for (int y = 0; y <=  Level_Height;  y ++ ){
            switch (LevelData[y*Level_Width+x ]) {
                case L'^':
                    if (!MysticPlayerOne.CanShoot && MysticCoreData.LevelID != 30){

                        if (MysticCoreData.AnimationTicker >= 50){

                            DrawRectangleRoundedLines({ x * 20 - MysticCamera.XOffset - 30,   y * 20  + MysticCamera.YOffset - 40 - MysticCoreData.HoverAnimationTicker / 4 , 80, 30 }, .5, 0, 1, RED);
                            DrawText("Space",  x * 20 - MysticCamera.XOffset - 13 ,   y * 20  + MysticCamera.YOffset - 30 - MysticCoreData.HoverAnimationTicker / 4, 15 , WHITE);

                        }

                        DrawText("->",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - MysticCoreData.HoverAnimationTicker / 4  , 20 , DARKGRAY);
                    }

                    if (MysticCoreData.LevelID == 30 && !MysticPlayerOne.HasRocket){
                        if (MysticCoreData.AnimationTicker >= 50){

                            DrawRectangleRoundedLines({ x * 20 - MysticCamera.XOffset - 30,   y * 20  + MysticCamera.YOffset - 40 - MysticCoreData.HoverAnimationTicker / 4 , 80, 30 }, .5, 0, 1, RED);
                            DrawText("Click",  x * 20 - MysticCamera.XOffset - 13 ,   y * 20  + MysticCamera.YOffset - 30 - MysticCoreData.HoverAnimationTicker / 4, 15 , WHITE);

                        }
                        DrawText("|-.->>",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - MysticCoreData.HoverAnimationTicker / 4  , 20 , DARKGRAY);
                    }
                    break;
                case L'A':
                    DrawText("#",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset, 20 , GRAY);
                    break;
                case L'B':
                    DrawText("#",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset, 20 , DARKGRAY);
                    break;
                case L'C':
                    DrawText("@",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset, 20 , GRAY);
                    break;
                case L'D':
                    DrawText("@",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset, 20 , DARKGRAY);
                    break;
                case L'E':
                    DrawText("^",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset, 20 , ORANGE);
                    break;
                case L'F':
                    DrawText("#",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , BLUE);
                    break;
                case L'G':
                    DrawText("*",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , DARKBROWN);
                    break;
                case L'H':
                    DrawText("$",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , SKYBLUE);
                    break;
                case L'I':
                    DrawText("$",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , DARKPURPLE);
                    break;
                case L'J':
                    DrawText("*",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , PINK);
                    break;
                case L'K':
                    DrawText("#",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , LIME);
                    break;
                case L'L':
                    DrawText("#",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , GOLD);
                    break;
               case L'M':
                    DrawText("#",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , VIOLET);
                    break;
                case L'N':
                    DrawText("*",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , ORANGE);
                    break;
                case L'O':
                    DrawText("*",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , MAGENTA);
                    break;
                case L'P':
                    DrawText("$",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , DARKGREEN);
                    break;
                case L'1':
                    DrawText("#",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , GREEN);
                    break;
                case L'2':
                    DrawText("%",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , YELLOW);
                    break;
                case L'3':
                    DrawText("&",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , WHITE);
                    break;
                case L'4':
                    DrawText("^",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , BLUE);
                    break;
                case L'5':
                    DrawText("*",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , BROWN);
                    break;
                case L'6':
                    DrawText("@",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , WHITE);
                    break;
                case L'7':
                    DrawText("E",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , WHITE);
                    break;
                case L'8':
                    DrawText("A",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , WHITE);
                    break;
                case L'9':
                    DrawText("#",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , WHITE);
                    break;
                case L'%':
                    DrawText("%",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , PURPLE);
                    break;
                case L'!':
                    if (MysticPlayerOne.HeartVisable){
                        DrawText("#",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3  - MysticCoreData.HoverAnimationTicker / 4, 32 , RED);
                    }
                    break;
                case L'Q':
                    if (MysticCoreData.BreakTimer >= 50) {
                        DrawText("#",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset, 20 , DARKGRAY);
                    }
                    else {
                        DrawText("#",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset, 20 , DARKGRAY);
                    }
                    break;
                case L'R':
                    if (MysticCoreData.BreakTimer >= 50) {
                        DrawText("%",  x * 20 - MysticCamera.XOffset,   y * 20  + MysticCamera.YOffset - 3, 32 , GOLD);
                    }
                    break;
                case L'+': 
                    if (MysticCoreData.LevelEditor){
                        DrawText("@",x*20  - MysticCamera.XOffset,(y *20) - 80, 40 , WHITE);
                        DrawText("@",x*20  - MysticCamera.XOffset,(y *20) - 40, 40 , BLUE);
                    }
                    break;
                case L'&':
                    if (MysticCoreData.LevelEditor){
                        DrawText("@",x*20  - MysticCamera.XOffset,(y *20) - 80, 40 , DARKGRAY);
                        DrawText("@",x*20  - MysticCamera.XOffset,(y *20) - 40, 40 , RED);
                    }
                    break;
                case L'Z':
                    if (MysticCoreData.LevelEditor){
                        DrawRectangle(x*20- MysticCamera.XOffset,y*20,20,20,RED);
                    }
                    break;
            }     
        }   
    }

    if (MysticCamera.XOffset <= 0){
        MysticCamera.XOffset = 0;
        MysticCamera.BackgroundParrallaxX1 = 0;
        MysticCamera.BackgroundParrallaxX2 = 120;
        MysticCamera.BackgroundParrallaxX3 = 240;
    }


    if (MysticCamera.XOffset >= Level_Width *20 - 640){
        MysticCamera.XOffset = Level_Width *20 - 640;
    }

    if (MysticPlayerOne.x >= 25 ){
        MysticPlayerOne.x -= 5 + MysticPlayerOne.Acceloration / 5;
        MysticCamera.XOffset += 6 + MysticPlayerOne.Acceloration / 5;
    }

    if (MysticPlayerOne.x <= 280 ){
        MysticPlayerOne.x += 5;
        MysticCamera.XOffset -= 6 + MysticPlayerOne.Acceloration / 5;
    }

}




