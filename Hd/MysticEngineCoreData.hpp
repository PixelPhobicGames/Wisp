#include <raylib.h>
#include "MysticLevelRenderer.hpp"
#include <time.h>
#include "rlgl/rlgl.h"

//#define LINUX_BUILD //GL3.3

//#define RPI_BUILD // Raylib 3.5 : GL2 

#define WINDOWS_BUILD //GL3.3



static void ScanForSpawnTiles(LevelData LV){
    for (int x = 0; x <= LV.LevelWidth ;  x ++ ){
        for (int y = 0; y <= 24;  y ++ ){
            if (LV.Data[y*LV.LevelWidth+x] == L'+'){
                MysticPlayerOne.x = x * 20;
                MysticPlayerOne.y =  y * 20 ;
                MysticCamera.XOffset = (MysticPlayerOne.x) - 50;
            }
        }
    }
}


static void ScanForEnemyTiles(LevelData LV){
    int i = 0;
    for (int x = 0; x <= LV.LevelWidth ;  x ++ ){
        for (int y = 0; y <= 24;  y ++ ){
            if (LV.Data[y*LV.LevelWidth+x] == L'&'){
                i ++;
                MysticEnemy[i].x = x * 20;
                MysticEnemy[i].y =  y * 20 ;
                MysticEnemy[i].direction = 4;
                MysticEnemy[i].JumpCount = 20;
                if (MysticCoreData.Level_ID == 30){
                    MysticEnemy[i].health = 300;
                }
                else {
                    MysticEnemy[i].health = 100;
                }
                MysticEnemy[i].isalive = true;
                MysticEnemy[i].DT = 0;

            }
        }
    }

}


static void ResetLevel(LevelData LV){
    CurrentData.LevelData = LV.Data;
    CurrentData.LevelWidth = LV.LevelWidth;
    CurrentData.LevelHeight = LV.LevelHeight;
    CurrentData.LevelNonCollisionBlock1 = LV.NonCollisionBlock1;
    CurrentData.LevelNonCollisionBlock2 = LV.NonCollisionBlock2;
    CurrentData.LevelNonCollisionBlock3 = LV.NonCollisionBlock3;
    CurrentData.LevelNonCollisionBlock4 = LV.NonCollisionBlock4;
}


void delay(float number_of_seconds) 
{ 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
} 

auto TransitionLevel( int NextLevelID , LevelData NextLevelData ){
    if (MysticCoreData.CanMoveOn){

        for (int i = 0; i < EMC; i++)
        {
            MysticEnemy[i].x = 0;
            MysticEnemy[i].y = 0;
            MysticEnemy[i].direction = 0;
            MysticEnemy[i].JumpCount = 0;
            MysticEnemy[i].health = 0;
            MysticEnemy[i].isalive = false;
            MysticEnemy[i].DT = 0;
        }

        MysticCoreData.Level_ID = NextLevelID;
        MysticPlayerOne.Text_Size = 40;
        rlViewport(0, 0 , 640 ,500 );
        MysticPlayerOne.HeartVisable = true;

        ResetLevel(NextLevelData);
        ScanForSpawnTiles(NextLevelData);
        ScanForEnemyTiles(NextLevelData);


        MysticCoreData.CanMoveOn = false;
        //TGSH = false;
    }
    else {
        //TGSH = true;                
        MysticPlayerOne.Text_Size --; 
        MysticPlayerOne.x -= MysticPlayerOne.Velocity_X;
        MysticPlayerOne.Velocity_Y = 0;
        MysticPlayerOne.Velocity_X = 0;

        rlViewport(0, 0 ,640 + MysticPlayerOne.Text_Size * 2 ,500 + MysticPlayerOne.Text_Size * 2);

        if (MysticPlayerOne.Text_Size == 20){
                MysticCoreData.CanMoveOn= true;
        }
    }

}
static void MysticInit(){

    //MysticCoreData.Level_ID = 0;
    MysticCoreData.FPS = 60;
    MysticCoreData.Gravity_Strength = 5;
    MysticCoreData.Debug = true;
    MysticCoreData.Animation_Ticker = 0;
    MysticCoreData.Hover_Animation_Ticker=0;
    MysticCoreData.Hover_Animation_DIR = 2;

    MysticPlayerOne.x = 50;
    MysticPlayerOne.y = 250;
    MysticPlayerOne.facing_direction = 2;
    MysticPlayerOne.JumpCounter = 20;
    MysticPlayerOne.JumpCoolDown = 60;
    MysticPlayerOne.Projectile_x = 0;
    MysticPlayerOne.Projectile_y = 0;
    MysticPlayerOne.Projectile_trigger = false;
    MysticPlayerOne.Projectile_Direction = 2;

    MysticCamera.XOffset = 0;
    MysticCamera.YOffset = 0;

    MysticControls.Right = false;
    MysticControls.Left = false;
    MysticControls.Up = false;
    MysticControls.Shoot = false;

}

