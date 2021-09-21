#include "MysticLevelData.hpp"
#include "MysticPlayer.hpp"
#include "MysticEnemy.hpp"
#include <iostream>
#include "string"

using namespace std;


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



static void MysticDrawLevel(wstring LevelData, int Level_Width , int Level_Height, wchar_t ShaderBlock1 , wchar_t ShaderBlock2 , wchar_t ShaderBlock3 , wchar_t ShaderBlock4 ){
    for (int x = (MysticCamera.XOffset) / 20; x <=  (MysticCamera.XOffset + 640) / 20 ;  x ++ ){
        for (int y = 0; y <=  Level_Height;  y ++ ){
            if (!MysticCoreData.LowEndHardware){
                if (LevelData[y*Level_Width+x ] == ShaderBlock1){
                    BeginShaderMode(Core_Shaders.Water);
                }
                if (LevelData[y*Level_Width+x ] == ShaderBlock2){
                    BeginShaderMode(Core_Shaders.Water);
                }
                if (LevelData[y*Level_Width+x ] == ShaderBlock3){
                    BeginShaderMode(Core_Shaders.Water);
                }
                if (LevelData[y*Level_Width+x ] == ShaderBlock4){
                    BeginShaderMode(Core_Shaders.Water);
                }
            }
            
            switch (LevelData[y*Level_Width+x ]) {
                case L'^':
                    if (!MysticPlayerOne.CanShoot && MysticCoreData.Level_ID != 30){

                        if (MysticCoreData.Animation_Ticker >= 50){

                            DrawRectangleRoundedLines({ x * 20 - MysticCamera.XOffset - 30,  y * 20 + MysticCamera.YOffset - 40 - MysticCoreData.Hover_Animation_Ticker / 4 , 80, 30 }, .5, 0, 1, RED);

                            DrawText("Space",  x * 20 - MysticCamera.XOffset - 13 ,  y * 20 + MysticCamera.YOffset - 30 - MysticCoreData.Hover_Animation_Ticker / 4, 15 , WHITE);

                        }

                        DrawText("->",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - MysticCoreData.Hover_Animation_Ticker / 4  , 20 , DARKGRAY);
                    }

                    if (MysticCoreData.Level_ID == 30 && !MysticPlayerOne.HasRocket){
                        if (MysticCoreData.Animation_Ticker >= 50){

                            DrawRectangleRoundedLines({ x * 20 - MysticCamera.XOffset - 30,  y * 20 + MysticCamera.YOffset - 40 - MysticCoreData.Hover_Animation_Ticker / 4 , 80, 30 }, .5, 0, 1, RED);

                            DrawText("Click",  x * 20 - MysticCamera.XOffset - 13 ,  y * 20 + MysticCamera.YOffset - 30 - MysticCoreData.Hover_Animation_Ticker / 4, 15 , WHITE);

                        }
                        DrawText("|-.->>",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - MysticCoreData.Hover_Animation_Ticker / 4  , 20 , DARKGRAY);
                    }
                    
                    //DrawTexture(Level_Tiles.Tile_A, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - MysticCoreData.Hover_Animation_Ticker / 4 , WHITE );
                    break;

                case L'A':
                    DrawText("#",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, 20 , GRAY);
                    //DrawTexture(Level_Tiles.Tile_A, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - MysticCoreData.Hover_Animation_Ticker / 4 , WHITE );
                    break;
                case L'B':
                    DrawText("#",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, 20 , DARKGRAY);
                    //DrawTexture(Level_Tiles.Tile_B, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - MysticCoreData.Hover_Animation_Ticker / 4 , WHITE );

                    break;
                case L'C':
                    DrawText("@",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, 20 , GRAY);
                    //DrawTexture(Level_Tiles.Tile_C, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - MysticCoreData.Hover_Animation_Ticker / 4 , WHITE );

                    break;
                case L'D':
                    DrawText("@",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, 20 , DARKGRAY);
                    //DrawTexture(Level_Tiles.Tile_D, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - MysticCoreData.Hover_Animation_Ticker / 4 , WHITE );

                    break;
                case L'E':
                    DrawText("^",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, 20 , ORANGE);
                    //DrawTexture(Level_Tiles.Tile_E, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - MysticCoreData.Hover_Animation_Ticker / 4 , WHITE );
                    break;
                case L'F':
                    DrawText("#",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , BLUE);
                    //DrawTexture(Level_Tiles.Tile_F, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - MysticCoreData.Hover_Animation_Ticker / 4 , WHITE );
                    break;
                case L'G':
                    DrawText("*",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , DARKBROWN);
                   //DrawTexture(Level_Tiles.Tile_G, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset , WHITE );

                    break;
                case L'H':
                    DrawText("$",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , SKYBLUE);
                    //DrawTexture(Level_Tiles.Tile_H, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset , WHITE );
                    break;
                case L'I':
                    DrawText("$",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , DARKPURPLE);
                    //DrawTexture(Level_Tiles.Tile_I, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE );
                    break;

                case L'J':
                    //DrawTexture(Level_Tiles.Tile_J, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    DrawText("*",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , PINK);
                    break;
                case L'K':
                    //DrawTexture(Level_Tiles.Tile_K, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    DrawText("#",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , LIME);
                    break;
                    
                case L'L':
                    DrawText("#",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , GOLD);
                    //BeginShaderMode(Core_Shaders.Water);
                    //DrawTexture(Level_Tiles.Tile_L, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    //EndShaderMode();
                    break;
               case L'M':
                    //BeginShaderMode(Core_Shaders.Water);
                    DrawText("#",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , VIOLET);
                    //DrawTexture(Level_Tiles.Tile_M, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    //EndShaderMode();
                    break;

                case L'N':
                    DrawText("*",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , ORANGE);
                    //DrawTexture(Level_Tiles.Tile_N, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;

                case L'O':
                    DrawText("*",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , MAGENTA);
                    //DrawTexture(Level_Tiles.Tile_O, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;
                case L'P':

                    DrawText("$",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , DARKGREEN);
                    //DrawTexture(Level_Tiles.Tile_P, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;

                case L'1':
                    DrawText("#",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , GREEN);
                    //DrawTexture(Level_Tiles.Tile_1, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;
                case L'2':

                    DrawText("%",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , YELLOW);
                    //DrawTexture(Level_Tiles.Tile_2, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;
                case L'3':
                    DrawText("&",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , WHITE);
                    //DrawTexture(Level_Tiles.Tile_3, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;
                case L'4':
                    DrawText("^",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , BLUE);
                    //DrawTexture(Level_Tiles.Tile_4, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;
                case L'5':
                    DrawText("*",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , BROWN);
                    //DrawTexture(Level_Tiles.Tile_5, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;
                case L'6':
                    DrawText("@",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , WHITE);
                    //DrawTexture(Level_Tiles.Tile_6, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;
                case L'7':
                    DrawText("E",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , WHITE);
                    //DrawTexture(Level_Tiles.Tile_7, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;
                case L'8':
                    DrawText("A",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , WHITE);
                    //DrawTexture(Level_Tiles.Tile_8, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;
                    
                case L'9':
                    DrawText("#",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , WHITE);
                    //DrawTexture(Level_Tiles.Tile_9, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;

                case L'%':
                    DrawText("%",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , PURPLE);
                    //DrawTexture(Level_Tiles.Tile_9, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;

                case L'!':
                    if (MysticPlayerOne.HeartVisable){
                        DrawText("#",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3  - MysticCoreData.Hover_Animation_Ticker / 4, 32 , RED);
                    }
                    //DrawTexture(Level_Tiles.Tile_9, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;

                case L'Q':
                    if (MysticCoreData.BreakTimer >= 50) {
                        DrawText("#",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, 20 , DARKGRAY);
                    }
                    else {
                        BeginShaderMode(Core_Shaders.Water);
                        DrawText("#",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, 20 , DARKGRAY);
                        EndShaderMode();

                    }
                    //DrawTexture(Level_Tiles.Tile_9, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;

                case L'R':
                    if (MysticCoreData.BreakTimer >= 50) {
                        DrawText("%",  x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset - 3, 32 , GOLD);
                    }
                    //DrawTexture(Level_Tiles.Tile_9, x * 20 - MysticCamera.XOffset,  y * 20 + MysticCamera.YOffset, WHITE);
                    break;
                



            }
            EndShaderMode();
            

        
        }

        
    }

    if (MysticCamera.XOffset <= 0){

        MysticCamera.XOffset = 0;
        MysticCamera.Background_Parrallax_X_1 = 0;
        MysticCamera.Background_Parrallax_X_2 = 120;
        MysticCamera.Background_Parrallax_X_3 = 240;

    }


    if (MysticCamera.XOffset >= Level_Width *20 - 640){
        MysticCamera.XOffset = Level_Width *20 - 640;
    }

    if (MysticPlayerOne.x >= 25 ){
        MysticPlayerOne.x -= 5 + MysticPlayerOne.acceloration / 5;
        MysticCamera.XOffset += 6 + MysticPlayerOne.acceloration / 5;
    }

    if (MysticPlayerOne.x <= 280 ){
        MysticPlayerOne.x += 5;
        MysticCamera.XOffset -= 6 + MysticPlayerOne.acceloration / 5;

    }

}




