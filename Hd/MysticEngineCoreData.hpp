#include <raylib.h>
#include "MysticLevelRenderer.hpp"
#include <time.h>
#include <rlgl.h>

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
                MysticEnemy[i].Direction = 4;
                MysticEnemy[i].JumpCount = 20;
                if (MysticCoreData.LevelID == 30){
                    MysticEnemy[i].Health = 300;
                }
                else {
                    MysticEnemy[i].Health = 100;
                }
                MysticEnemy[i].IsAlive = true;
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

auto TransitionLevel( int NextLevelID , LevelData NextLevelData ){
    if (MysticCoreData.CanMoveOn){

        for (int i = 0; i < MaxEnemys; i++)
        {
            MysticEnemy[i].x = 0;
            MysticEnemy[i].y = 0;
            MysticEnemy[i].Direction = 0;
            MysticEnemy[i].JumpCount = 0;
            MysticEnemy[i].Health = 0;
            MysticEnemy[i].IsAlive = false;
            MysticEnemy[i].DT = 0;
        }

        MysticCoreData.LevelID = NextLevelID;
        MysticPlayerOne.TextSize = 40;
        rlViewport(0, 0 , 640 ,500 );
        MysticPlayerOne.HeartVisable = true;

        ResetLevel(NextLevelData);
        ScanForSpawnTiles(NextLevelData);
        ScanForEnemyTiles(NextLevelData);


        MysticCoreData.CanMoveOn = false;
    }
    else {          
        MysticPlayerOne.TextSize --; 
        MysticPlayerOne.x -= MysticPlayerOne.VelocityX;
        MysticPlayerOne.VelocityY = 0;
        MysticPlayerOne.VelocityX = 0;

        rlViewport(0, 0 ,640 + MysticPlayerOne.TextSize * 2 ,500 + MysticPlayerOne.TextSize * 2);

        if (MysticPlayerOne.TextSize == 20){
                MysticCoreData.CanMoveOn= true;
        }
    }

}

static void MysticMusicInit(){

    MysticCoreData.TitleMusic = LoadMusicStream("GameAssets/Music/Title.mp3");
    MysticCoreData.GameMusic1 = LoadMusicStream("GameAssets/Music/Music1.mp3");
    MysticCoreData.GameMusic2 = LoadMusicStream("GameAssets/Music/Music2.mp3");
    MysticCoreData.GameMusic3 = LoadMusicStream("GameAssets/Music/Music3.mp3");
    MysticCoreData.GameMusic4 = LoadMusicStream("GameAssets/Music/Music4.mp3");

}

static void MysticInit(){

    MysticCoreData.LevelID = 0;
    MysticCoreData.FPS = 60;
    MysticCoreData.GravityStrength = 5;
    MysticCoreData.Debug = true;
    MysticCoreData.AnimationTicker = 0;
    MysticCoreData.HoverAnimationTicker =0;
    MysticCoreData.HoverAnimationDirection = 2;
    MysticCoreData.LevelEditor = false;
    MysticCoreData.GameType = 1;
    MysticCoreData.LowEndHardware = false;
    MysticCoreData.CanMoveOn = false;
    MysticCoreData.BonusMenu = false;
    MysticCoreData.TrackNumber = 3;

    MysticPlayerOne.x = 50;
    MysticPlayerOne.y = 250;
    MysticPlayerOne.FacingDirection = 2;
    MysticPlayerOne.JumpCounter = 20;
    MysticPlayerOne.JumpCoolDown = 60;
    MysticPlayerOne.ProjectileX = 0;
    MysticPlayerOne.ProjectileY = 0;
    MysticPlayerOne.ProjectileTrigger = false;
    MysticPlayerOne.ProjectileDirection = 2;
    MysticPlayerOne.TextSize = 40;
    MysticPlayerOne.Charge = 0;
    MysticPlayerOne.Lives = 4;
    MysticPlayerOne.HeartVisable = true;

    MysticCamera.XOffset = 0;
    MysticCamera.YOffset = 0;

    MysticControls.Right = false;
    MysticControls.Left = false;
    MysticControls.Up = false;
    MysticControls.Shoot = false;

    MysticBoss.Alive = true;

    
    MysticBoss.ProjectileX = 0;
    MysticBoss.ProjectileY = 0;
    MysticBoss.ProjectileTrigger = false;


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

        if (MysticCoreData.LevelID >= 1 && MysticCoreData.LevelID <= 29){
            MysticControls.VirtualMouseEnabled = false;
        }
        else {
            MysticControls.VirtualMouseEnabled = true;
        }

    }
}