static void UpdateControls(){
    if (!IsGamepadAvailable(0)){
        if (IsKeyDown(KEY_RIGHT)){
            MysticControls.Right = true;
        }
        else {
            MysticControls.Right = false;
        }

        if (IsKeyDown(KEY_LEFT)){
            MysticControls.Left = true;
        }
        else {
            MysticControls.Left = false;
        }

        if (IsKeyDown(KEY_UP)){
            MysticControls.Up = true;
        }
        else {
            MysticControls.Up = false;
        }

        if (IsKeyDown(KEY_SPACE)){
            MysticControls.Shoot = true;
        }
        else {
            MysticControls.Shoot = false;
        }
        MysticControls.VirtualMouseEnabled = false;
    
    }
    else {
        
        if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
            MysticControls.Up = true;
        }
        else {
            MysticControls.Up = false;
        }
        if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)){
            MysticControls.Right = true;
        }
        else {
            MysticControls.Right = false;
        }
        if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)){
            MysticControls.Left = true;
        }
        else {
            MysticControls.Left = false;
        }

        if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_2)){
            MysticControls.Shoot = true;
        }
        else {
            MysticControls.Shoot = false;
        }


        if (GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) >= .75 && GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) <= 1.0){
            MysticControls.Right = true;
        }
        else{
            MysticControls.Right = false;
        }
        if (GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) <= -0.75 && GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) >= -1.0){
            MysticControls.Left = true;
        }
        else{
            MysticControls.Left = false;
        }

        if (MysticControls.VirtualMouseEnabled ){

            if (GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) <= -0.75 && GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_X) >= -1.0){
                MysticControls.VirtualMouseX -= 4;
            }

            if (GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) >= 0.75 && GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_X) <= 1.0){
                MysticControls.VirtualMouseX += 4;
            }

            if (GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y) <= -0.75 && GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_Y) >= -1.0){
                MysticControls.VirtualMouseY -= 4;
            }

            if (GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y) >= 0.75 && GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_Y) <= 1.0){
                MysticControls.VirtualMouseY += 4;
            }

            if (MysticControls.VirtualMouseX >= 640){
                MysticControls.VirtualMouseX -= 4;
            }
            if (MysticControls.VirtualMouseX <= 0){
                MysticControls.VirtualMouseX += 4;
            }
            if (MysticControls.VirtualMouseY >= 500){
                MysticControls.VirtualMouseY -= 4;
            }
            if (MysticControls.VirtualMouseY <= 0){
                MysticControls.VirtualMouseY += 4;
            }

            if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_UP)){
                MysticControls.VirtualMouseClick = true;
            }
            else {
                MysticControls.VirtualMouseClick = false;
            }
            
        }

        if (MysticControls.VirtualMouseEnabled){
            DrawText("@" , MysticControls.VirtualMouseX , MysticControls.VirtualMouseY, 12, BLUE);
        }

        if (MysticCoreData.Level_ID >= 1 && MysticCoreData.Level_ID <= 29){
            MysticControls.VirtualMouseEnabled = false;
        }
        else {
            MysticControls.VirtualMouseEnabled = true;
        }

    }
}

static void LoadTexture(){

    MysticCoreData.Title_Music = LoadMusicStream("GameAssets/music/title.wav");
    
    #if (defined(LINUX_BUILD))
        Core_Shaders.Water = LoadShader(0, TextFormat("GameAssets/Shaders/glsl%i/wave.fs", 330));
    #endif

    
    #if (defined(WINDOWS_BUILD))
        Core_Shaders.Water = LoadShader(0, TextFormat("GameAssets/Shaders/glsl%i/wave.fs", 330));
    #endif

    #if (defined(RPI_BUILD))
        Core_Shaders.Water = LoadShader(0, TextFormat("GameAssets/Shaders/glsl%i/wave.fs", 100));
    #endif
}

static void Tick_Animations(){
    MysticCoreData.Animation_Ticker += 4;
    if (MysticCoreData.Animation_Ticker == 100){
        MysticCoreData.Animation_Ticker = 0;
    }
    if (MysticCoreData.Hover_Animation_Ticker <= 0){
        MysticCoreData.Hover_Animation_DIR = 1;
    }

    if (MysticCoreData.Hover_Animation_Ticker >= 100){
        MysticCoreData.Hover_Animation_DIR = 2;
    }

    if(MysticCoreData.Hover_Animation_DIR == 1){
        MysticCoreData.Hover_Animation_Ticker ++;
    }
    if(MysticCoreData.Hover_Animation_DIR == 2){
        MysticCoreData.Hover_Animation_Ticker --;
    }
}


