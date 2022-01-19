/* Code By Liquid 2021 */

/* Code Improved By Liquid 2022 */


/*- Backstory -

        This Game Started as A Dumb Idea We had on Discord One day. A Member of the team had been working on a Platformer Engine Known as MysticEngine. Liquid 
    Took that Engine and Modded it to Use Only Text Characters. We Submitted the Game to the 4MB Game Jam on itch.io and Placed 8th. This Game Had No Budget and was
    all Completed on Spare Time. 
    

    Special Thanks to The Developers of Raylib. Raylib Helped make this game A Reality, Before We Had Developed a Whole Framework On Top of SDL2 that was very 
    Buggy and Slow. Then We swapped that out with Raylib 3.5 and It Worked Flawlessy. 
    
    
    - Credits -


    ~ Lead Engine Development

        Liquid

    ~ Music 

        Liquid

    ~ Gameplay Testing 

        PPG Development Team / MysticEngine Team 

    ~ Idea

        Liquid

        PPG Development Team / MysticEngine Team 

    ~ Level Design

        Liquid 

        PPG Development Team / MysticEngine Team 

*/


/*

  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM 
 MMMMMMMWNXXKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKXXNWMMMMMMM 
MMMMMMMWXOxolllllllllllllllllllllllllllllllllllllllllllllllllllllllloxOXWMMMMMMM
MMMMMWNKOd:,........................................................,:dOKNWMMMMM
MMWNX0kdl:'..........................................................':ldk0XNWMM
MMNKko:,'..............................................................',:okKNMM
MWN0d:'..................................................................':d0NWM
MWN0d:'..................................................................':d0NWM
MWN0d:'..................................................................':d0NWM
MWN0d:'.................,;ccllllllllllllllllllllllllcc;,.................':d0NWM
MWN0d:'................,cxOKKKKKKKKKKKKKKKKKKKKKKKKKKOxc,................':d0NWM
MWN0d:'..............,:ok0NWWNXKKKKKKKKKKKKKKKKKKXNWWN0ko:,..............':d0NWM
MWN0d:'...........';ldk0XNWNX0kdollllllllllllllodk0XNWNX0kdl;'...........':d0NWM
MWN0d:'...........;okKNWWWNKOd:,................,:dOKNWWWNKko;...........':d0NWM
MWN0d:'...........:d0XWNX0kdl:'..................':ldk0XNWX0d:...........':d0NWM
MWN0d:'...........:d0XNKko:,'......................',:okKNX0d:...........':d0NWM
MWN0d:'...........:d0XX0d:'........',,,;;,,,'........':d0XX0d:...........':d0NWM
MWN0d:'...........:d0XX0d:'......,:ldxkkkkxdl:,......':d0XX0d:...........':d0NWM
MWN0d:'...........:d0XX0d:'......;okKNWWWWNKko;......':d0XX0d:...........':d0NWM
MWN0d:'...........:d0XX0d:'.....':d0NWMMMMWN0d:'.....':d0XX0d:...........':d0NWM
MWN0d:'...........:d0XX0d:'.....':dOXWMMMMWXOd:'.....':d0XX0d:...........':d0NWM
MWN0d:'...........:d0XX0d:'......;lxOKXXXXKOxl;.......;lxOOxl;...........':d0NWM
MWN0d:'...........:d0XX0d:'.......,:cllllllc:,........',:cc:,'...........':d0NWM
MWN0d:'...........:d0XX0xc,..............................................':d0NWM
MWN0d:'...........:d0XNX0koc;,...........................................':d0NWM
MWN0d:'...........;oOXWWWNKOxl;..........................................':d0NWM
MWN0d:'...........,cdOKNWWWNKko:;,,,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,,;:okKNMM
MWN0d:'............';cox0XWWNX0OkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkO0XNWMM
MWN0d:'...............':oOKNNNNXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXNWWMMM
MWN0d:'................';ldxkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkO0XNWMM
MWN0d:'..................'',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,;:okKNMM
MWN0d:'..................................................................':d0NWM
MWN0d:'..................................................................':d0NWM
MMN0xc,..................................................................,cx0NWM
MMWX0xoc;,............................................................,;cox0XWMM
MMMWNNKOxl;..........................................................;lxOKNNWMMM
MMMMMMWNKko:;,,,,,,;;;;,,,,,,;;;,,,,,,,,,,,,,,,,,,,,,,,,,;;;;,,,,,,;:okKNWMMMMMM
MMMMMMMWNK0OkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkO0KNWMMMMMMM
 MMMMMMMMWWWNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWWMMMMMMMM
   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM  


                       ~ Wisp Team 2021 ~

*/
#include "MysticEngineCoreData.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main (void){


    InitWindow(640 , 500 , "WispHD");
    SetTargetFPS(60);

    SetWindowIcon(LoadImage("GameAssets/Icon/icon.png"));  

    Texture2D SplashScreen = LoadTexture("GameAssets/SplashScreen/ppg.png");

    Music PPGSplash = LoadMusicStream("GameAssets/SplashScreen/PPGopen.mp3");

    if (LoadMconfFile("GameAssets/MainConf/Window.mconf") == L'0'){
        SetWindowState(FLAG_WINDOW_UNDECORATED);
    }

    if (LoadMconfFile("GameAssets/MainConf/Full_Screen.mconf") == L'1'){
        ToggleFullscreen();
    }

    if (LoadMconfFile("GameAssets/MainConf/Sound.mconf") == L'1'){
        InitAudioDevice();
    }

    if (LoadMconfFile("GameAssets/Saves/SAV_0.msave") == L'1'){
        BonusLevelsEnabled = true;
    }

    PlayMusicStream(PPGSplash);

    while (Splash && !WindowShouldClose()){

        BeginDrawing();

        UpdateControls();
        UpdateMusicStream(PPGSplash);

        ClearBackground(WHITE);

        DrawTexture(SplashScreen , 0 , 0 , SplashColor);

        if (R >= 255 && ColorCounter == 0){
            ColorCounter = 1;
        }

        if (ColorCounter == 0){
            R += 1;
            G += 1;
            B += 1;
        }

        else{
            R -= 1;
            G -= 1;
            B -= 1;
        }

        if (SplashCounter != 500){
            SplashCounter ++;
        }
        else {
            Splash = false;
            StopMusicStream(PPGSplash);
        }

        EndDrawing();
    }


    MysticInit();

    MysticMusicInit();

    InitLevelData();

    ResetLevel(Level1Data);
    ScanForSpawnTiles(Level1Data);
    ScanForEnemyTiles(Level1Data);

    PlayMusicStream(MysticCoreData.TitleMusic);


    while (!WindowShouldClose()){ 

        BeginDrawing();

        ClearBackground(BLACK);

        if (MysticCoreData.LevelID == 0){

            if (Start){
                MysticDrawLevel(Level1Data.Data,Level1Data.LevelWidth, Level1Data.LevelHeight,  Level1Data.ShaderBlock1 , Level1Data.ShaderBlock2 , Level1Data.ShaderBlock3 , Level1Data.ShaderBlock4);
                MysticCamera.XOffset ++;

                if (MysticCamera.XOffset >= 1280){
                    MysticCamera.XOffset = 0;
                }
                switch (TextCounter)
                {
                    case 1:
                        DrawText(TextSubtext("There Has Been Something Strange Going on.", 0, FrameCounter/5), 640 / 2 - MeasureText(TextSubtext("There Has Been Something Strange Going on.", 0, FrameCounter/5) , 20) / 2 , 200 , 20 , WHITE);
                        break;
                    case 2:
                        DrawText(TextSubtext("People Have Been Acting Violent.", 0, FrameCounter/5), 640 / 2 - MeasureText(TextSubtext("People Have Been Acting Violent.", 0, FrameCounter/5) , 20) / 2 , 200 , 20 , WHITE);
                        break;
                    case 3:
                        DrawText(TextSubtext("There's a Gold Cave to the West Shining.", 0, FrameCounter/5), 640 / 2 - MeasureText(TextSubtext("There's a Gold Cave to the West Shining.", 0, FrameCounter/5) , 20) / 2 , 200 , 20 , WHITE);
                        
                        break;
                    case 4:
                        DrawText(TextSubtext("Better Go Investigate.", 0, FrameCounter/5), 640 / 2 - MeasureText(TextSubtext("Better Go Investigate.", 0, FrameCounter/5) , 20) / 2 , 200 , 20 , WHITE);
                        break;
                    
                    default:
                        break;
                }

                if (MysticCoreData.AnimationTicker <= 50){
                    DrawText("Space" , 640 / 2 - MeasureText("Space" , 20) / 2 , 400 , 20 , WHITE);
                }
                if (MysticControls.Shoot){
                    if (TextCounter == 4){
                        Start = false;
                        TextCounter = 1;
                        FrameCounter = 0;
                    }
                    TextCounter ++;
                    FrameCounter = 0;
                }
                FrameCounter++;

            }
            else {

                if (!Help && !MysticCoreData.BonusMenu){

                    UpdateMusicStream(MysticCoreData.TitleMusic);
                    MysticDrawLevel(Level1Data.Data,Level1Data.LevelWidth, Level1Data.LevelHeight,  Level1Data.ShaderBlock1 , Level1Data.ShaderBlock2 , Level1Data.ShaderBlock3 , Level1Data.ShaderBlock4);
                    
                    DrawText(TextSubtext("Wi",0,TextAnimationValue / 20), 288 - HomeScreenScroller  , 200 + HomeScreenScroller , 32 + HomeScreenScroller / 4 , WHITE);
                    DrawText(TextSubtext("sp",0,TextAnimationValue / 20), 320 - HomeScreenScroller + HomeScreenScroller / 4 , 200 + HomeScreenScroller  , 32 + HomeScreenScroller / 4  , BLUE);
                    
                    if (!IsGamepadAvailable(0)){
                        if (MysticCoreData.AnimationTicker >= 50) DrawText(TextSubtext("Press Space",0,TextAnimationValue / 2), 270 - HomeScreenScroller  , 300 + HomeScreenScroller , 16 + HomeScreenScroller / 8 , WHITE);
                    }
                    else {
                        if (MysticCoreData.AnimationTicker >= 50) DrawText(TextSubtext("Press RT",0,TextAnimationValue / 2), (640/2 - MeasureText("Press RT" , 16)/2) - HomeScreenScroller  , 300 + HomeScreenScroller , 16 + HomeScreenScroller / 8 , WHITE);
                    }

                    MysticCamera.XOffset ++;
                    if (MysticCamera.XOffset >= 1280){
                        MysticCamera.XOffset = 0;
                    }
                    if (TextAnimationValue <= 40){
                        TextAnimationValue ++;
                    }
                    if (MysticControls.Shoot){

                        HomeScreenScroller = 2;
                    }

                    if (!BonusLevelsEnabled){

                        DrawText("Story" , 20  - HomeScreenScroller + HomeScreenScroller / 4 , 450  + HomeScreenScroller , 20 + HomeScreenScroller / 4 , WHITE);

                        if (GetCollision(20 , 450 , 50 , 20 , MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5, 5 ) && MysticGetVirtualMouseClick(MOUSE_LEFT_BUTTON)){
                            Start = true;
                        }

                    }
                    else{
                        DrawText("Bonus" , 20  - HomeScreenScroller + HomeScreenScroller / 4 , 450  + HomeScreenScroller , 20 + HomeScreenScroller / 4 , WHITE);
                        if (GetCollision(20 , 450 , 50 , 20 , MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5, 5 ) && MysticGetVirtualMouseClick(MOUSE_LEFT_BUTTON)){
                            MysticCoreData.BonusMenu = true;
                        }
                    }

                    DrawText("Help" , 570  - HomeScreenScroller + HomeScreenScroller / 4, 450  + HomeScreenScroller  , 20 + HomeScreenScroller / 4 , WHITE);

                    if (GetCollision(570 , 450 , 50 , 20 , MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5, 5 ) && MysticGetVirtualMouseClick(MOUSE_LEFT_BUTTON)){
                        Help = true;
                    }

                    if (HomeScreenScroller >= 1 && HomeScreenScroller <= 60){
                        rlViewport(0, 0 ,640 + HomeScreenScroller * 2 ,500 + HomeScreenScroller * 2);
                        HomeScreenScroller ++;
                    }
                    else{
                        if (HomeScreenScroller != 0){
                            rlViewport(0,0,640,500);
                            MysticCoreData.LevelID = 1;
                            MysticCamera.XOffset = 0;
                            StopMusicStream(MysticCoreData.TitleMusic);
                            PlayMusicStream(MysticCoreData.GameMusic2);
                        }
                    }

                }
                if (Help){
                    MysticDrawLevel(Level1Data.Data,Level1Data.LevelWidth, Level1Data.LevelHeight,  Level1Data.ShaderBlock1 , Level1Data.ShaderBlock2 , Level1Data.ShaderBlock3 , Level1Data.ShaderBlock4);
                    
                    MysticCamera.XOffset ++;
                    if (MysticCamera.XOffset >= 1280){
                        MysticCamera.XOffset = 0;
                    }

                    DrawText("Back" , 20 , 20 , 20 , WHITE);

                    if (GetCollision(20 , 20 , 50 , 20 , MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5, 5 ) && MysticGetVirtualMouseClick(MOUSE_LEFT_BUTTON)){
                        Help = false;
                    }

                    DrawText("Controls" , 80 , 100 , 25 , WHITE);

                    DrawText("Jump : Up Arrow Key" , 100 , 200 , 20 , WHITE);
                    DrawText("Right : Right Arrow Key" , 100 , 230 , 20 , WHITE);
                    DrawText("Left : Left Arrow Key" , 100 , 250 , 20 , WHITE);
                    DrawText("Shoot ( Normal Weapon ) : Space Key" , 100 , 270 , 20 , WHITE);
                    DrawText("Shoot ( Boss Weapon ) : Left Click" , 100 , 290 , 20 , WHITE);

                }
                if (MysticCoreData.BonusMenu && !MysticCoreData.LevelEditor ){

                    MysticDrawLevel(Level15Data.Data,Level15Data.LevelWidth, Level15Data.LevelHeight,  Level15Data.ShaderBlock1 , Level15Data.ShaderBlock2 , Level15Data.ShaderBlock3 , Level15Data.ShaderBlock4);

                    MysticCamera.XOffset ++;
                    if (MysticCamera.XOffset >= 640*2){
                        MysticCamera.XOffset = 0;
                    }
                
                    if (!IsGamepadAvailable(0)){
                        DrawText("- >" , (600)  , 20, 20, PURPLE );

                        if (GetCollision(600 , 20 , 20 , 20 , MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5 , 5) && MysticGetVirtualMouseClick(MOUSE_LEFT_BUTTON)){
                            MysticCoreData.LevelEditor = true;
                            MysticCamera.XOffset = 0;
                        }
                    }

                    DrawText("< -" , (20)  , 20, 20, PURPLE );

                    if (GetCollision(20 , 20 , 20 , 20 , MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5 , 5) && MysticGetVirtualMouseClick(MOUSE_LEFT_BUTTON)){
                        MysticCoreData.BonusMenu = false;
                    }

                    DrawRectangleLines(50 , 90 + BonusScroll , 540 , 40 , WHITE );

                    DrawText("Bonus Level ( Custom ): Custom" , 60 , 100 + BonusScroll , 20 , BLUE);

                    DrawText("   You   " , (540 - 5*20) - 10 , 100 + BonusScroll , 20 , BLUE);

                    if (GetCollision(50 , 90 + BonusScroll , 590 , 40, MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5 , 5)){

                        DrawRectangleLines(50 , 90 + BonusScroll , 540 , 40 , RED );

                        if (MysticGetVirtualMouseClick(0)){
                            CustomTransition(2 , 41, LevelCustomData);
                        }

                    }

                    DrawRectangleLines(50 , 60+ 90 + BonusScroll , 540 , 40 , WHITE );

                    DrawText("Bonus Level 1: F_Fortess" , 60 ,60 + 100 + BonusScroll , 20 , BLUE);

                    DrawText("   Ewan Cole   " , (540 - 5*20) - 10 , 60 + 100 + BonusScroll , 20 , BLUE);

                    if (GetCollision(50 , 60 + 90 + BonusScroll , 540 , 40, MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5 , 5)){

                        DrawRectangleLines(50 , 60 + 90 + BonusScroll , 540 , 40 , RED );

                        if (MysticGetVirtualMouseClick(0)){
                            CustomTransition(2 , 31 , BonusData1);
                        }

                    }

                    BonusScroll -= (GetMouseWheelMove()*3);
                    
                }

                if (MysticCoreData.LevelEditor){

                    MysticDrawLevel(LevelCustomData.Data,LevelCustomData.LevelWidth, LevelCustomData.LevelHeight,  LevelCustomData.ShaderBlock1 , LevelCustomData.ShaderBlock2 , LevelCustomData.ShaderBlock3 , LevelCustomData.ShaderBlock4);
                    
                    if (MysticControls.Left){
                        MysticCamera.XOffset -= LevelEditorXOffset;
                    }

                    if (MysticControls.Right){
                        MysticCamera.XOffset += LevelEditorXOffset;
                    }

                    if (IsKeyPressed(KEY_X)){
                        if (LevelEditorXOffset != 12 )LevelEditorXOffset ++;
                    }
                    if (IsKeyPressed(KEY_Z)){
                        if (LevelEditorXOffset != 1 )LevelEditorXOffset --;
                        
                    }

                    if (MysticGetVirtualMouseClick(MOUSE_LEFT_BUTTON) && MysticGetVirtualMouseX() <= 490 && !GetCollision(20 , 20 , 20 , 20 , MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5 , 5)){
                        LevelCustomData.Data[MysticGetVirtualMouseY() / 20 * Level1Data.LevelWidth + MysticGetVirtualMouseX() / 20 + MysticCamera.XOffset / 20 ] = CurrrentSelectedTile;
                    }

                    DrawRectangle(640 - 150, 0 ,150 ,500 ,SPRO2);

                    for (int x = 0 ; x < 2; x++ ){
                        for (int y = 0 ; y <= 15; y++ ){
                            DrawRectangle(495 + (x*75), 5 + (y*75) + Scroller, 65 , 65 ,SPRO);
                            if (GetCollision(495 + (x*75), 5 + (y*75) + Scroller, 50 ,50 , MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5 , 5)){
                                DrawRectangleLines(495 + (x*75), 5 + (y*75)  + Scroller, 65 , 65 ,WHITE);
                            }
                            if (GetCollision(495 + (x*75), 5 + (y*75) + Scroller, 50 ,50 , MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5 , 5) && MysticGetVirtualMouseClick(MOUSE_LEFT_BUTTON)){
                                DrawRectangleLines(495 + (x*75), 5 + (y*75)  + Scroller, 65 , 65 ,RED);

                                switch (y)
                                {
                                    case 0:
                                        if (x == 0)CurrrentSelectedTile = L'1';
                                        if (x == 1)CurrrentSelectedTile = L'5';
                                        break;
                                    case 1:
                                        if (x == 0)CurrrentSelectedTile = L'4';
                                        if (x == 1)CurrrentSelectedTile = L'E';    
                                        break;
                                    case 2:
                                        if (x == 0)CurrrentSelectedTile = L'A';
                                        if (x == 1)CurrrentSelectedTile = L'B';    
                                        break;
                                    case 3:
                                        if (x == 0)CurrrentSelectedTile = L'C';
                                        if (x == 1)CurrrentSelectedTile = L'D';    
                                        break;
                                    case 4:
                                        if (x == 0)CurrrentSelectedTile = L'G';
                                        if (x == 1)CurrrentSelectedTile = L'H';    
                                        break;
                                    case 5:
                                        if (x == 0)CurrrentSelectedTile = L'M';
                                        if (x == 1)CurrrentSelectedTile = L'I';    
                                        break;
                                    case 6:
                                        if (x == 0)CurrrentSelectedTile = L'2';
                                        if (x == 1)CurrrentSelectedTile = L'3';    
                                        break;
                                    case 7:
                                        if (x == 0)CurrrentSelectedTile = L'6';
                                        if (x == 1)CurrrentSelectedTile = L'7';    
                                        break;
                                    case 8:
                                        if (x == 0)CurrrentSelectedTile = L'8';
                                        if (x == 1)CurrrentSelectedTile = L'9';    
                                        break;
                                    case 9:
                                        if (x == 0)CurrrentSelectedTile = L'F';
                                        if (x == 1)CurrrentSelectedTile = L'J';    
                                        break;
                                    case 10:
                                        if (x == 0)CurrrentSelectedTile = L'K';
                                        if (x == 1)CurrrentSelectedTile = L'L';    
                                        break;
                                    case 11:
                                        if (x == 0)CurrrentSelectedTile = L'N';
                                        if (x == 1)CurrrentSelectedTile = L'O';    
                                        break;
                                    case 12:
                                        if (x == 0)CurrrentSelectedTile = L'P';
                                        if (x == 1)CurrrentSelectedTile = L'0'; 
                                        break;

                                    case 13:
                                        if (x == 0)CurrrentSelectedTile = L'Z';
                                        if (x == 1)CurrrentSelectedTile = L'%'; 
                                        break;
                                    case 14:
                                        if (x == 0)CurrrentSelectedTile = L'+';
                                        if (x == 1)CurrrentSelectedTile = L'&'; 
                                        break;
                                    case 15:
                                        if (x == 0)CurrrentSelectedTile = L'^';
                                        if (x == 1)CurrrentSelectedTile = L'!'; 
                                        break;
                                    default:
                                        
                                        break;
                                }
                            }

                            
                        }
                    }

                    DrawText("#" , 495 + 16 , 5 + 10 + Scroller , 50 , GREEN);

                    DrawText("*" , 495 + 75 + 16 , 5 + 10 + Scroller, 50 , BROWN);

                    DrawText("^" , 495  + 16 , 5 + 10 + 75+ Scroller , 50 , BLUE);

                    DrawText("^" , 495 + 75 + 16 , 5 + 10 + 75+ Scroller , 50 , ORANGE);

                    DrawText("#" , 495  + 16 , 5 + 10 + 75  * 2 + Scroller, 50 , GRAY);

                    DrawText("#" , 495 + 75 + 16 , 5 + 10 + 75 * 2 + Scroller, 50 ,DARKGRAY);

                    DrawText("@" , 495  + 16 , 5 + 10 + 75  * 3 + Scroller, 50 , GRAY);

                    DrawText("@" , 495 + 75 + 16 , 5 + 10 + 75 * 3 + Scroller, 50 ,DARKGRAY);

                    DrawText("*" , 495  + 16 , 5 + 10 + 75  * 4 + Scroller, 50 , DARKBROWN);

                    DrawText("$" , 495 + 75 + 16 , 5 + 10 + 75 * 4 + Scroller, 50 , SKYBLUE);

                    DrawText("#" , 495  + 16 , 5 + 10 + 75  * 5+ Scroller, 50 , VIOLET);

                    DrawText("$" , 495 + 75 + 16 , 5 + 10 + 75 * 5 + Scroller, 50 , DARKPURPLE);

                    DrawText("%" , 495  + 16 , 5 + 10 + 75  * 6+ Scroller, 50 , YELLOW);

                    DrawText("&" , 495 + 75 + 16 , 5 + 10 + 75 * 6+ Scroller, 50 , WHITE);

                    DrawText("@" , 495  + 16 , 5 + 10 + 75  * 7+ Scroller, 50 , WHITE);

                    DrawText("E" , 495 + 75 + 16 , 5 + 10 + 75 * 7 + Scroller, 50 , WHITE);
                    
                    DrawText("A" , 495  + 16 , 5 + 10 + 75  * 8+ Scroller, 50 , WHITE);

                    DrawText("#" , 495 + 75 + 16 , 5 + 10 + 75 * 8 + Scroller, 50 , WHITE);

                    DrawText("#" , 495  + 16 , 5 + 10 + 75  * 9+ Scroller, 50 , BLUE);

                    DrawText("*" , 495 + 75 + 16 , 5 + 10 + 75 * 9 + Scroller, 50 , PINK);

                    DrawText("#" , 495  + 16 , 5 + 10 + 75  * 10+ Scroller, 50 , LIME);

                    DrawText("#" , 495 + 75 + 16 , 5 + 10 + 75 * 10 + Scroller, 50 , GOLD);

                    DrawText("*" , 495  + 16 , 5 + 10 + 75  * 11+ Scroller, 50 , ORANGE);

                    DrawText("*" , 495 + 75 + 16 , 5 + 10 + 75 * 11 + Scroller, 50 , MAGENTA);

                    DrawText("$" , 495  + 16 , 5 + 10 + 75  * 12+ Scroller, 50 , DARKGREEN);

                    DrawText("Delete" , 495 + 75 + 10  , 5 + 20 + 75 * 12 + Scroller, 15 , RED);

                    DrawText("Colli." , 495  + 16 , 5 + 20 + 75  * 13+ Scroller, 15 , RED);

                    DrawText("Trans." , 495 + 75 + 10  , 5 + 20 + 75 * 13 + Scroller, 15 , PINK);


                    DrawText("Plyr Spwn." , 495  + 16 - 8, 5 + 20 + 75  * 14+ Scroller, 10 , BLUE);

                    DrawText("Enmy Spwn." , 495 + 75 + 10 -4 , 5 + 20 + 75 * 14 + Scroller, 10 , RED);

                    DrawText("Plyr Wpon." , 495  + 16 - 8, 5 + 20 + 75  * 15+ Scroller, 10 , RED);

                    DrawText("Plyr Hlth." , 495 + 75 + 10 -4 , 5 + 20 + 75 * 15 + Scroller, 10 , RED);


                    DrawLine(490 , 350 , 640 , 350 , WHITE);
                    DrawRectangle(490 , 350, 150 , 150,DARKGRAY);

                    DrawRectangleLines(490 , 350, 150 , 150 , GRAY);

                    DrawRectangle(495 + (0*75), 10 + (4.6*75) , 140 , 65 ,GRAY);

                    DrawRectangle(495 + (0*75), 10 + (345+75) , 140 , 65 ,GRAY);

                    DrawText("Save",495 + (0*75) + 25 , 10 + (345+13), 35 , WHITE);

                    DrawText("Export",495 + (0*75 +10) , 10 + (345+88), 35 , WHITE);

                    if (GetCollision(495 + (0*75), 10 + (4.6*75) , 140 , 65 , MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5 , 5) && MysticGetVirtualMouseClick(MOUSE_LEFT_BUTTON)){
                        DrawRectangleLines(495 + (0*75), 10 + (4.6*75) , 140 , 65, RED);
                        wofstream outfile;
                        outfile.open("LevelData/LevelCustom/Level_Custom.mpak");
                        outfile << LevelCustomData.Data << "\n";
                        SaveMessageCounter = 120;
                    }

                    if (GetCollision(495 + (0*75), 10 + (4.6*75) , 140 , 65 , MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5 , 5)){
                        DrawRectangleLines(495 + (0*75), 10 + (4.6*75) , 140 , 65, WHITE);
                    }

                    if (GetCollision(495 + (0*75), 10 + (345+75), 140 , 65 , MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5 , 5) && MysticGetVirtualMouseClick(MOUSE_LEFT_BUTTON)){
                        
                        DrawRectangleLines(495 + (0*75), 10 + (345+75), 140 , 65, RED);

                        wofstream outfile;

                        #if (defined(LINUX_BUILD))
                            system("mkdir Export ; cd Export ; echo '' >> Level_Custom.mpak");
                            system("cp -r LevelData/LevelCustom/ProgrammableComponents Export");

                            outfile.open("Export/LevelCustom.mpak");
                            outfile << LevelCustomData.Data << "\n";

                        #endif

                        #if (defined(WINDOWS_BUILD))
                            remove("Export");
                            system("mkdir Export");

                            outfile.open("Export/Level_Custom.mpak");
                            outfile << LevelCustomData.Data << "\n";

                        #endif

                        ExportMessageCounter = 120;

                    }
                    if (GetCollision(495 + (0*75), 10 + (345+75) , 140 , 65 , MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5 , 5)){
                        DrawRectangleLines(495 + (0*75), 10 + (345+75), 140 , 65, WHITE);
                    }

                    if (ExportMessageCounter != 0){
                        ExportMessageCounter --;
                        DrawText("Level Exported to ( Export/LevelCustom.mpak ) ", 640 / 2 - (48 * 20 / 4) , 200 , 20 , WHITE );
                    }

                    if (SaveMessageCounter != 0){
                        SaveMessageCounter --;
                        DrawText("                    Saved                      ", 640 / 2 - (48 * 20 / 4) , 200 , 20 , WHITE );
                    }

                    Scroller -= (GetMouseWheelMove()*2);

                    if (IsKeyDown(KEY_DOWN)){
                        Scroller -= 4;
                    }

                    if (MysticControls.Up){
                        Scroller += 4;
                    }




                    DrawText("< -" , (20)  , 20, 20, PURPLE );

                    if (GetCollision(20 , 20 , 20 , 20 , MysticGetVirtualMouseX() , MysticGetVirtualMouseY() , 5 , 5) && MysticGetVirtualMouseClick(MOUSE_LEFT_BUTTON)){
                        MysticCoreData.LevelEditor = false;
                    }

            

                }
            }
                
        }

        if (MysticBoss.Alive){

            switch (MysticCoreData.LevelID){

                case 1:
                    MysticDrawLevel(Level1Data.Data,Level1Data.LevelWidth, Level1Data.LevelHeight,  Level1Data.ShaderBlock1 , Level1Data.ShaderBlock2 , Level1Data.ShaderBlock3 , Level1Data.ShaderBlock4);
                    break;
                case 2:
                    MysticDrawLevel(Level2Data.Data,Level2Data.LevelWidth, Level2Data.LevelHeight,  Level2Data.ShaderBlock1 , Level2Data.ShaderBlock2 , Level2Data.ShaderBlock3 , Level2Data.ShaderBlock4);
                    break;
                case 3:
                    MysticDrawLevel(Level3Data.Data,Level3Data.LevelWidth, Level3Data.LevelHeight,  Level3Data.ShaderBlock1 , Level3Data.ShaderBlock2 , Level3Data.ShaderBlock3 , Level3Data.ShaderBlock4);
                    break;
                case 4:
                    MysticDrawLevel(Level4Data.Data,Level4Data.LevelWidth, Level4Data.LevelHeight,  Level4Data.ShaderBlock1 , Level4Data.ShaderBlock2 , Level4Data.ShaderBlock3 , Level4Data.ShaderBlock4);
                    break;
                case 5:
                    MysticDrawLevel(Level5Data.Data,Level5Data.LevelWidth, Level5Data.LevelHeight,  Level5Data.ShaderBlock1 , Level5Data.ShaderBlock2 , Level5Data.ShaderBlock3 , Level5Data.ShaderBlock4);
                    break;
                case 6:
                    MysticDrawLevel(Level6Data.Data,Level6Data.LevelWidth, Level6Data.LevelHeight,  Level6Data.ShaderBlock1 , Level6Data.ShaderBlock2 , Level6Data.ShaderBlock3 , Level6Data.ShaderBlock4);
                    break;
                case 7:
                    MysticDrawLevel(Level7Data.Data,Level7Data.LevelWidth, Level7Data.LevelHeight,  Level7Data.ShaderBlock1 , Level7Data.ShaderBlock2 , Level7Data.ShaderBlock3 , Level7Data.ShaderBlock4);
                    break;
                case 8:
                    MysticDrawLevel(Level8Data.Data,Level8Data.LevelWidth, Level8Data.LevelHeight,  Level8Data.ShaderBlock1 , Level8Data.ShaderBlock2 , Level8Data.ShaderBlock3 , Level8Data.ShaderBlock4);
                    break;
                case 9:
                    MysticDrawLevel(Level9Data.Data,Level9Data.LevelWidth, Level9Data.LevelHeight,  Level9Data.ShaderBlock1 , Level9Data.ShaderBlock2 , Level9Data.ShaderBlock3 , Level9Data.ShaderBlock4);
                    break;
                case 10:
                    MysticDrawLevel(Level10Data.Data,Level10Data.LevelWidth, Level10Data.LevelHeight,  Level10Data.ShaderBlock1 , Level10Data.ShaderBlock2 , Level10Data.ShaderBlock3 , Level10Data.ShaderBlock4);
                    break;
                case 11:
                    MysticDrawLevel(Level11Data.Data,Level11Data.LevelWidth, Level11Data.LevelHeight,  Level11Data.ShaderBlock1 , Level11Data.ShaderBlock2 , Level11Data.ShaderBlock3 , Level11Data.ShaderBlock4);
                    break;
                case 12:
                    MysticDrawLevel(Level12Data.Data,Level12Data.LevelWidth, Level12Data.LevelHeight,  Level12Data.ShaderBlock1 , Level12Data.ShaderBlock2 , Level12Data.ShaderBlock3 , Level12Data.ShaderBlock4);
                    break;
                case 13:
                    MysticDrawLevel(Level13Data.Data,Level13Data.LevelWidth, Level13Data.LevelHeight,  Level13Data.ShaderBlock1 , Level13Data.ShaderBlock2 , Level13Data.ShaderBlock3 , Level13Data.ShaderBlock4);
                    break;
                case 14:
                    MysticDrawLevel(Level14Data.Data,Level14Data.LevelWidth, Level14Data.LevelHeight,  Level14Data.ShaderBlock1 , Level14Data.ShaderBlock2 , Level14Data.ShaderBlock3 , Level14Data.ShaderBlock4);
                    break;
                case 15:
                    MysticDrawLevel(Level15Data.Data,Level15Data.LevelWidth, Level15Data.LevelHeight,  Level15Data.ShaderBlock1 , Level15Data.ShaderBlock2 , Level15Data.ShaderBlock3 , Level15Data.ShaderBlock4);
                    break;
                case 16:
                    MysticDrawLevel(Level16Data.Data,Level16Data.LevelWidth, Level16Data.LevelHeight,  Level16Data.ShaderBlock1 , Level16Data.ShaderBlock2 , Level16Data.ShaderBlock3 , Level16Data.ShaderBlock4);
                    break;
                case 17:
                    MysticDrawLevel(Level17Data.Data,Level17Data.LevelWidth, Level17Data.LevelHeight,  Level17Data.ShaderBlock1 , Level17Data.ShaderBlock2 , Level17Data.ShaderBlock3 , Level17Data.ShaderBlock4);
                    break;
                case 18:
                    MysticDrawLevel(Level18Data.Data,Level18Data.LevelWidth, Level18Data.LevelHeight,  Level18Data.ShaderBlock1 , Level18Data.ShaderBlock2 , Level18Data.ShaderBlock3 , Level18Data.ShaderBlock4);
                    break;
                case 19:
                    MysticDrawLevel(Level19Data.Data,Level19Data.LevelWidth, Level19Data.LevelHeight,  Level19Data.ShaderBlock1 , Level19Data.ShaderBlock2 , Level19Data.ShaderBlock3 , Level19Data.ShaderBlock4);
                    break;
                case 20:
                    MysticDrawLevel(Level20Data.Data,Level20Data.LevelWidth, Level20Data.LevelHeight,  Level20Data.ShaderBlock1 , Level20Data.ShaderBlock2 , Level20Data.ShaderBlock3 , Level20Data.ShaderBlock4);
                    break;
                case 21:
                    MysticDrawLevel(Level21Data.Data,Level21Data.LevelWidth, Level21Data.LevelHeight,  Level21Data.ShaderBlock1 , Level21Data.ShaderBlock2 , Level21Data.ShaderBlock3 , Level21Data.ShaderBlock4);
                    break;
                case 22:
                    MysticDrawLevel(Level22Data.Data,Level22Data.LevelWidth, Level22Data.LevelHeight,  Level22Data.ShaderBlock1 , Level22Data.ShaderBlock2 , Level22Data.ShaderBlock3 , Level22Data.ShaderBlock4);
                    break;
                case 23:
                    MysticDrawLevel(Level23Data.Data,Level23Data.LevelWidth, Level23Data.LevelHeight,  Level23Data.ShaderBlock1 , Level23Data.ShaderBlock2 , Level23Data.ShaderBlock3 , Level23Data.ShaderBlock4);
                    break;
                case 24:
                    MysticDrawLevel(Level24Data.Data,Level24Data.LevelWidth, Level24Data.LevelHeight,  Level24Data.ShaderBlock1 , Level24Data.ShaderBlock2 , Level24Data.ShaderBlock3 , Level24Data.ShaderBlock4);
                    break;
                case 25:
                    MysticDrawLevel(Level25Data.Data,Level25Data.LevelWidth, Level25Data.LevelHeight,  Level25Data.ShaderBlock1 , Level25Data.ShaderBlock2 , Level25Data.ShaderBlock3 , Level25Data.ShaderBlock4);
                    break;
                case 26:
                    MysticDrawLevel(Level26Data.Data,Level26Data.LevelWidth, Level26Data.LevelHeight,  Level26Data.ShaderBlock1 , Level26Data.ShaderBlock2 , Level26Data.ShaderBlock3 , Level26Data.ShaderBlock4);
                    break;
                case 27:
                    MysticDrawLevel(Level27Data.Data,Level27Data.LevelWidth, Level27Data.LevelHeight,  Level27Data.ShaderBlock1 , Level27Data.ShaderBlock2 , Level27Data.ShaderBlock3 , Level27Data.ShaderBlock4);
                    break;
                case 28:
                    MysticDrawLevel(Level28Data.Data,Level28Data.LevelWidth, Level28Data.LevelHeight,  Level28Data.ShaderBlock1 , Level28Data.ShaderBlock2 , Level28Data.ShaderBlock3 , Level28Data.ShaderBlock4);
                    break;
                case 29:
                    MysticDrawLevel(Level29Data.Data,Level29Data.LevelWidth, Level29Data.LevelHeight,  Level29Data.ShaderBlock1 , Level29Data.ShaderBlock2 , Level29Data.ShaderBlock3 , Level29Data.ShaderBlock4);
                    break;
                case 30:
                    MysticDrawLevel(Level30Data.Data,Level30Data.LevelWidth, Level30Data.LevelHeight,  Level30Data.ShaderBlock1 , Level30Data.ShaderBlock2 , Level30Data.ShaderBlock3 , Level30Data.ShaderBlock4);
                    break;
                case 31:
                    MysticDrawLevel(BonusData1.Data,BonusData1.LevelWidth, BonusData1.LevelHeight,  BonusData1.ShaderBlock1 , BonusData1.ShaderBlock2 , BonusData1.ShaderBlock3 , BonusData1.ShaderBlock4);
                    MysticControls.VirtualMouseEnabled = false;
                    break;
                case 41:
                    MysticDrawLevel(LevelCustomData.Data,LevelCustomData.LevelWidth, LevelCustomData.LevelHeight,  LevelCustomData.ShaderBlock1 , LevelCustomData.ShaderBlock2 , LevelCustomData.ShaderBlock3 , LevelCustomData.ShaderBlock4);
                    MysticControls.VirtualMouseEnabled = false;
                    break;

            }

        

            if (MysticCoreData.TrackNumber == 2){
                UpdateMusicStream(MysticCoreData.GameMusic1);
            }

            if (MysticCoreData.TrackNumber == 3){
                UpdateMusicStream(MysticCoreData.GameMusic2);
            }

            switch (MysticCoreData.TrackNumber)
            {
                case 2:
                    UpdateMusicStream(MysticCoreData.GameMusic1);
                    break;
                case 3:
                    UpdateMusicStream(MysticCoreData.GameMusic2);
                    break;
                case 4:
                    UpdateMusicStream(MysticCoreData.GameMusic3);
                    break;
                case 5:
                    UpdateMusicStream(MysticCoreData.GameMusic4);
                    break;

            }

            if (MysticCoreData.LevelID != 1000 && MysticCoreData.LevelID != 0 ){
                UpdateMusicStream(MysticCoreData.JumpSound);
                UpdateMusicStream(MysticCoreData.KillSound);
                UpdatePlayer();
                UpdateEnemy();
                UpdateTransitionTiles();
            }

        }

        if (!MysticBoss.Alive){

            // Splash Message 

            switch (TextCounter){
                case 1:
                    DrawText(TextSubtext("You've Defeated the Root of the Problem Right ?", 0, FrameCounter/5), 640 / 2 - MeasureText(TextSubtext("You've Defeated the Root of the Problem Right ?", 0, FrameCounter/5) , 20) / 2 , 200 , 20 , WHITE);
                    break;
                case 2:
                    DrawText(TextSubtext("It's All Over People Are Normal Now .", 0, FrameCounter/5), 640 / 2 - MeasureText(TextSubtext("It's All Over People Are Normal Now .", 0, FrameCounter/5) , 20) / 2 , 200 , 20 , WHITE);
                    break;
                case 3:
                    DrawText(TextSubtext("Right ??", 0, FrameCounter/5), 640 / 2 - MeasureText(TextSubtext("Right ??", 0, FrameCounter/5) , 20) / 2 , 200 , 20 , BLUE);
                    break;
            }
            if (TextCounter == 2 ){
                if (FrameCounter >= 460){
                    TextCounter ++;
                    FrameCounter = 0;
                }
            }
            else {
         
               if (FrameCounter >= 320){
                    if (TextCounter == 3){
                        StopMusicStream(MysticCoreData.GameMusic4);
                        PlayMusicStream(MysticCoreData.TitleMusic);
                        MysticPlayerOne.CanShoot = false;

                        MysticPlayerOne.HasRocket = false;

                        MysticInit();

                        ResetLevel(Level1Data);

                        ScanForSpawnTiles(Level1Data);

                        ScanForEnemyTiles(Level1Data);

                        MysticPlayerOne.Lives = 3;

                        MysticPlayerOne.Health = 100;
                        MysticCoreData.LevelID = 0;

                        StopMusicStream(MysticCoreData.KillSound);

                        StopMusicStream(MysticCoreData.ShootSound);

                        TextCounter = 1;
                        FrameCounter = 0;

                        HomeScreenScroller = 0;

                        MysticBoss.Alive = true;
                    }
                    else {
                        TextCounter ++;
                        FrameCounter = 0;
                    }


                }
            }
            FrameCounter ++;


        }

        if (MysticPlayerOne.y >= 500){
            MysticPlayerOne.Health = 0;
        }

        if (MysticPlayerOne.y <= 80){
            MysticPlayerOne.y = 80;
        }


            
        if (MysticCoreData.LevelID != -1 && MysticCoreData.LevelID != 0){

            if(MysticPlayerOne.Direction != 4){
                if( GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'0' && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'%' && GetTile((MysticPlayerOne.x + 40) / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'0' && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x + 20) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x + 20) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x + 20) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4  && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' ){
                    
                    if (GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) == L'Q' && MysticCoreData.BreakTimer <= 50){
                        MysticPlayerOne.VelocityY = MysticCoreData.GravityStrength;
                    }
                    else {
                        MysticPlayerOne.VelocityY = 0; 
                        if (!MysticPlayerOne.IsJumping){
                            FixPlayerY();
                        }
                    }
                    if (MysticControls.Up && MysticPlayerOne.IsJumping == false){
                        MysticPlayerOne.IsJumping = true;
                        PlayMusicStream(MysticCoreData.JumpSound);
                        
                    }
                }
                else {

                    MysticPlayerOne.VelocityY = MysticCoreData.GravityStrength;
                }
            }
            else {
                if( GetTile((MysticPlayerOne.x + 40) / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'0' && GetTile((MysticPlayerOne.x + 40) / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' &&  GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != L'!' && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' ){
                    MysticPlayerOne.VelocityY = 0;
                    if (!MysticPlayerOne.IsJumping){
                        FixPlayerY();
                    }
                    if (MysticControls.Up && MysticPlayerOne.IsJumping == false){
                        MysticPlayerOne.IsJumping = true;
                        PlayMusicStream(MysticCoreData.JumpSound);
                    }
                }
                else {
                    MysticPlayerOne.VelocityY = MysticCoreData.GravityStrength;
                }
            }
            if( GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != L'%'  && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' &&  GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != L'!' ){
                if (MysticPlayerOne.Direction != 4 ){
                    MysticPlayerOne.x -= MysticPlayerOne.VelocityX;
                }
            }

            if( GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != L'%'  && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' &&  GetTile((MysticPlayerOne. x+ 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != L'!' ){
                if (MysticPlayerOne.Direction != 4 ){
                    MysticPlayerOne.x -= MysticPlayerOne.VelocityX;
                }
            }

            if( GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != L'%'  && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' &&  GetTile((MysticPlayerOne.x + 40 ) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != L'!' ){
                if (MysticPlayerOne.Direction != 4 ){
                    MysticPlayerOne.x -= MysticPlayerOne.VelocityX;
                }
            }

            if( GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != L'%'  && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' &&  GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != L'!'   ){
                if (MysticPlayerOne.Direction != 2){
                    MysticPlayerOne.x += abs(MysticPlayerOne.VelocityX) ;
                }
            }

            if( GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  40) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y -  40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  40) / 20, CurrentData.LevelData) != L'%'  && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' &&  GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != L'!'  ){
                if (MysticPlayerOne.Direction != 2){
                    MysticPlayerOne.x += abs(MysticPlayerOne.VelocityX) ;
                }
            }

            if( GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  60) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  60) / 20, CurrentData.LevelData) != L'%' && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' &&  GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != L'!'){
                if (MysticPlayerOne.Direction != 2){
                    MysticPlayerOne.x += abs(MysticPlayerOne.VelocityX) ;
                }
            }


            if( GetTile(MysticPlayerOne.x / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) == L'A'){
                SetTile(MysticPlayerOne.x / 20 ,(MysticPlayerOne.y - 20) / 20, L'0');
                if (MysticPlayerOne.Health <= 80 ){MysticPlayerOne.Health += 20;}
            }

            if( GetTile(MysticPlayerOne.x / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) == L'^'){

                MysticPlayerOne.CanShoot = true;

                if (MysticCoreData.LevelID == 30){
                    MysticPlayerOne.HasRocket = true;
                }
            }

            if (MysticPlayerOne.Direction != 4){

                if( GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) == L'!' && MysticPlayerOne.HeartVisable){
                    SetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, L'0');
                    if (MysticPlayerOne.Lives != 5){MysticPlayerOne.Lives ++;}
                    MysticPlayerOne.HeartVisable = false;
                }
                if( GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) == L'!' && MysticPlayerOne.HeartVisable){
                    SetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 40) / 20, L'0');
                    if (MysticPlayerOne.Lives != 5){MysticPlayerOne.Lives ++;}
                    
                    MysticPlayerOne.HeartVisable = false;
                }
                if( GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) == L'!' && MysticPlayerOne.HeartVisable){
                    SetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 60) / 20, L'0');
                    if (MysticPlayerOne.Lives != 5){MysticPlayerOne.Lives ++;}
                    MysticPlayerOne.HeartVisable = false;
                }
                if( GetTile((MysticPlayerOne.x + 40) / 20,(MysticPlayerOne.y - 80) / 20, CurrentData.LevelData) == L'!' && MysticPlayerOne.HeartVisable){
                    SetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 80) / 20, L'0');
                    if (MysticPlayerOne.Lives != 5){MysticPlayerOne.Lives ++;}
                    MysticPlayerOne.HeartVisable = false;
                }

            }

            if (MysticPlayerOne.Direction != 2){
                if( GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) == L'!' && MysticPlayerOne.HeartVisable){
                    SetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 20) / 20, L'0');
                    if (MysticPlayerOne.Lives != 5){MysticPlayerOne.Lives ++;}
                    MysticPlayerOne.HeartVisable = false;
                }
                if( GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) == L'!' && MysticPlayerOne.HeartVisable){
                    SetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 40) / 20, L'0');
                    if (MysticPlayerOne.Lives != 5){MysticPlayerOne.Lives ++;}
                    MysticPlayerOne.HeartVisable = false;
                }
                if( GetTile((MysticPlayerOne.x) / 20,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) == L'!' && MysticPlayerOne.HeartVisable){
                    SetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 60) / 20, L'0');
                    if (MysticPlayerOne.Lives != 5){MysticPlayerOne.Lives ++;}
                    MysticPlayerOne.HeartVisable = false;
                }
                if( GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 80) / 20, CurrentData.LevelData) == L'!' && MysticPlayerOne.HeartVisable){
                    SetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 80) / 20, L'0');
                    if (MysticPlayerOne.Lives != 5){MysticPlayerOne.Lives ++;}
                    MysticPlayerOne.HeartVisable = false;

                }
            }



            if (GetTile(MysticPlayerOne.x / 20 ,(MysticPlayerOne.y - 80) / 20, CurrentData.LevelData) != L'0' && GetTile(MysticPlayerOne.x / 20 ,(MysticPlayerOne.y - 80) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile(MysticPlayerOne.x / 20 ,(MysticPlayerOne.y - 80) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile(MysticPlayerOne.x / 20 ,(MysticPlayerOne.y - 80) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile(MysticPlayerOne.x / 20 ,(MysticPlayerOne.y - 80) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4){
                MysticPlayerOne.y += MysticPlayerOne.VelocityY;
            }
            


            if( GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) == L'X' && GetTile((MysticPlayerOne.x + 40) / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) == L'X'){
                MysticPlayerOne.Health -= 2;
            }
        }

        
        

        if( GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) == L'Q'){
            if (MysticCoreData.BreakTimer != 0){MysticCoreData.BreakTimer --;}
        }
        else {
            if (MysticCoreData.BreakTimer != 100){
                MysticCoreData.BreakTimer ++ ;
            }
        }


        if (IsKeyDown(KEY_F11)){ToggleFullscreen();}

        UpdateControls();


        EndDrawing();
        TickAnimations();

    }
    CloseWindow();
}