static void TickAnimations(){
    MysticCoreData.AnimationTicker += 4;
    if (MysticCoreData.AnimationTicker == 100){
        MysticCoreData.AnimationTicker = 0;
    }
    if (MysticCoreData.HoverAnimationTicker <= 0){
        MysticCoreData.HoverAnimationDirection = 1;
    }

    if (MysticCoreData.HoverAnimationTicker >= 100){
        MysticCoreData.HoverAnimationDirection = 2;
    }

    if(MysticCoreData.HoverAnimationDirection == 1){
        MysticCoreData.HoverAnimationTicker ++;
    }
    if(MysticCoreData.HoverAnimationDirection == 2){
        MysticCoreData.HoverAnimationTicker --;
    }
}

auto GetTile(int x, int y, wstring LevelData){

    return LevelData[y * Level1Data.LevelWidth + x + MysticCamera.XOffset / 20 ];

}

auto SetTile(int x, int y, wchar_t TILE){

    CurrentData.LevelData[y * Level1Data.LevelWidth + x + MysticCamera.XOffset / 20 ] = TILE;
    return 0;

}

// For Y Value Hack
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

// Quick Y Player Value Fix Hack 
static void FixPlayerY(){

    if (!CheckNumberSuffix(MysticPlayerOne.y , 4)){
        MysticPlayerOne.y ++;
    }
    
}