auto GetTile = [&](int x, int y, wstring LevelData)
{

    return LevelData[y * Level_1_Data.LevelWidth + x + MysticCamera.XOffset / 20 ];

};


auto SetTile = [&](int x, int y, wchar_t TILE)
{

    CurrentData.LevelData[y * Level_1_Data.LevelWidth + x + MysticCamera.XOffset / 20 ] = TILE;
    return 0;

};

int CheckNumberSuffix(int A, int B)
{
    string String1 = to_string(A);
    string String2 = to_string(B);
    if (String1.length() < String2.length()) {
        return false;
    }
    for (int i = 0; i < String2.length(); i++) {
        if (String1[String1.length() - i - 1]
            != String2[String2.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

static void FixPlayerY(){

    if (!CheckNumberSuffix(MysticPlayerOne.y , 4)){
        MysticPlayerOne.y ++;
    }
    
}


static void UpdatePlayer(){

    DrawText("Health", 85, 35 , 10 , RED);
    DrawRectangleLines(49,49,MysticPlayerOne.Health+2,4,WHITE);
    DrawRectangle(50,50,MysticPlayerOne.Health,2,RED);

    if (MysticCoreData.Level_ID == 30){

        if (MysticGetVirtualMouseClick(MOUSE_LEFT_BUTTON) && !MysticPlayerOne.Rocket_trigger){
            MysticPlayerOne.Rocket_trigger = true;
 

            MysticPlayerOne.Click_x = MysticGetVirtualMouseX();
            MysticPlayerOne.Click_y = MysticGetVirtualMouseY();

            MysticPlayerOne.Rocket_x = 0;
            MysticPlayerOne.Click_Timer = 0;
            
        }

        if (MysticPlayerOne.Rocket_trigger){
            for (int i = 0 ; i < 40 ; i++){

                DrawPixel(MysticPlayerOne.Click_x - i * 2 + (MysticPlayerOne.Rocket_x - i * 5) , MysticPlayerOne.Click_y , WHITE);

                DrawPixel(MysticPlayerOne.Click_x + i * 2 + (abs(MysticPlayerOne.Rocket_x) + i * 5) , MysticPlayerOne.Click_y , WHITE);

                DrawPixel(MysticPlayerOne.Click_x, MysticPlayerOne.Click_y - i * 2 + (MysticPlayerOne.Rocket_x - i * 5)  , WHITE);

                DrawPixel(MysticPlayerOne.Click_x, MysticPlayerOne.Click_y  + i * 2 + (abs(MysticPlayerOne.Rocket_x) + i * 5)  , WHITE);

                DrawPixel(MysticPlayerOne.Click_x + i * 2 + (abs(MysticPlayerOne.Rocket_x) + i * 5), MysticPlayerOne.Click_y  + i * 2 + (abs(MysticPlayerOne.Rocket_x) + i * 5)  , WHITE);

                DrawPixel(MysticPlayerOne.Click_x - i * 2 + (MysticPlayerOne.Rocket_x - i * 5) , MysticPlayerOne.Click_y - i * 2 + (MysticPlayerOne.Rocket_x - i * 5) , WHITE);

                DrawPixel(MysticPlayerOne.Click_x + i * 2 + (abs(MysticPlayerOne.Rocket_x) + i * 5), MysticPlayerOne.Click_y - i * 2 + (MysticPlayerOne.Rocket_x - i * 5) , WHITE);

                DrawPixel(MysticPlayerOne.Click_x - i * 2 + (MysticPlayerOne.Rocket_x - i * 5), MysticPlayerOne.Click_y + i * 2 + (abs(MysticPlayerOne.Rocket_x) + i * 5), WHITE);


                MysticPlayerOne.Rocket_x -= 1;



            }

            MysticPlayerOne.Click_Timer ++;
            if ( MysticPlayerOne.Click_Timer >= 80){
                MysticPlayerOne.Rocket_trigger = false;
                StopMusicStream(MysticCoreData.Kill_Sound);
            }

        }

    }
    

    

    for (int i = 0 ; i < MysticPlayerOne.Lives ; i ++ ){
        DrawText("@" , 460 + i * 20 , 35 , 20 , RED);
    }


    DrawText("@",MysticPlayerOne.x ,MysticPlayerOne.y - 80, MysticPlayerOne.Text_Size , WHITE);
    DrawText("@",MysticPlayerOne.x ,MysticPlayerOne.y - 40, MysticPlayerOne.Text_Size , BLUE);


    if (MysticControls.Shoot && MysticPlayerOne.Projectile_trigger == false && MysticPlayerOne.CanShoot){
        PlayMusicStream(MysticCoreData.Shoot_Sound);
        MysticPlayerOne.Projectile_trigger = true;
        MysticPlayerOne.Projectile_Direction = MysticPlayerOne.direction;
        if (MysticPlayerOne.direction != 4){
            MysticPlayerOne.Projectile_x = MysticPlayerOne.x+40;
            MysticPlayerOne.Projectile_y = MysticPlayerOne.y - 60;
        }
        else{
            MysticPlayerOne.Projectile_x = MysticPlayerOne.x;
            MysticPlayerOne.Projectile_y = MysticPlayerOne.y - 60;
        }

    }

    if (MysticPlayerOne.Projectile_trigger){
        UpdateMusicStream(MysticCoreData.Shoot_Sound);
        if (MysticPlayerOne.Projectile_Direction != 4){
            DrawText("->",  MysticPlayerOne.Projectile_x ,  MysticPlayerOne.Projectile_y , 20 , DARKGRAY);
            MysticPlayerOne.Projectile_x += 5;

            for (int i = 0 ; i < 10 ; i++){
                int x = i * 2 + MysticPlayerOne.Projectile_x - 35 - GetRandomValue(7, 13);
                int y = MysticPlayerOne.Projectile_y + 8 + GetRandomValue(-2, 2) ;
                DrawPixel(x , y , WHITE);
            }
        }
        else{
            MysticPlayerOne.Projectile_x -= 5;
            DrawText("<-",  MysticPlayerOne.Projectile_x ,  MysticPlayerOne.Projectile_y , 20 , DARKGRAY);
            for (int i = 0 ; i < 10 ; i++){
                int x = i * 2 + MysticPlayerOne.Projectile_x + 35 - GetRandomValue(7, 13);
                int y = MysticPlayerOne.Projectile_y + 8 + GetRandomValue(-2, 2) ;
                DrawPixel(x , y , WHITE);
            }

        }

          
        if (MysticCoreData.Animation_Ticker >= 50){
            MysticPlayerOne.Projectile_y -= 1;
        }
        else {
            MysticPlayerOne.Projectile_y += 1;
        }

        if (MysticPlayerOne.Projectile_x >= 640){
            MysticPlayerOne.Projectile_x = 0;
            MysticPlayerOne.Projectile_y = 0;
            MysticPlayerOne.Projectile_trigger = false;
            StopMusicStream(MysticCoreData.Shoot_Sound);
            StopMusicStream(MysticCoreData.Kill_Sound);
        } 

        if (MysticPlayerOne.Projectile_x <= 0){
            MysticPlayerOne.Projectile_x = 0;
            MysticPlayerOne.Projectile_y = 0;
            MysticPlayerOne.Projectile_trigger = false;
            StopMusicStream(MysticCoreData.Shoot_Sound);
            StopMusicStream(MysticCoreData.Kill_Sound);
        }


    }

    if (MysticControls.Left){

        MysticPlayerOne.Velocity_X = -1 - (MysticPlayerOne.Charge / 10);
        MysticPlayerOne.direction = 4;

        MysticPlayerOne.facing_direction = 4;
        
    }


    if (MysticControls.Right){

        MysticPlayerOne.Velocity_X = 1 + (MysticPlayerOne.Charge / 10);

        MysticPlayerOne.direction = 2;

        MysticPlayerOne.facing_direction = 2;

    }



    if (MysticControls.Right == false && MysticControls.Left == false){

        MysticPlayerOne.acceloration = 0 ;

        MysticPlayerOne.direction = 3;

        MysticPlayerOne.Velocity_X = 0;
        
        if (MysticPlayerOne.Charge != 0){
            MysticPlayerOne.Charge -= 2;
        }

    }
    else {
        if (MysticPlayerOne.Charge <= 40){
            MysticPlayerOne.Charge += 2;
        }
    }


    if (MysticPlayerOne.JumpCoolDown != 0){
        MysticPlayerOne.JumpCoolDown --;
    }

    if (MysticPlayerOne.IsJumping) {
        if (MysticPlayerOne.JumpCounter >= -10) {

            MysticPlayerOne.Velocity_Y = -(MysticPlayerOne.JumpCounter * abs(MysticPlayerOne.JumpCounter)) * .05;

            MysticPlayerOne.JumpCounter -= 1;

            for (int i = 0 ; i < 4 ; i++){
                int x = i * 2 + MysticPlayerOne.x + 27 - GetRandomValue(0, 30);
                int y = MysticPlayerOne.y + GetRandomValue(0, 20) ;
    

                DrawLine(x, y, x, y + GetRandomValue(0, 7) + MysticPlayerOne.JumpCounter , BLUE); 
            }
        }
        else {
            MysticPlayerOne.JumpCounter = 20;
            MysticPlayerOne.Velocity_Y = 0;
            MysticPlayerOne.JumpCoolDown = 40;
            StopMusicStream(MysticCoreData.Jump_Sound);
            FixPlayerY();
            MysticPlayerOne.IsJumping = false;
        }
    }

    if (MysticCamera.YOffset <= 0){
        MysticCamera.YOffset = 0;
    }

    if (MysticPlayerOne.Health <= 0){
        if (MysticPlayerOne.Lives != 0){
            for (int x = 0; x <= CurrentData.LevelWidth;  x ++ ){
                for (int y = 0; y <= 24;  y ++ ){
                    if (CurrentData.LevelData[y*CurrentData.LevelWidth+x] == L'+'){
                        MysticPlayerOne.x = x * 20;
                        MysticPlayerOne.y =  y * 20 ;
                        MysticCamera.XOffset = (MysticPlayerOne.x) - 50;
                    }
                }
            }

            int i = 0;
            for (int x = 0; x <= CurrentData.LevelWidth ;  x ++ ){
                for (int y = 0; y <= 24;  y ++ ){
                    if (CurrentData.LevelData[y*CurrentData.LevelWidth+x] == L'&'){
                        i ++;
                        MysticEnemy[i].x = x * 20;
                        MysticEnemy[i].y =  y * 20 ;
                        MysticEnemy[i].direction = 4;
                        MysticEnemy[i].JumpCount = 20;
                        if (MysticCoreData.Level_ID == 30){
                            MysticEnemy[i].health = 300;
                        }
                        else {
                            MysticEnemy[i].health = 100;
                        }
                        MysticEnemy[i].isalive = true;
                        MysticEnemy[i].DT = 0;

                    }
                }
            }
            MysticPlayerOne.Health = 100;
            MysticPlayerOne.Lives --;
        }
        else {
            MysticPlayerOne.CanShoot = false;

            MysticPlayerOne.HasRocket = false;

            MysticInit();

            InitLevelData();

            ResetLevel(Level_1_Data);

            ScanForSpawnTiles(Level_1_Data);

            ScanForEnemyTiles(Level_1_Data);

            MysticPlayerOne.Lives = 3;

            MysticPlayerOne.Health = 100;

            if (MysticCoreData.BonusMenu){
                MysticCoreData.Level_ID = 0;
            }
            else {
                MysticCoreData.Level_ID = 1;
            }
        }
    }

    MysticPlayerOne.x += MysticPlayerOne.Velocity_X;
    MysticPlayerOne.y += MysticPlayerOne.Velocity_Y;

}

int CreateCollision(int x , int y, int w , int h){

    if (GetCollision(MysticPlayerOne.x , MysticPlayerOne.y , 60,80, x,y,w,h)){
        if (MysticPlayerOne.direction == 3){
            MysticPlayerOne.Velocity_Y = 0;
            return 0;
        }
    }
    else {MysticPlayerOne.Velocity_Y = 4;}
    return 0;
}

static void UpdateEnemy(){

    for (int i = 0; i < EMC; i++)
    {
        if (MysticEnemy[i].isalive){

            if (MysticCoreData.Level_ID == 30 ){
                DrawRectangleLines(MysticEnemy[i].x  - 41, MysticEnemy[i].y - 302 - MysticCoreData.Hover_Animation_Ticker / 2 , 142 , 4 , WHITE); 
                DrawLine(MysticEnemy[i].x  - 40, MysticEnemy[i].y - 300 - MysticCoreData.Hover_Animation_Ticker / 2, MysticEnemy[i].x + MysticEnemy[i].health / 3 , MysticEnemy[i].y - 301 - MysticCoreData.Hover_Animation_Ticker / 2, RED); 
                DrawText("@", MysticEnemy[i].x , MysticEnemy[i].y - 280 - MysticCoreData.Hover_Animation_Ticker / 2, 70 , YELLOW);
                DrawText("@", MysticEnemy[i].x - 10,  MysticEnemy[i].y - 230- MysticCoreData.Hover_Animation_Ticker / 4, 100 , PURPLE);    
                
                DrawText("@", MysticEnemy[i].x + 7  , MysticEnemy[i].y - 140- MysticCoreData.Hover_Animation_Ticker / 4, 50 , VIOLET);  


                DrawText("@", MysticEnemy[i].x - 50,  MysticEnemy[i].y - 230- MysticCoreData.Hover_Animation_Ticker / 4, 50 , PURPLE);  
                DrawText("@", MysticEnemy[i].x - 90,  MysticEnemy[i].y - 190 - MysticCoreData.Hover_Animation_Ticker / 2, 50 , PURPLE);    
    
                DrawText("@", MysticEnemy[i].x + 67,  MysticEnemy[i].y - 230- MysticCoreData.Hover_Animation_Ticker / 4, 50 , PURPLE);  
                DrawText("@", MysticEnemy[i].x + 107,  MysticEnemy[i].y - 190 - MysticCoreData.Hover_Animation_Ticker / 2, 50 , PURPLE);   

                if (GetCollision(MysticPlayerOne.Click_x , MysticPlayerOne.Click_y ,5,5,MysticEnemy[i].x ,MysticEnemy[i].y - 280 - MysticCoreData.Hover_Animation_Ticker / 2, 50, 50 ) && MysticPlayerOne.Rocket_trigger) {
                    MysticEnemy[i].health -= 1;

                    PlayMusicStream(MysticCoreData.Kill_Sound);
                    DrawText("@", MysticEnemy[i].x , MysticEnemy[i].y - 280 - MysticCoreData.Hover_Animation_Ticker / 2, 70 , PINK);
                }

                if ( GetRandomValue(0, 25) == 2 && !MysticBoss.Projectile_trigger){
                    MysticBoss.Projectile_trigger = true;
                    MysticBoss.Projectile_x = MysticEnemy[i].x - 90;
                    MysticBoss.Projectile_y = MysticEnemy[i].y - 190;
                    MysticBoss.Projectile_timer = 0;
                }
                if (MysticBoss.Projectile_trigger){
                    DrawText("*" ,MysticBoss.Projectile_x ,MysticBoss.Projectile_y, 20 , PURPLE );

                    if (MysticPlayerOne.x <= MysticBoss.Projectile_x){
                        MysticBoss.Projectile_x -= 1;
                    }
                    if (MysticPlayerOne.x >= MysticBoss.Projectile_x){
                        MysticBoss.Projectile_x += 1;
                    }
                    if (MysticPlayerOne.y - 40 <= MysticBoss.Projectile_y){
                        MysticBoss.Projectile_y -= 1;
                    }
                    if (MysticPlayerOne.y - 40 >= MysticBoss.Projectile_y){
                        MysticBoss.Projectile_y += 1;
                    }


                    if (GetCollision(MysticBoss.Projectile_x ,MysticBoss.Projectile_y , 30 ,30 , MysticPlayerOne.x , MysticPlayerOne.y - 80 , 40 , 80)){
                        MysticPlayerOne.Health -= 20;
                        MysticBoss.Projectile_trigger = false;
                        DrawText("@",MysticPlayerOne.x ,MysticPlayerOne.y - 80, MysticPlayerOne.Text_Size , RED);
                        DrawText("@",MysticPlayerOne.x ,MysticPlayerOne.y - 40, MysticPlayerOne.Text_Size , BLUE);

                    }

                    MysticBoss.Projectile_timer ++;

                    if (MysticBoss.Projectile_timer >= 60*3){
                        MysticBoss.Projectile_trigger = false;
                    }


                }
            }

            if (MysticCoreData.Level_ID == 20 ){
                DrawText("@", MysticEnemy[i].x , MysticEnemy[i].y - 80, MysticPlayerOne.Text_Size , YELLOW);
                DrawText("@", MysticEnemy[i].x ,  MysticEnemy[i].y - 40, MysticPlayerOne.Text_Size , PURPLE);
            
            }else{
                if (MysticCoreData.Level_ID != 30)
                {
                    DrawText("@", MysticEnemy[i].x , MysticEnemy[i].y - 80, MysticPlayerOne.Text_Size , DARKGRAY);
                    DrawText("@", MysticEnemy[i].x ,  MysticEnemy[i].y - 40, MysticPlayerOne.Text_Size , RED);
                }
            
            }

            if (MysticCoreData.Level_ID != 30){

                if (MysticEnemy[i].direction == 2){

                    if (GetCollision(MysticPlayerOne.x, MysticPlayerOne.y , 40 , 80 , MysticEnemy[i].x , MysticEnemy[i].y , 40 ,80)){
                        MysticPlayerOne.Velocity_X = 5;
                        MysticEnemy[i].x -= 5;
                        if (MysticCoreData.Level_ID == 20){
                            MysticPlayerOne.Health -= 2;
                        }
                        else {
                            MysticPlayerOne.Health --;
                        }
                    }
                }
                if (MysticEnemy[i].direction == 4){

                    if (GetCollision(MysticPlayerOne.x, MysticPlayerOne.y , 40 , 80 , MysticEnemy[i].x , MysticEnemy[i].y , 40 ,80)){
                        MysticPlayerOne.Velocity_X = -5;
                        MysticEnemy[i].x += 5;
                        if (MysticCoreData.Level_ID == 20){
                            MysticPlayerOne.Health -= 2;
                        }
                        else {
                            MysticPlayerOne.Health --;
                        }
                    }
                }

            }

            if (MysticPlayerOne.x >= MysticEnemy[i].x ){

                MysticEnemy[i].Velocity_X = 2;
                MysticEnemy[i].direction = 2;
            }
            if (MysticPlayerOne.x <= MysticEnemy[i].x ){
                MysticEnemy[i].Velocity_X  = -2;
                MysticEnemy[i].direction = 4;
            }

            
            if( GetTile(MysticEnemy[i].x / 20 ,MysticEnemy[i].y / 20, CurrentData.LevelData) != L'0' && GetTile((MysticEnemy[i].x + 40) / 20 ,MysticEnemy[i].y / 20, CurrentData.LevelData) != L'0' && GetTile(MysticEnemy[i].x / 20 ,MysticEnemy[i].y / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 ){
                MysticEnemy[i].Velocity_Y = 0;
            }
            else {
                MysticEnemy[i].Velocity_Y = 4;
            }
            
            if( GetTile((MysticEnemy[i].x + 40) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticEnemy[i].x + 40) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticEnemy[i].x + 40) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != L'%' ){
                if (MysticEnemy[i].direction != 4){
                    MysticEnemy[i].x -= MysticEnemy[i].Velocity_X;
                    if (MysticPlayerOne.x >= 280){
                        MysticEnemy[i].x -= 4;
                    }
                }
            }

            if( GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != L'%' ){
                if (MysticEnemy[i].direction != 2){
                    MysticEnemy[i].x += abs(MysticEnemy[i].Velocity_X) ;
                }
            }
            

            if (MysticPlayerOne.y <= MysticEnemy[i].y && MysticEnemy[i].Jumper_CoolDown == 0){
                MysticEnemy[i].IsJumping = true;
            }

            if (MysticEnemy[i].IsJumping) {
                if (MysticEnemy[i].JumpCount >= -10) {
                    MysticEnemy[i].Velocity_Y = -(MysticEnemy[i].JumpCount * abs(MysticEnemy[i].JumpCount)) * .05;
                    MysticEnemy[i].JumpCount -= 1;

                }
                else {
                    MysticEnemy[i].Jumper_CoolDown = 120;
                    MysticEnemy[i].JumpCount = 20;
                    MysticEnemy[i].Velocity_Y = 0;
                    MysticEnemy[i].IsJumping = false;
                }
            }

            if (MysticEnemy[i].Jumper_CoolDown != 0){
                MysticEnemy[i].Jumper_CoolDown --;
            }

            if(MysticEnemy[i].y >= 475){
                MysticEnemy[i].health -= 5;
            }
            if(MysticEnemy[i].health <= 0 && MysticCoreData.Level_ID != 30){
                MysticEnemy[i].isalive = false;
            }
            else {
                if(MysticEnemy[i].health <= 0 && MysticCoreData.Level_ID == 30){
                    MysticEnemy[i].isalive = false;
                    MysticBoss.Alive = false;

                    // Set Bonus Flag here 
                }
            }

            if (MysticPlayerOne.x >= 280 && MysticControls.Right){
                MysticEnemy[i].x -= 5;
            }
            if (MysticPlayerOne.x <= 50 && MysticControls.Left){
                MysticEnemy[i].x += 5;
            }



            if (GetCollision(MysticEnemy[i].x , MysticEnemy[i].y - 80 , 40 , 80 , MysticPlayerOne.Projectile_x , MysticPlayerOne.Projectile_y , 20 , 20)){
                MysticEnemy[i].isalive = false;

                if (IsMusicPlaying(MysticCoreData.Kill_Sound)){
                    StopMusicStream(MysticCoreData.Kill_Sound);
                    PlayMusicStream(MysticCoreData.Kill_Sound);
                }
                else {
                    PlayMusicStream(MysticCoreData.Kill_Sound);
                }
            }

            if (MysticCoreData.Level_ID == 20){
                MysticEnemy[i].x += MysticEnemy[i].Velocity_X*2;
                MysticEnemy[i].y += MysticEnemy[i].Velocity_Y*2;
            }
            else{
                MysticEnemy[i].x += MysticEnemy[i].Velocity_X;
                MysticEnemy[i].y += MysticEnemy[i].Velocity_Y;
            }


        }
    }

}




static void UpdateTransitionTiles(){
    if( GetTile(MysticPlayerOne.x / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) == L'%'){
        switch (MysticCoreData.Level_ID){
            case 1:
                TransitionLevel( 2 , Level_2_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 2:
                TransitionLevel( 3 , Level_3_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 3:
                TransitionLevel( 4 , Level_4_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 4:
                TransitionLevel( 5 , Level_5_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 5:
                TransitionLevel( 6 , Level_6_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 6:
                TransitionLevel( 7 , Level_7_Data);
                MysticCoreData.TrackNumber = 2;
                
                break;
            case 7:
                TransitionLevel( 8 , Level_8_Data);
                MysticCoreData.TrackNumber = 3;
                break;
            case 8:
                TransitionLevel( 9 , Level_9_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 9:
                TransitionLevel( 10 , Level_10_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 10:
                TransitionLevel( 11 , Level_11_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 11:
                TransitionLevel( 12 , Level_12_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 12:
                TransitionLevel( 13 , Level_13_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 13:
                TransitionLevel( 14 , Level_14_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 14:
                TransitionLevel( 15 , Level_15_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 15:
                TransitionLevel( 16 , Level_16_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 16:
                TransitionLevel( 17 , Level_17_Data);
                MysticCoreData.TrackNumber = 3;
                break;
            case 17:
                TransitionLevel( 18 , Level_18_Data);
                MysticCoreData.TrackNumber = 3;
                break;
            case 18:
                TransitionLevel( 19 , Level_19_Data);
                MysticCoreData.TrackNumber = 3;
                break;
            case 19:
                TransitionLevel( 20 , Level_20_Data);
                MysticCoreData.TrackNumber = 5;
                break;
            case 20:
                TransitionLevel( 21 , Level_21_Data);
                MysticCoreData.TrackNumber = 3;
                break;

            case 21:
                TransitionLevel( 22 , Level_22_Data);
                MysticCoreData.TrackNumber = 2;
                break;

            case 22:
                TransitionLevel( 23 , Level_23_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 23:
                TransitionLevel( 24 , Level_24_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 24:
                TransitionLevel( 25 , Level_25_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 25:
                TransitionLevel( 26 , Level_26_Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 26:
                TransitionLevel( 27 , Level_27_Data);
                MysticCoreData.TrackNumber = 3;
                break;
            case 27:
                TransitionLevel( 28 , Level_28_Data);
                MysticCoreData.TrackNumber = 3;
                break;
            case 28:
                TransitionLevel( 29 , Level_29_Data);
                MysticCoreData.TrackNumber = 3;
                break;
            case 29:
                TransitionLevel( 30 , Level_30_Data);
                MysticCoreData.TrackNumber = 5;
                break;
            case 30:
                TransitionLevel( 30 , Level_30_Data);
                MysticCoreData.TrackNumber = 5;
                break;
            case 41:
                TransitionLevel( 0 , Level_1_Data);
                MysticCoreData.TrackNumber = 0;
                MysticPlayerOne.CanShoot = false;
                break;
        }
        if (MysticCoreData.TrackNumber == 0){
            StopMusicStream(MysticCoreData.Game_Music3);
            StopMusicStream(MysticCoreData.Game_Music2);
            StopMusicStream(MysticCoreData.Game_Music4);
            StopMusicStream(MysticCoreData.Game_Music1);
        }
        if (MysticCoreData.TrackNumber == 2){
            StopMusicStream(MysticCoreData.Game_Music3);
            StopMusicStream(MysticCoreData.Game_Music2);
            StopMusicStream(MysticCoreData.Game_Music4);
            PlayMusicStream(MysticCoreData.Game_Music1);
        }
        if (MysticCoreData.TrackNumber == 3){
            StopMusicStream(MysticCoreData.Game_Music3);
            StopMusicStream(MysticCoreData.Game_Music2);
            StopMusicStream(MysticCoreData.Game_Music4);
            PlayMusicStream(MysticCoreData.Game_Music2);
        }
        if (MysticCoreData.TrackNumber == 4){
            StopMusicStream(MysticCoreData.Game_Music1);
            StopMusicStream(MysticCoreData.Game_Music2);
            StopMusicStream(MysticCoreData.Game_Music4);

            PlayMusicStream(MysticCoreData.Game_Music3);
        }
        if (MysticCoreData.TrackNumber == 5){
            StopMusicStream(MysticCoreData.Game_Music1);
            StopMusicStream(MysticCoreData.Game_Music3);
            StopMusicStream(MysticCoreData.Game_Music2);
            StopMusicStream(MysticCoreData.Game_Music4);

            PlayMusicStream(MysticCoreData.Game_Music4);
        }

    }
}

void CustomTransition(int TrackNumber , int Id, LevelData Data ){
    for (int i = 0; i < EMC; i++)
    {
        MysticEnemy[i].x = 0;
        MysticEnemy[i].y = 0;
        MysticEnemy[i].direction = 0;
        MysticEnemy[i].JumpCount = 0;
        MysticEnemy[i].health = 0;
        MysticEnemy[i].isalive = false;
        MysticEnemy[i].DT = 0;
    }

    MysticCoreData.Level_ID = Id;
    MysticPlayerOne.Text_Size = 40;
    rlViewport(0, 0 , 640 ,500 );
    MysticPlayerOne.HeartVisable = true;

    ResetLevel(Data);
    ScanForSpawnTiles(Data);
    ScanForEnemyTiles(Data);


    MysticCoreData.CanMoveOn = false;
    MysticCoreData.TrackNumber = 2;
}