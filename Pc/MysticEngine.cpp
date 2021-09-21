/* Code By Liquid 2021 */

#include "MysticEngineCoreData.hpp"
#include <iostream>
#include <string>
#include <fstream>

// This Code Is a Modified Engine I Wrote a While back so Its a bit messy

// MysticEngine 1.2.0 ( Modified )

// Runs on raylib 3.5

using namespace std;

int main (void){


    InitWindow(640 , 500 , "Wisp . . .");
    SetWindowIcon(LoadImage("GameAssets/Icon/icon.png"));  
    MysticCoreData.LowEndHardware = false;
    int TextAnimationValue = 0;
    int HomeScreenScroller = 0;
    if (LoadMconfFile("GameAssets/MainConf/Full_Screen.mconf") == L'1'){
        ToggleFullscreen();
    }
    int Help = false;
    MysticBoss.Alive = true;
    MysticCoreData.GameType = 1;
    InitAudioDevice();
    SetTargetFPS(60);

    #if (defined(TEST_PROGRAM))
        Level_1_Data.Data = LoadFile(argv[1]);
    #endif


    MysticInit();
    InitLevelData();
    LoadTexture();

    MysticPlayerOne.Text_Size = 40;

    MysticCoreData.CanMoveOn = false;

    int secondsLoc = GetShaderLocation(Core_Shaders.Water, "secondes"); // Shader Stuff
    int freqXLoc = GetShaderLocation(Core_Shaders.Water, "freqX");
    int freqYLoc = GetShaderLocation(Core_Shaders.Water, "freqY");
    int ampXLoc = GetShaderLocation(Core_Shaders.Water, "ampX");
    int ampYLoc = GetShaderLocation(Core_Shaders.Water, "ampY");
    int speedXLoc = GetShaderLocation(Core_Shaders.Water, "speedX");
    int speedYLoc = GetShaderLocation(Core_Shaders.Water, "speedY");
    // Shader uniform values that can be updated at any time
    float freqX = 25.0f;
    float freqY = 25.0f;
    float ampX = 5.0f;
    float ampY = 5.0f;
    float speedX = 8.0f;
    float speedY = 8.0f;

    float screenSize[2] = { (float)GetScreenWidth(), (float)GetScreenHeight() };

    #if (defined(WINDOWS_BUILD))
        SetShaderValue(Core_Shaders.Water, GetShaderLocation(Core_Shaders.Water, "size"), &screenSize, UNIFORM_VEC2); // Shader Loading 
        SetShaderValue(Core_Shaders.Water, freqXLoc, &freqX, UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, freqYLoc, &freqY, UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, ampXLoc, &ampX, UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, ampYLoc, &ampY, UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, speedXLoc, &speedX, UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, speedYLoc, &speedY, UNIFORM_FLOAT  );
    #endif

    #if (defined(LINUX_BUILD))
        SetShaderValue(Core_Shaders.Water, GetShaderLocation(Core_Shaders.Water, "size"), &screenSize, UNIFORM_VEC2);
        SetShaderValue(Core_Shaders.Water, freqXLoc, &freqX, UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, freqYLoc, &freqY, UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, ampXLoc, &ampX, UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, ampYLoc, &ampY, UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, speedXLoc, &speedX, UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, speedYLoc, &speedY, UNIFORM_FLOAT  );
    #endif

    #if (defined(RPI_BUILD))
        SetShaderValue(Core_Shaders.Water, GetShaderLocation(Core_Shaders.Water, "size"), &screenSize, SHADER_UNIFORM_VEC2);
        SetShaderValue(Core_Shaders.Water, freqXLoc, &freqX, SHADER_UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, freqYLoc, &freqY, SHADER_UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, ampXLoc, &ampX, SHADER_UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, ampYLoc, &ampY, SHADER_UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, speedXLoc, &speedX, SHADER_UNIFORM_FLOAT  );
        SetShaderValue(Core_Shaders.Water, speedYLoc, &speedY, SHADER_UNIFORM_FLOAT  );
    #endif

    float seconds = 0.0f;
    
    MysticCamera.XOffset = 0;

    MysticCoreData.Level_ID = 0;

    MysticCoreData.Title_Music = LoadMusicStream("GameAssets/Music/Title.mp3");

    MysticCoreData.Game_Music1 = LoadMusicStream("GameAssets/Music/Music1.mp3");

    MysticCoreData.Game_Music2 = LoadMusicStream("GameAssets/Music/Music2.mp3");

    MysticCoreData.Game_Music3 = LoadMusicStream("GameAssets/Music/Music3.mp3");

    MysticCoreData.Game_Music4 = LoadMusicStream("GameAssets/Music/Music4.mp3");

    MysticBoss.Projectile_x = 0;

    MysticBoss.Projectile_y = 0;

    MysticBoss.Projectile_trigger = false;

    int FrameCounter = 0;

    int TextCounter = 1;



    MysticCoreData.TrackNumber = 3;

    int Start = false;
    ResetLevel(Level_1_Data);
    // Quickly Scan for + Tiles to Set the Players Spawn 
    ScanForSpawnTiles(Level_1_Data);

    // Scans for Enemy Tiles or & 
    ScanForEnemyTiles(Level_1_Data);

    PlayMusicStream(MysticCoreData.Title_Music);


    MysticPlayerOne.Lives = 4;
    MysticPlayerOne.HeartVisable = true;

    while (!WindowShouldClose()){ 

        seconds += GetFrameTime();

        #if (defined(RPI_BUILD))
            SetShaderValue(Core_Shaders.Water, secondsLoc, &seconds, SHADER_UNIFORM_FLOAT);
        #endif
        #if (defined(LINUX_BUILD))
            SetShaderValue(Core_Shaders.Water, secondsLoc, &seconds, UNIFORM_FLOAT);
        #endif
        #if (defined(WINDOWS_BUILD))
            SetShaderValue(Core_Shaders.Water, secondsLoc, &seconds, UNIFORM_FLOAT);
        #endif

        BeginDrawing();

        ClearBackground(BLACK);

        if (MysticCoreData.Level_ID == 0){

            if (Start){
                MysticDrawLevel(Level_1_Data.Data,Level_1_Data.LevelWidth, Level_1_Data.LevelHeight,  Level_1_Data.ShaderBlock1 , Level_1_Data.ShaderBlock2 , Level_1_Data.ShaderBlock3 , Level_1_Data.ShaderBlock4);
                MysticCamera.XOffset ++;

                if (MysticCamera.XOffset >= 1280){
                    MysticCamera.XOffset = 0;
                }
                switch (TextCounter)
                {
                    case 1:
                        DrawText(TextSubtext("     There Has Been Something Strange Going on.", 0, FrameCounter/5), 50 , 200 , 20 , WHITE);
                        break;
                    case 2:
                        DrawText(TextSubtext("         People Have Been Acting Violent.      ", 0, FrameCounter/5), 50 , 200 , 20 , WHITE);
                        break;
                    case 3:
                        DrawText(TextSubtext("      There's a Gold Cave to the West Shining.  ", 0, FrameCounter/5), 50 , 200 , 20 , WHITE);
                        break;
                    case 4:
                        DrawText(TextSubtext("                 Better Go Investigate.            ", 0, FrameCounter/5), 50 , 200 , 20 , WHITE);
                        break;
                    
                    default:
                        break;
                }

                if (MysticCoreData.Animation_Ticker <= 50){
                    DrawText("                              Space" , 50 , 400 , 20 , WHITE);
                }
                if (IsKeyPressed(KEY_SPACE)){
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

                if (!Help){
                    UpdateMusicStream(MysticCoreData.Title_Music);
                    MysticDrawLevel(Level_1_Data.Data,Level_1_Data.LevelWidth, Level_1_Data.LevelHeight,  Level_1_Data.ShaderBlock1 , Level_1_Data.ShaderBlock2 , Level_1_Data.ShaderBlock3 , Level_1_Data.ShaderBlock4);
                    DrawText(TextSubtext("Wi",0,TextAnimationValue / 20), 288 - HomeScreenScroller  , 200 + HomeScreenScroller , 32 + HomeScreenScroller / 4 , WHITE);
                    DrawText(TextSubtext("sp",0,TextAnimationValue / 20), 320 - HomeScreenScroller + HomeScreenScroller / 4 , 200 + HomeScreenScroller  , 32 + HomeScreenScroller / 4  , BLUE);
                    if (MysticCoreData.Animation_Ticker >= 50) DrawText(TextSubtext("Press Space",0,TextAnimationValue / 2), 270 - HomeScreenScroller  , 300 + HomeScreenScroller , 16 + HomeScreenScroller / 8 , WHITE);
                    MysticCamera.XOffset ++;

                    if (MysticCamera.XOffset >= 1280){
                        MysticCamera.XOffset = 0;
                    }
                    if (TextAnimationValue <= 40){
                        TextAnimationValue ++;
                    }
                    if (IsKeyPressed(KEY_SPACE)){

                        HomeScreenScroller = 2;
                    }

                    DrawText("Story" , 20  - HomeScreenScroller + HomeScreenScroller / 4 , 450  + HomeScreenScroller , 20 + HomeScreenScroller / 4 , WHITE);

                    if (GetCollision(20 , 450 , 50 , 20 , GetMouseX() , GetMouseY() , 5, 5 ) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                        Start = true;
                    }

                    DrawText("Help" , 570  - HomeScreenScroller + HomeScreenScroller / 4, 450  + HomeScreenScroller  , 20 + HomeScreenScroller / 4 , WHITE);

                    if (GetCollision(570 , 450 , 50 , 20 , GetMouseX() , GetMouseY() , 5, 5 ) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                        Help = true;
                    }

                    if (HomeScreenScroller >= 1 && HomeScreenScroller <= 60){
                        rlViewport(0, 0 ,640 + HomeScreenScroller * 2 ,500 + HomeScreenScroller * 2);
                        HomeScreenScroller ++;
                    }
                    else{
                        if (HomeScreenScroller != 0){
                            rlViewport(0,0,640,500);
                            MysticCoreData.Level_ID = 1;
                            MysticCamera.XOffset = 0;
                            StopMusicStream(MysticCoreData.Title_Music);
                            PlayMusicStream(MysticCoreData.Game_Music2);
                        }
                    }

                }
                else {
                    MysticDrawLevel(Level_1_Data.Data,Level_1_Data.LevelWidth, Level_1_Data.LevelHeight,  Level_1_Data.ShaderBlock1 , Level_1_Data.ShaderBlock2 , Level_1_Data.ShaderBlock3 , Level_1_Data.ShaderBlock4);
                    MysticCamera.XOffset ++;

                    if (MysticCamera.XOffset >= 1280){
                        MysticCamera.XOffset = 0;
                    }
                    DrawText("Back" , 20 , 20 , 20 , WHITE);
                    if (GetCollision(20 , 20 , 50 , 20 , GetMouseX() , GetMouseY() , 5, 5 ) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                        Help = false;
                    }
                    DrawText("Controls" , 80 , 100 , 25 , WHITE);
                    DrawText("Jump : Up Arrow Key" , 100 , 200 , 20 , WHITE);
                    DrawText("Right : Right Arrow Key" , 100 , 230 , 20 , WHITE);
                    DrawText("Left : Left Arrow Key" , 100 , 250 , 20 , WHITE);
                    DrawText("Shoot ( Normal Weapon ) : Space Key" , 100 , 270 , 20 , WHITE);
                    DrawText("Shoot ( Boss Weapon ) : Left Click" , 100 , 290 , 20 , WHITE);


                }
            }
                
        }

        if (MysticBoss.Alive){

            switch (MysticCoreData.Level_ID){

                case 1:
                    MysticDrawLevel(Level_1_Data.Data,Level_1_Data.LevelWidth, Level_1_Data.LevelHeight,  Level_1_Data.ShaderBlock1 , Level_1_Data.ShaderBlock2 , Level_1_Data.ShaderBlock3 , Level_1_Data.ShaderBlock4);
                    break;

                case 2:
                    MysticDrawLevel(Level_2_Data.Data,Level_2_Data.LevelWidth, Level_2_Data.LevelHeight,  Level_2_Data.ShaderBlock1 , Level_2_Data.ShaderBlock2 , Level_2_Data.ShaderBlock3 , Level_2_Data.ShaderBlock4);
                    break;

                case 3:
                    MysticDrawLevel(Level_3_Data.Data,Level_3_Data.LevelWidth, Level_3_Data.LevelHeight,  Level_3_Data.ShaderBlock1 , Level_3_Data.ShaderBlock2 , Level_3_Data.ShaderBlock3 , Level_3_Data.ShaderBlock4);
                    break;

                case 4:
                    MysticDrawLevel(Level_4_Data.Data,Level_4_Data.LevelWidth, Level_4_Data.LevelHeight,  Level_4_Data.ShaderBlock1 , Level_4_Data.ShaderBlock2 , Level_4_Data.ShaderBlock3 , Level_4_Data.ShaderBlock4);
                    break;

                case 5:
                    MysticDrawLevel(Level_5_Data.Data,Level_5_Data.LevelWidth, Level_5_Data.LevelHeight,  Level_5_Data.ShaderBlock1 , Level_5_Data.ShaderBlock2 , Level_5_Data.ShaderBlock3 , Level_5_Data.ShaderBlock4);
                    break;

                case 6:
                    MysticDrawLevel(Level_6_Data.Data,Level_6_Data.LevelWidth, Level_6_Data.LevelHeight,  Level_6_Data.ShaderBlock1 , Level_6_Data.ShaderBlock2 , Level_6_Data.ShaderBlock3 , Level_6_Data.ShaderBlock4);
                    break;

                case 7:
                    MysticDrawLevel(Level_7_Data.Data,Level_7_Data.LevelWidth, Level_7_Data.LevelHeight,  Level_7_Data.ShaderBlock1 , Level_7_Data.ShaderBlock2 , Level_7_Data.ShaderBlock3 , Level_7_Data.ShaderBlock4);
                    break;

                case 8:
                    MysticDrawLevel(Level_8_Data.Data,Level_8_Data.LevelWidth, Level_8_Data.LevelHeight,  Level_8_Data.ShaderBlock1 , Level_8_Data.ShaderBlock2 , Level_8_Data.ShaderBlock3 , Level_8_Data.ShaderBlock4);
                    break;

                case 9:
                    MysticDrawLevel(Level_9_Data.Data,Level_9_Data.LevelWidth, Level_9_Data.LevelHeight,  Level_9_Data.ShaderBlock1 , Level_9_Data.ShaderBlock2 , Level_9_Data.ShaderBlock3 , Level_9_Data.ShaderBlock4);
                    break;

                case 10:
                    MysticDrawLevel(Level_10_Data.Data,Level_10_Data.LevelWidth, Level_10_Data.LevelHeight,  Level_10_Data.ShaderBlock1 , Level_10_Data.ShaderBlock2 , Level_10_Data.ShaderBlock3 , Level_10_Data.ShaderBlock4);
                    break;
                case 11:
                    MysticDrawLevel(Level_11_Data.Data,Level_11_Data.LevelWidth, Level_11_Data.LevelHeight,  Level_11_Data.ShaderBlock1 , Level_11_Data.ShaderBlock2 , Level_11_Data.ShaderBlock3 , Level_11_Data.ShaderBlock4);
                    break;
                case 12:
                    MysticDrawLevel(Level_12_Data.Data,Level_12_Data.LevelWidth, Level_12_Data.LevelHeight,  Level_12_Data.ShaderBlock1 , Level_12_Data.ShaderBlock2 , Level_12_Data.ShaderBlock3 , Level_12_Data.ShaderBlock4);
                    break;
                case 13:
                    MysticDrawLevel(Level_13_Data.Data,Level_13_Data.LevelWidth, Level_13_Data.LevelHeight,  Level_13_Data.ShaderBlock1 , Level_13_Data.ShaderBlock2 , Level_13_Data.ShaderBlock3 , Level_13_Data.ShaderBlock4);
                    break;
                case 14:
                    MysticDrawLevel(Level_14_Data.Data,Level_14_Data.LevelWidth, Level_14_Data.LevelHeight,  Level_14_Data.ShaderBlock1 , Level_14_Data.ShaderBlock2 , Level_14_Data.ShaderBlock3 , Level_14_Data.ShaderBlock4);
                    break;
                case 15:
                    MysticDrawLevel(Level_15_Data.Data,Level_15_Data.LevelWidth, Level_15_Data.LevelHeight,  Level_15_Data.ShaderBlock1 , Level_15_Data.ShaderBlock2 , Level_15_Data.ShaderBlock3 , Level_15_Data.ShaderBlock4);
                    break;
                case 16:
                    MysticDrawLevel(Level_16_Data.Data,Level_16_Data.LevelWidth, Level_16_Data.LevelHeight,  Level_16_Data.ShaderBlock1 , Level_16_Data.ShaderBlock2 , Level_16_Data.ShaderBlock3 , Level_16_Data.ShaderBlock4);
                    break;
                case 17:
                    MysticDrawLevel(Level_17_Data.Data,Level_17_Data.LevelWidth, Level_17_Data.LevelHeight,  Level_17_Data.ShaderBlock1 , Level_17_Data.ShaderBlock2 , Level_17_Data.ShaderBlock3 , Level_17_Data.ShaderBlock4);
                    break;
                case 18:
                    MysticDrawLevel(Level_18_Data.Data,Level_18_Data.LevelWidth, Level_18_Data.LevelHeight,  Level_18_Data.ShaderBlock1 , Level_18_Data.ShaderBlock2 , Level_18_Data.ShaderBlock3 , Level_18_Data.ShaderBlock4);
                    break;
                case 19:
                    MysticDrawLevel(Level_19_Data.Data,Level_19_Data.LevelWidth, Level_19_Data.LevelHeight,  Level_19_Data.ShaderBlock1 , Level_19_Data.ShaderBlock2 , Level_19_Data.ShaderBlock3 , Level_19_Data.ShaderBlock4);
                    break;
                case 20:
                    MysticDrawLevel(Level_20_Data.Data,Level_20_Data.LevelWidth, Level_20_Data.LevelHeight,  Level_20_Data.ShaderBlock1 , Level_20_Data.ShaderBlock2 , Level_20_Data.ShaderBlock3 , Level_20_Data.ShaderBlock4);
                    break;
                case 21:
                    MysticDrawLevel(Level_21_Data.Data,Level_21_Data.LevelWidth, Level_21_Data.LevelHeight,  Level_21_Data.ShaderBlock1 , Level_21_Data.ShaderBlock2 , Level_21_Data.ShaderBlock3 , Level_21_Data.ShaderBlock4);
                    break;
                case 22:
                    MysticDrawLevel(Level_22_Data.Data,Level_22_Data.LevelWidth, Level_22_Data.LevelHeight,  Level_22_Data.ShaderBlock1 , Level_22_Data.ShaderBlock2 , Level_22_Data.ShaderBlock3 , Level_22_Data.ShaderBlock4);
                    break;
                case 23:
                    MysticDrawLevel(Level_23_Data.Data,Level_23_Data.LevelWidth, Level_23_Data.LevelHeight,  Level_23_Data.ShaderBlock1 , Level_23_Data.ShaderBlock2 , Level_23_Data.ShaderBlock3 , Level_23_Data.ShaderBlock4);
                    break;
                case 24:
                    MysticDrawLevel(Level_24_Data.Data,Level_24_Data.LevelWidth, Level_24_Data.LevelHeight,  Level_24_Data.ShaderBlock1 , Level_24_Data.ShaderBlock2 , Level_24_Data.ShaderBlock3 , Level_24_Data.ShaderBlock4);
                    break;
                case 25:
                    MysticDrawLevel(Level_25_Data.Data,Level_25_Data.LevelWidth, Level_25_Data.LevelHeight,  Level_25_Data.ShaderBlock1 , Level_25_Data.ShaderBlock2 , Level_25_Data.ShaderBlock3 , Level_25_Data.ShaderBlock4);
                    break;
                case 26:
                    MysticDrawLevel(Level_26_Data.Data,Level_26_Data.LevelWidth, Level_26_Data.LevelHeight,  Level_26_Data.ShaderBlock1 , Level_26_Data.ShaderBlock2 , Level_26_Data.ShaderBlock3 , Level_26_Data.ShaderBlock4);
                    break;
                case 27:
                    MysticDrawLevel(Level_27_Data.Data,Level_27_Data.LevelWidth, Level_27_Data.LevelHeight,  Level_27_Data.ShaderBlock1 , Level_27_Data.ShaderBlock2 , Level_27_Data.ShaderBlock3 , Level_27_Data.ShaderBlock4);
                    break;
                case 28:
                    MysticDrawLevel(Level_28_Data.Data,Level_28_Data.LevelWidth, Level_28_Data.LevelHeight,  Level_28_Data.ShaderBlock1 , Level_28_Data.ShaderBlock2 , Level_28_Data.ShaderBlock3 , Level_28_Data.ShaderBlock4);
                    break;
                case 29:
                    MysticDrawLevel(Level_29_Data.Data,Level_29_Data.LevelWidth, Level_29_Data.LevelHeight,  Level_29_Data.ShaderBlock1 , Level_29_Data.ShaderBlock2 , Level_29_Data.ShaderBlock3 , Level_29_Data.ShaderBlock4);
                    break;
                case 30:
                    MysticDrawLevel(Level_30_Data.Data,Level_30_Data.LevelWidth, Level_30_Data.LevelHeight,  Level_30_Data.ShaderBlock1 , Level_30_Data.ShaderBlock2 , Level_30_Data.ShaderBlock3 , Level_30_Data.ShaderBlock4);
                    break;

            }

        

            if (MysticCoreData.TrackNumber == 2){
                UpdateMusicStream(MysticCoreData.Game_Music1);
            }

            if (MysticCoreData.TrackNumber == 3){
                UpdateMusicStream(MysticCoreData.Game_Music2);
            }

            switch (MysticCoreData.TrackNumber)
            {
                case 2:
                    UpdateMusicStream(MysticCoreData.Game_Music1);
                    break;
                case 3:
                    UpdateMusicStream(MysticCoreData.Game_Music2);
                    break;
                case 4:
                    UpdateMusicStream(MysticCoreData.Game_Music3);
                    break;
                case 5:
                    UpdateMusicStream(MysticCoreData.Game_Music4);
                    break;

            }

            if (MysticCoreData.Level_ID != 1000 && MysticCoreData.Level_ID != 0 ){
                UpdateMusicStream(MysticCoreData.Jump_Sound);
                UpdateMusicStream(MysticCoreData.Kill_Sound);
                UpdatePlayer();
                UpdateEnemy();
                UpdateTransitionTiles();
            }

        }

        if (!MysticBoss.Alive){
            // Splash Message 


            switch (TextCounter){
                case 1:
                    DrawText(TextSubtext("You've Defeated the Root of the Problem Right ?", 0, FrameCounter/5), 80 , 200 , 20 , WHITE);
                    break;
                case 2:
                    DrawText(TextSubtext("It's All Over People Are Normal Now .", 0, FrameCounter/5), 130 , 200 , 20 , WHITE);
                    break;
                case 3:
                    DrawText(TextSubtext("Right ?", 0, FrameCounter/5), 290 , 200 , 20 , BLUE);
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
                        StopMusicStream(MysticCoreData.Game_Music4);
                        PlayMusicStream(MysticCoreData.Title_Music);
                        MysticPlayerOne.CanShoot = false;

                        MysticPlayerOne.HasRocket = false;

                        MysticInit();

                        ResetLevel(Level_1_Data);

                        ScanForSpawnTiles(Level_1_Data);

                        ScanForEnemyTiles(Level_1_Data);

                        MysticPlayerOne.Lives = 3;

                        MysticPlayerOne.Health = 100;
                        MysticCoreData.Level_ID = 0;

                        StopMusicStream(MysticCoreData.Kill_Sound);

                        StopMusicStream(MysticCoreData.Shoot_Sound);

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


            
        if (MysticCoreData.Level_ID != -1 && MysticCoreData.Level_ID != 0){ // Collisions 	↓ 
                                                                            //            
            if(MysticPlayerOne.direction != 4){
                if( GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'0' && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'%' && GetTile((MysticPlayerOne.x + 40) / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'0' && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x + 20) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x + 20) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x + 20) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4  && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' ){
                    
                    if (GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) == L'Q' && MysticCoreData.BreakTimer <= 50){
                        MysticPlayerOne.Velocity_Y = MysticCoreData.Gravity_Strength;
                    }
                    else {
                        MysticPlayerOne.Velocity_Y = 0;
                    }
                    if (IsKeyDown(KEY_UP) && MysticPlayerOne.IsJumping == false){
                        MysticPlayerOne.IsJumping = true;
                        PlayMusicStream(MysticCoreData.Jump_Sound);
                        
                    }
                }
                else {

                    MysticPlayerOne.Velocity_Y = MysticCoreData.Gravity_Strength;
                }
            }
            else {
                if( GetTile((MysticPlayerOne.x + 40) / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'0' && GetTile((MysticPlayerOne.x + 40) / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' &&  GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != L'!' && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' ){
                    MysticPlayerOne.Velocity_Y = 0;
                    if (IsKeyDown(KEY_UP) && MysticPlayerOne.IsJumping == false){
                        MysticPlayerOne.IsJumping = true;
                        PlayMusicStream(MysticCoreData.Jump_Sound);
                    }
                }
                else {
                    MysticPlayerOne.Velocity_Y = MysticCoreData.Gravity_Strength;
                }
            }
            if( GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != L'%'  && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' &&  GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != L'!' ){
                if (MysticPlayerOne.direction != 4 ){
                    MysticPlayerOne.x -= MysticPlayerOne.Velocity_X;
                }
            }

            if( GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != L'%'  && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' &&  GetTile((MysticPlayerOne. x+ 40) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != L'!' ){
                if (MysticPlayerOne.direction != 4 ){
                    MysticPlayerOne.x -= MysticPlayerOne.Velocity_X;
                }
            }

            if( GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticPlayerOne.x + 40) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != L'%'  && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' &&  GetTile((MysticPlayerOne.x + 40 ) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != L'!' ){
                if (MysticPlayerOne.direction != 4 ){
                    MysticPlayerOne.x -= MysticPlayerOne.Velocity_X;
                }
            }

            if( GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != L'%'  && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' &&  GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) != L'!'   ){
                if (MysticPlayerOne.direction != 2){
                    MysticPlayerOne.x += abs(MysticPlayerOne.Velocity_X) ;
                }
            }

            if( GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  40) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y -  40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  40) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  40) / 20, CurrentData.LevelData) != L'%'  && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' &&  GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 40) / 20, CurrentData.LevelData) != L'!'  ){
                if (MysticPlayerOne.direction != 2){
                    MysticPlayerOne.x += abs(MysticPlayerOne.Velocity_X) ;
                }
            }

            if( GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  60) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  60) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticPlayerOne.x ) / 20 ,(MysticPlayerOne.y -  60) / 20, CurrentData.LevelData) != L'%' && GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) != L'!' &&  GetTile((MysticPlayerOne.x) / 20 ,(MysticPlayerOne.y - 60) / 20, CurrentData.LevelData) != L'!'){
                if (MysticPlayerOne.direction != 2){
                    MysticPlayerOne.x += abs(MysticPlayerOne.Velocity_X) ;
                }
            }


            if( GetTile(MysticPlayerOne.x / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) == L'A'){
                SetTile(MysticPlayerOne.x / 20 ,(MysticPlayerOne.y - 20) / 20, L'0');
                if (MysticPlayerOne.Health <= 80 ){MysticPlayerOne.Health += 20;}
            }

            if( GetTile(MysticPlayerOne.x / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) == L'^'){

                MysticPlayerOne.CanShoot = true;

                if (MysticCoreData.Level_ID == 30){
                    MysticPlayerOne.HasRocket = true;
                }
            }

            if (MysticPlayerOne.direction != 4){

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

            if (MysticPlayerOne.direction != 2){
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


            if( GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) == L'X' && GetTile((MysticPlayerOne.x + 40) / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) == L'X'){
                MysticPlayerOne.Health -= 2;
            }
        }

    
        if( GetTile(MysticPlayerOne.x / 20 ,MysticPlayerOne.y / 20, CurrentData.LevelData) == L'Q'){  // Breakable Blocks Collision
            if (MysticCoreData.BreakTimer != 0){MysticCoreData.BreakTimer --;}
        }
        else {
            if (MysticCoreData.BreakTimer != 100){
                MysticCoreData.BreakTimer ++ ;
            }
        }

        //                                                                                                               	↑ 

        EndShaderMode();

        if (IsKeyDown(KEY_F11)){
            ToggleFullscreen();
        }

        if (IsKeyDown(KEY_L)){
            MysticCoreData.LowEndHardware = true;
        }


        EndDrawing();
        Tick_Animations();

    }
    CloseWindow();
}