// Updates Player
static void UpdatePlayer(){

    DrawText("Health", 85, 35 , 10 , RED);
    DrawRectangleLines(49,49,MysticPlayerOne.Health+2,4,WHITE);
    DrawRectangle(50,50,MysticPlayerOne.Health,2,RED);

    if (MysticCoreData.LevelID == 30){

        if (MysticGetVirtualMouseClick(MOUSE_LEFT_BUTTON) && !MysticPlayerOne.RocketTrigger){
            MysticPlayerOne.RocketTrigger = true;
 

            MysticPlayerOne.ClickX = MysticGetVirtualMouseX();
            MysticPlayerOne.ClickY = MysticGetVirtualMouseY();

            MysticPlayerOne.RocketX = 0;
            MysticPlayerOne.ClickTimer = 0;
            
        }

        if (MysticPlayerOne.RocketTrigger){
            for (int i = 0 ; i < 40 ; i++){

                DrawPixel(MysticPlayerOne.ClickX - i * 2 + (MysticPlayerOne.RocketX - i * 5) , MysticPlayerOne.ClickY , WHITE);

                DrawPixel(MysticPlayerOne.ClickX + i * 2 + (abs(MysticPlayerOne.RocketX) + i * 5) , MysticPlayerOne.ClickY , WHITE);

                DrawPixel(MysticPlayerOne.ClickX, MysticPlayerOne.ClickY - i * 2 + (MysticPlayerOne.RocketX - i * 5)  , WHITE);

                DrawPixel(MysticPlayerOne.ClickX, MysticPlayerOne.ClickY  + i * 2 + (abs(MysticPlayerOne.RocketX) + i * 5)  , WHITE);

                DrawPixel(MysticPlayerOne.ClickX + i * 2 + (abs(MysticPlayerOne.RocketX) + i * 5), MysticPlayerOne.ClickY  + i * 2 + (abs(MysticPlayerOne.RocketX) + i * 5)  , WHITE);

                DrawPixel(MysticPlayerOne.ClickX - i * 2 + (MysticPlayerOne.RocketX - i * 5) , MysticPlayerOne.ClickY - i * 2 + (MysticPlayerOne.RocketX - i * 5) , WHITE);

                DrawPixel(MysticPlayerOne.ClickX + i * 2 + (abs(MysticPlayerOne.RocketX) + i * 5), MysticPlayerOne.ClickY - i * 2 + (MysticPlayerOne.RocketX - i * 5) , WHITE);

                DrawPixel(MysticPlayerOne.ClickX - i * 2 + (MysticPlayerOne.RocketX - i * 5), MysticPlayerOne.ClickY + i * 2 + (abs(MysticPlayerOne.RocketX) + i * 5), WHITE);


                MysticPlayerOne.RocketX -= 1;



            }

            MysticPlayerOne.ClickTimer ++;
            if ( MysticPlayerOne.ClickTimer >= 80){
                MysticPlayerOne.RocketTrigger = false;
                StopMusicStream(MysticCoreData.KillSound);
            }

        }

    }
    

    

    for (int i = 0 ; i < MysticPlayerOne.Lives ; i ++ ){
        DrawText("@" , 460 + i * 20 , 35 , 20 , RED);
    }


    DrawText("@",MysticPlayerOne.x ,MysticPlayerOne.y - 80, MysticPlayerOne.TextSize , WHITE);
    DrawText("@",MysticPlayerOne.x ,MysticPlayerOne.y - 40, MysticPlayerOne.TextSize , BLUE);


    if (MysticControls.Shoot && MysticPlayerOne.ProjectileTrigger == false && MysticPlayerOne.CanShoot){
        PlayMusicStream(MysticCoreData.ShootSound);
        MysticPlayerOne.ProjectileTrigger = true;
        MysticPlayerOne.ProjectileDirection = MysticPlayerOne.Direction;
        if (MysticPlayerOne.Direction != 4){
            MysticPlayerOne.ProjectileX = MysticPlayerOne.x+40;
            MysticPlayerOne.ProjectileY = MysticPlayerOne.y - 60;
        }
        else{
            MysticPlayerOne.ProjectileX = MysticPlayerOne.x;
            MysticPlayerOne.ProjectileY = MysticPlayerOne.y - 60;
        }

    }

    if (MysticPlayerOne.ProjectileTrigger){
        UpdateMusicStream(MysticCoreData.ShootSound);
        if (MysticPlayerOne.ProjectileDirection != 4){
            DrawText("->",  MysticPlayerOne.ProjectileX ,  MysticPlayerOne.ProjectileY , 20 , DARKGRAY);
            MysticPlayerOne.ProjectileX += 5;

            for (int i = 0 ; i < 10 ; i++){
                int x = i * 2 + MysticPlayerOne.ProjectileX - 35 - GetRandomValue(7, 13);
                int y = MysticPlayerOne.ProjectileY + 8 + GetRandomValue(-2, 2) ;
                DrawPixel(x , y , WHITE);
            }
        }
        else{
            MysticPlayerOne.ProjectileX -= 5;
            DrawText("<-",  MysticPlayerOne.ProjectileX ,  MysticPlayerOne.ProjectileY , 20 , DARKGRAY);
            for (int i = 0 ; i < 10 ; i++){
                int x = i * 2 + MysticPlayerOne.ProjectileX + 35 - GetRandomValue(7, 13);
                int y = MysticPlayerOne.ProjectileY + 8 + GetRandomValue(-2, 2) ;
                DrawPixel(x , y , WHITE);
            }

        }

          
        if (MysticCoreData.AnimationTicker >= 50){
            MysticPlayerOne.ProjectileY -= 1;
        }
        else {
            MysticPlayerOne.ProjectileY += 1;
        }

        if (MysticPlayerOne.ProjectileX >= 640){
            MysticPlayerOne.ProjectileX = 0;
            MysticPlayerOne.ProjectileY = 0;
            MysticPlayerOne.ProjectileTrigger = false;
            StopMusicStream(MysticCoreData.ShootSound);
            StopMusicStream(MysticCoreData.KillSound);
        } 

        if (MysticPlayerOne.ProjectileX <= 0){
            MysticPlayerOne.ProjectileX = 0;
            MysticPlayerOne.ProjectileY = 0;
            MysticPlayerOne.ProjectileTrigger = false;
            StopMusicStream(MysticCoreData.ShootSound);
            StopMusicStream(MysticCoreData.KillSound);
        }


    }

    if (MysticControls.Left){

        MysticPlayerOne.VelocityX = -1 - (MysticPlayerOne.Charge / 10);
        MysticPlayerOne.Direction = 4;

        MysticPlayerOne.FacingDirection = 4;
        
    }


    if (MysticControls.Right){

        MysticPlayerOne.VelocityX = 1 + (MysticPlayerOne.Charge / 10);

        MysticPlayerOne.Direction = 2;

        MysticPlayerOne.FacingDirection = 2;

    }



    if (MysticControls.Right == false && MysticControls.Left == false){

        MysticPlayerOne.Acceloration = 0 ;

        MysticPlayerOne.Direction = 3;

        MysticPlayerOne.VelocityX = 0;
        
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

            MysticPlayerOne.VelocityY = -(MysticPlayerOne.JumpCounter * abs(MysticPlayerOne.JumpCounter)) * .05;

            MysticPlayerOne.JumpCounter -= 1;

            for (int i = 0 ; i < 4 ; i++){
                int x = i * 2 + MysticPlayerOne.x + 27 - GetRandomValue(0, 30);
                int y = MysticPlayerOne.y + GetRandomValue(0, 20) ;
    

                DrawLine(x, y, x, y + GetRandomValue(0, 7) + MysticPlayerOne.JumpCounter , BLUE); 
            }
        }
        else {
            MysticPlayerOne.JumpCounter = 20;
            MysticPlayerOne.VelocityY = 0;
            MysticPlayerOne.JumpCoolDown = 40;
            StopMusicStream(MysticCoreData.JumpSound);
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
                        MysticEnemy[i].Direction = 4;
                        MysticEnemy[i].JumpCount = 20;
                        if (MysticCoreData.LevelID == 30){
                            MysticEnemy[i].Health = 300;
                        }
                        else {
                            MysticEnemy[i].Health = 100;
                        }
                        MysticEnemy[i].IsAlive = true;
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

            ResetLevel(Level1Data);

            ScanForSpawnTiles(Level1Data);

            ScanForEnemyTiles(Level1Data);

            MysticPlayerOne.Lives = 3;

            MysticPlayerOne.Health = 100;

            if (MysticCoreData.BonusMenu){
                MysticCoreData.LevelID = 0;
            }
            else {
                MysticCoreData.LevelID = 1;
            }
        }
    }

    MysticPlayerOne.x += MysticPlayerOne.VelocityX;
    MysticPlayerOne.y += MysticPlayerOne.VelocityY;

}

// ???
int CreateCollision(int x , int y, int w , int h){
    if (GetCollision(MysticPlayerOne.x , MysticPlayerOne.y , 60,80, x,y,w,h)){
        if (MysticPlayerOne.Direction == 3){
            MysticPlayerOne.VelocityY = 0;
            return 0;
        }
    }
    else {MysticPlayerOne.VelocityY = 4;}
    return 0;
}

// Updates Enemys
static void UpdateEnemy(){

    for (int i = 0; i < MaxEnemys; i++)
    {
        if (MysticEnemy[i].IsAlive){

            if (MysticCoreData.LevelID == 30 ){
                DrawRectangleLines(MysticEnemy[i].x  - 41, MysticEnemy[i].y - 302 - MysticCoreData.HoverAnimationTicker / 2 , 142 , 4 , WHITE); 
                DrawLine(MysticEnemy[i].x  - 40, MysticEnemy[i].y - 300 - MysticCoreData.HoverAnimationTicker / 2, MysticEnemy[i].x + MysticEnemy[i].Health / 3 , MysticEnemy[i].y - 301 - MysticCoreData.HoverAnimationTicker / 2, RED); 
                DrawText("@", MysticEnemy[i].x , MysticEnemy[i].y - 280 - MysticCoreData.HoverAnimationTicker / 2, 70 , YELLOW);
                DrawText("@", MysticEnemy[i].x - 10,  MysticEnemy[i].y - 230- MysticCoreData.HoverAnimationTicker / 4, 100 , PURPLE);    
                
                DrawText("@", MysticEnemy[i].x + 7  , MysticEnemy[i].y - 140- MysticCoreData.HoverAnimationTicker / 4, 50 , VIOLET);  


                DrawText("@", MysticEnemy[i].x - 50,  MysticEnemy[i].y - 230- MysticCoreData.HoverAnimationTicker / 4, 50 , PURPLE);  
                DrawText("@", MysticEnemy[i].x - 90,  MysticEnemy[i].y - 190 - MysticCoreData.HoverAnimationTicker / 2, 50 , PURPLE);    
    
                DrawText("@", MysticEnemy[i].x + 67,  MysticEnemy[i].y - 230- MysticCoreData.HoverAnimationTicker / 4, 50 , PURPLE);  
                DrawText("@", MysticEnemy[i].x + 107,  MysticEnemy[i].y - 190 - MysticCoreData.HoverAnimationTicker / 2, 50 , PURPLE);   

                if (GetCollision(MysticPlayerOne.ClickX , MysticPlayerOne.ClickY ,5,5,MysticEnemy[i].x ,MysticEnemy[i].y - 280 - MysticCoreData.HoverAnimationTicker / 2, 50, 50 ) && MysticPlayerOne.RocketTrigger) {
                    MysticEnemy[i].Health -= 1;

                    PlayMusicStream(MysticCoreData.KillSound);
                    DrawText("@", MysticEnemy[i].x , MysticEnemy[i].y - 280 - MysticCoreData.HoverAnimationTicker / 2, 70 , PINK);
                }

                if ( GetRandomValue(0, 25) == 2 && !MysticBoss.ProjectileTrigger){
                    MysticBoss.ProjectileTrigger = true;
                    MysticBoss.ProjectileX = MysticEnemy[i].x - 90;
                    MysticBoss.ProjectileY = MysticEnemy[i].y - 190;
                    MysticBoss.ProjectileTimer = 0;
                }
                if (MysticBoss.ProjectileTrigger){
                    DrawText("*" ,MysticBoss.ProjectileX ,MysticBoss.ProjectileY, 20 , PURPLE );

                    if (MysticPlayerOne.x <= MysticBoss.ProjectileX){
                        MysticBoss.ProjectileX -= 1;
                    }
                    if (MysticPlayerOne.x >= MysticBoss.ProjectileX){
                        MysticBoss.ProjectileX += 1;
                    }
                    if (MysticPlayerOne.y - 40 <= MysticBoss.ProjectileY){
                        MysticBoss.ProjectileY -= 1;
                    }
                    if (MysticPlayerOne.y - 40 >= MysticBoss.ProjectileY){
                        MysticBoss.ProjectileY += 1;
                    }


                    if (GetCollision(MysticBoss.ProjectileX ,MysticBoss.ProjectileY , 30 ,30 , MysticPlayerOne.x , MysticPlayerOne.y - 80 , 40 , 80)){
                        MysticPlayerOne.Health -= 20;
                        MysticBoss.ProjectileTrigger = false;
                        DrawText("@",MysticPlayerOne.x ,MysticPlayerOne.y - 80, MysticPlayerOne.TextSize , RED);
                        DrawText("@",MysticPlayerOne.x ,MysticPlayerOne.y - 40, MysticPlayerOne.TextSize , BLUE);

                    }

                    MysticBoss.ProjectileTimer ++;

                    if (MysticBoss.ProjectileTimer >= 60*3){
                        MysticBoss.ProjectileTrigger = false;
                    }


                }
            }

            if (MysticCoreData.LevelID == 20 ){
                DrawText("@", MysticEnemy[i].x , MysticEnemy[i].y - 80, MysticPlayerOne.TextSize , YELLOW);
                DrawText("@", MysticEnemy[i].x ,  MysticEnemy[i].y - 40, MysticPlayerOne.TextSize , PURPLE);
            
            }else{
                if (MysticCoreData.LevelID != 30)
                {
                    DrawText("@", MysticEnemy[i].x , MysticEnemy[i].y - 80, MysticPlayerOne.TextSize , DARKGRAY);
                    DrawText("@", MysticEnemy[i].x ,  MysticEnemy[i].y - 40, MysticPlayerOne.TextSize , RED);
                }
            
            }

            if (MysticCoreData.LevelID != 30){

                if (MysticEnemy[i].Direction == 2){

                    if (GetCollision(MysticPlayerOne.x, MysticPlayerOne.y , 40 , 80 , MysticEnemy[i].x , MysticEnemy[i].y , 40 ,80)){
                        MysticPlayerOne.VelocityX = 5;
                        MysticEnemy[i].x -= 5;
                        if (MysticCoreData.LevelID == 20){
                            MysticPlayerOne.Health -= 2;
                        }
                        else {
                            MysticPlayerOne.Health --;
                        }
                    }
                }
                if (MysticEnemy[i].Direction == 4){

                    if (GetCollision(MysticPlayerOne.x, MysticPlayerOne.y , 40 , 80 , MysticEnemy[i].x , MysticEnemy[i].y , 40 ,80)){
                        MysticPlayerOne.VelocityX = -5;
                        MysticEnemy[i].x += 5;
                        if (MysticCoreData.LevelID == 20){
                            MysticPlayerOne.Health -= 2;
                        }
                        else {
                            MysticPlayerOne.Health --;
                        }
                    }
                }

            }

            if (MysticPlayerOne.x >= MysticEnemy[i].x ){

                MysticEnemy[i].VelocityX = 2;
                MysticEnemy[i].Direction = 2;
            }
            if (MysticPlayerOne.x <= MysticEnemy[i].x ){
                MysticEnemy[i].VelocityX  = -2;
                MysticEnemy[i].Direction = 4;
            }

            
            if( GetTile(MysticEnemy[i].x / 20 ,MysticEnemy[i].y / 20, CurrentData.LevelData) != L'0' && GetTile((MysticEnemy[i].x + 40) / 20 ,MysticEnemy[i].y / 20, CurrentData.LevelData) != L'0' && GetTile(MysticEnemy[i].x / 20 ,MysticEnemy[i].y / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 ){
                MysticEnemy[i].VelocityY = 0;
            }
            else {
                MysticEnemy[i].VelocityY = 4;
            }
            
            if( GetTile((MysticEnemy[i].x + 40) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticEnemy[i].x + 40) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticEnemy[i].x + 40) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != L'%' ){
                if (MysticEnemy[i].Direction != 4){
                    MysticEnemy[i].x -= MysticEnemy[i].VelocityX;
                    if (MysticPlayerOne.x >= 280){
                        MysticEnemy[i].x -= 4;
                    }
                }
            }

            if( GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != L'0' && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock1 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock2 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock3 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != CurrentData.LevelNonCollisionBlock4 && GetTile((MysticEnemy[i].x + 20) / 20 ,(MysticEnemy[i].y - 20) / 20, CurrentData.LevelData) != L'%' ){
                if (MysticEnemy[i].Direction != 2){
                    MysticEnemy[i].x += abs(MysticEnemy[i].VelocityX) ;
                }
            }
            

            if (MysticPlayerOne.y <= MysticEnemy[i].y && MysticEnemy[i].JumperCoolDown == 0){
                MysticEnemy[i].IsJumping = true;
            }

            if (MysticEnemy[i].IsJumping) {
                if (MysticEnemy[i].JumpCount >= -10) {
                    MysticEnemy[i].VelocityY = -(MysticEnemy[i].JumpCount * abs(MysticEnemy[i].JumpCount)) * .05;
                    MysticEnemy[i].JumpCount -= 1;

                }
                else {
                    MysticEnemy[i].JumperCoolDown = 120;
                    MysticEnemy[i].JumpCount = 20;
                    MysticEnemy[i].VelocityY = 0;
                    MysticEnemy[i].IsJumping = false;
                }
            }

            if (MysticEnemy[i].JumperCoolDown != 0){
                MysticEnemy[i].JumperCoolDown --;
            }

            if(MysticEnemy[i].y >= 475){
                MysticEnemy[i].Health -= 5;
            }
            if(MysticEnemy[i].Health <= 0 && MysticCoreData.LevelID != 30){
                MysticEnemy[i].IsAlive = false;
            }
            else {
                if(MysticEnemy[i].Health <= 0 && MysticCoreData.LevelID == 30){
                    MysticEnemy[i].IsAlive = false;
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



            if (GetCollision(MysticEnemy[i].x , MysticEnemy[i].y - 80 , 40 , 80 , MysticPlayerOne.ProjectileX , MysticPlayerOne.ProjectileY , 20 , 20)){
                MysticEnemy[i].IsAlive = false;

                //if (IsMusicPlaying(MysticCoreData.KillSound)){
                //    StopMusicStream(MysticCoreData.KillSound);
                //    PlayMusicStream(MysticCoreData.KillSound);
                //}
                //else {
                //    PlayMusicStream(MysticCoreData.KillSound);
                //}
            }

            if (MysticCoreData.LevelID == 20){
                MysticEnemy[i].x += MysticEnemy[i].VelocityX*2;
                MysticEnemy[i].y += MysticEnemy[i].VelocityY*2;
            }
            else{
                MysticEnemy[i].x += MysticEnemy[i].VelocityX;
                MysticEnemy[i].y += MysticEnemy[i].VelocityY;
            }


        }
    }

}

// Master List of all Transitions
static void UpdateTransitionTiles(){
    if( GetTile(MysticPlayerOne.x / 20 ,(MysticPlayerOne.y - 20) / 20, CurrentData.LevelData) == L'%'){
        switch (MysticCoreData.LevelID){
            case 1:
                TransitionLevel( 2 , Level2Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 2:
                TransitionLevel( 3 , Level3Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 3:
                TransitionLevel( 4 , Level4Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 4:
                TransitionLevel( 5 , Level5Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 5:
                TransitionLevel( 6 , Level6Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 6:
                TransitionLevel( 7 , Level7Data);
                MysticCoreData.TrackNumber = 2;
                
                break;
            case 7:
                TransitionLevel( 8 , Level8Data);
                MysticCoreData.TrackNumber = 3;
                break;
            case 8:
                TransitionLevel( 9 , Level9Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 9:
                TransitionLevel( 10 , Level10Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 10:
                TransitionLevel( 11 , Level11Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 11:
                TransitionLevel( 12 , Level12Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 12:
                TransitionLevel( 13 , Level13Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 13:
                TransitionLevel( 14 , Level14Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 14:
                TransitionLevel( 15 , Level15Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 15:
                TransitionLevel( 16 , Level16Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 16:
                TransitionLevel( 17 , Level17Data);
                MysticCoreData.TrackNumber = 3;
                break;
            case 17:
                TransitionLevel( 18 , Level18Data);
                MysticCoreData.TrackNumber = 3;
                break;
            case 18:
                TransitionLevel( 19 , Level19Data);
                MysticCoreData.TrackNumber = 3;
                break;
            case 19:
                TransitionLevel( 20 , Level20Data);
                MysticCoreData.TrackNumber = 5;
                break;
            case 20:
                TransitionLevel( 21 , Level21Data);
                MysticCoreData.TrackNumber = 3;
                break;

            case 21:
                TransitionLevel( 22 , Level22Data);
                MysticCoreData.TrackNumber = 2;
                break;

            case 22:
                TransitionLevel( 23 , Level23Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 23:
                TransitionLevel( 24 , Level24Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 24:
                TransitionLevel( 25 , Level25Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 25:
                TransitionLevel( 26 , Level26Data);
                MysticCoreData.TrackNumber = 2;
                break;
            case 26:
                TransitionLevel( 27 , Level27Data);
                MysticCoreData.TrackNumber = 3;
                break;
            case 27:
                TransitionLevel( 28 , Level28Data);
                MysticCoreData.TrackNumber = 3;
                break;
            case 28:
                TransitionLevel( 29 , Level29Data);
                MysticCoreData.TrackNumber = 3;
                break;
            case 29:
                TransitionLevel( 30 , Level30Data);
                MysticCoreData.TrackNumber = 5;
                break;
            case 30:
                TransitionLevel( 30 , Level30Data);
                MysticCoreData.TrackNumber = 5;
                break;
            case 41:
                TransitionLevel( 0 , Level1Data);
                MysticCoreData.TrackNumber = 0;
                MysticPlayerOne.CanShoot = false;
                break;
        }
        if (MysticCoreData.TrackNumber == 0){
            StopMusicStream(MysticCoreData.GameMusic3);
            StopMusicStream(MysticCoreData.GameMusic2);
            StopMusicStream(MysticCoreData.GameMusic4);
            StopMusicStream(MysticCoreData.GameMusic1);
        }
        if (MysticCoreData.TrackNumber == 2){
            StopMusicStream(MysticCoreData.GameMusic3);
            StopMusicStream(MysticCoreData.GameMusic2);
            StopMusicStream(MysticCoreData.GameMusic4);
            PlayMusicStream(MysticCoreData.GameMusic1);
        }
        if (MysticCoreData.TrackNumber == 3){
            StopMusicStream(MysticCoreData.GameMusic3);
            StopMusicStream(MysticCoreData.GameMusic2);
            StopMusicStream(MysticCoreData.GameMusic4);
            PlayMusicStream(MysticCoreData.GameMusic2);
        }
        if (MysticCoreData.TrackNumber == 4){
            StopMusicStream(MysticCoreData.GameMusic1);
            StopMusicStream(MysticCoreData.GameMusic2);
            StopMusicStream(MysticCoreData.GameMusic4);

            PlayMusicStream(MysticCoreData.GameMusic3);
        }
        if (MysticCoreData.TrackNumber == 5){
            StopMusicStream(MysticCoreData.GameMusic1);
            StopMusicStream(MysticCoreData.GameMusic3);
            StopMusicStream(MysticCoreData.GameMusic2);
            StopMusicStream(MysticCoreData.GameMusic4);

            PlayMusicStream(MysticCoreData.GameMusic4);
        }

    }
}

// Used for Bonus Levels 
void CustomTransition(int TrackNumber , int Id, LevelData Data ){

    for (int i = 0; i < MaxEnemys; i++)
    {
        MysticEnemy[i].x = 0;
        MysticEnemy[i].y = 0;
        MysticEnemy[i].Direction = 0;
        MysticEnemy[i].JumpCount = 0;
        MysticEnemy[i].Health = 0;
        MysticEnemy[i].IsAlive = false;
        MysticEnemy[i].DT = 0;
    }

    MysticCoreData.LevelID = Id;
    MysticPlayerOne.TextSize = 40;
    rlViewport(0, 0 , 640 ,500 );
    MysticPlayerOne.HeartVisable = true;

    ResetLevel(Data);
    ScanForSpawnTiles(Data);
    ScanForEnemyTiles(Data);

    MysticCoreData.CanMoveOn = false;
    MysticCoreData.TrackNumber = 2;
}
