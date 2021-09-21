#include <string>
#include <fstream>
#include <iostream>
//#include "MysticParticles.hpp"

using namespace std;


typedef struct MCurrentData{

    wstring LevelData;

    int LevelWidth;

    int LevelHeight;

    wchar_t LevelNonCollisionBlock1;
    wchar_t LevelNonCollisionBlock2;
    wchar_t LevelNonCollisionBlock3;
    wchar_t LevelNonCollisionBlock4;

    Music Song;

}MCurrentData;

static MCurrentData CurrentData;

typedef struct GameData{
    int Level_ID;
    int FPS;
    int Animation_Ticker;
    int Debug;
    int Hover_Animation_Ticker;
    int Hover_Animation_DIR;
    int GameType;
    int Gravity_Strength;
    int BreakTimer;
    int CanMoveOn;
    int TrackNumber;
    int LowEndHardware;
    Shader shader;
    Music Title_Music;
    Music Game_Music1;
    Music Game_Music2;
    Music Game_Music3;
    Music Game_Music4;

    Music Kill_Sound;
    Music Shoot_Sound;
    Music Jump_Sound;
}GameData;

static GameData MysticCoreData;

typedef struct MCamera{
    int XOffset;
    int YOffset;
    int Background_Parrallax_X_1;
    int Background_Parrallax_X_2;
    int Background_Parrallax_X_3;
}MCamera;

static MCamera MysticCamera;


typedef struct LevelData{
    wstring Data;
    int LevelHeight;
    int LevelWidth;
    int VisableTiles;
    bool IsOptimized;

    wchar_t NonCollisionBlock1;
    wchar_t NonCollisionBlock2;
    wchar_t NonCollisionBlock3;
    wchar_t NonCollisionBlock4;
    wchar_t ShaderBlock1;
    wchar_t ShaderBlock2;
    wchar_t ShaderBlock3;
    wchar_t ShaderBlock4;

    Music Music_1;



}LevelData;

static LevelData Level_1_Data;

static LevelData Level_2_Data;

static LevelData Level_3_Data;

static LevelData Level_4_Data;

static LevelData Level_5_Data;

static LevelData Level_6_Data;

static LevelData Level_7_Data;

static LevelData Level_8_Data;

static LevelData Level_9_Data;

static LevelData Level_10_Data;

static LevelData Level_11_Data;

static LevelData Level_12_Data;

static LevelData Level_13_Data;

static LevelData Level_14_Data;

static LevelData Level_15_Data;

static LevelData Level_16_Data;

static LevelData Level_17_Data;

static LevelData Level_18_Data;

static LevelData Level_19_Data;

static LevelData Level_20_Data;

static LevelData Level_21_Data;

static LevelData Level_22_Data;

static LevelData Level_23_Data;

static LevelData Level_24_Data;

static LevelData Level_25_Data;

static LevelData Level_26_Data;

static LevelData Level_27_Data;

static LevelData Level_28_Data;

static LevelData Level_29_Data;

static LevelData Level_30_Data;


typedef struct MShaders{
    Shader Water;
    Shader General;

}MShaders;

static MShaders Core_Shaders;



wstring LoadFile(const char *PATH){
    wstring Data;

    wifstream outfile;

    outfile.open(PATH);

    outfile >> Data;

    return Data;

}
       

wchar_t LoadMconfFile(const char *PATH){
    wchar_t Data;

    wifstream outfile;

    outfile.open(PATH);

    outfile >> Data;

    return Data;

}


static void InitLevelData(){

    MysticCoreData.Kill_Sound = LoadMusicStream("GameAssets/Sound/Kill.mp3");
    MysticCoreData.Shoot_Sound = LoadMusicStream("GameAssets/Sound/Shoot.mp3");
    MysticCoreData.Jump_Sound = LoadMusicStream("GameAssets/Sound/Jump.mp3");


    Level_1_Data.LevelWidth = 512;

    Level_1_Data.LevelHeight = 24;
    Level_1_Data.VisableTiles = 32;

    // Shader MConfs
    Level_1_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_1_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_1_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_1_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_1_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_1_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_1_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_1_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_1_Data.Data  = LoadFile("LevelData/Level_1/Level_1.mpak");


    Level_2_Data.LevelWidth = 512;

    Level_2_Data.LevelHeight = 24;
    Level_2_Data.VisableTiles = 32;

    // Shader MConfs
    Level_2_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_2_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_2_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_2_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_2_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_2_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_2_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_2_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_2_Data.Data  = LoadFile("LevelData/Level_2/Level_2.mpak");

    

    Level_3_Data.LevelWidth = 512;

    Level_3_Data.LevelHeight = 24;
    Level_3_Data.VisableTiles = 32;

    // Shader MConfs
    Level_3_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_3_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_3_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_3_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_3_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_3_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_3_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_3_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_3_Data.Data  = LoadFile("LevelData/Level_3/Level_3.mpak");

    Level_4_Data.LevelWidth = 512;

    Level_4_Data.LevelHeight = 24;
    Level_4_Data.VisableTiles = 32;

    // Shader MConfs
    Level_4_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_4_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_4_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_4_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_4_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_4_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_4_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_4_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_4_Data.Data  = LoadFile("LevelData/Level_4/Level_4.mpak");

    Level_5_Data.LevelWidth = 512;

    Level_5_Data.LevelHeight = 24;
    Level_5_Data.VisableTiles = 32;

    // Shader MConfs
    Level_5_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_5_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_5_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_5_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_5_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_5_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_5_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_5_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_5_Data.Data  = LoadFile("LevelData/Level_5/Level_5.mpak");

    Level_6_Data.LevelWidth = 512;

    Level_6_Data.LevelHeight = 24;
    Level_6_Data.VisableTiles = 32;

    // Shader MConfs
    Level_6_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_6_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_6_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_6_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_6_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_6_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_6_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_6_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_6_Data.Data  = LoadFile("LevelData/Level_6/Level_6.mpak");

    Level_7_Data.LevelWidth = 512;

    Level_7_Data.LevelHeight = 24;
    Level_7_Data.VisableTiles = 32;

    // Shader MConfs
    Level_7_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_7_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_7_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_7_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_7_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_7_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_7_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_7_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_7_Data.Data  = LoadFile("LevelData/Level_7/Level_7.mpak");

    Level_8_Data.LevelWidth = 512;

    Level_8_Data.LevelHeight = 24;
    Level_8_Data.VisableTiles = 32;

    // Shader MConfs
    Level_8_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_8_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_8_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_8_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_8_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_8_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_8_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_8_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_8_Data.Data  = LoadFile("LevelData/Level_8/Level_8.mpak");

    Level_9_Data.LevelWidth = 512;

    Level_9_Data.LevelHeight = 24;
    Level_9_Data.VisableTiles = 32;

    // Shader MConfs
    Level_9_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_9_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_9_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_9_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_9_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_9_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_9_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_9_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_9_Data.Data  = LoadFile("LevelData/Level_9/Level_9.mpak");
    
    Level_10_Data.LevelWidth = 512;

    Level_10_Data.LevelHeight = 24;
    Level_10_Data.VisableTiles = 32;

    // Shader MConfs
    Level_10_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_10_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_10_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_10_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_10_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_10_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_10_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_10_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_10_Data.Data  = LoadFile("LevelData/Level_10/Level_10.mpak");

    Level_10_Data.LevelWidth = 512;

    Level_10_Data.LevelHeight = 24;
    Level_10_Data.VisableTiles = 32;

    // Shader MConfs
    Level_10_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_10_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_10_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_10_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_10_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_10_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_10_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_10_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_10_Data.Data  = LoadFile("LevelData/Level_10/Level_10.mpak");

    Level_11_Data.LevelWidth = 512;

    Level_11_Data.LevelHeight = 24;
    Level_11_Data.VisableTiles = 32;

    // Shader MConfs
    Level_11_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_11_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_11_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_11_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_11_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_11_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_11_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_11_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_11_Data.Data  = LoadFile("LevelData/Level_11/Level_11.mpak");


    Level_12_Data.LevelWidth = 512;

    Level_12_Data.LevelHeight = 24;
    Level_12_Data.VisableTiles = 32;

    // Shader MConfs
    Level_12_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_12_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_12_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_12_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_12_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_12_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_12_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_12_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_12_Data.Data  = LoadFile("LevelData/Level_12/Level_12.mpak");

    Level_13_Data.LevelWidth = 512;

    Level_13_Data.LevelHeight = 24;
    Level_13_Data.VisableTiles = 32;

    // Shader MConfs
    Level_13_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_13_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_13_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_13_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_13_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_13_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_13_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_13_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_13_Data.Data  = LoadFile("LevelData/Level_13/Level_13.mpak");

    Level_14_Data.LevelWidth = 512;

    Level_14_Data.LevelHeight = 24;
    Level_14_Data.VisableTiles = 32;

    // Shader MConfs
    Level_14_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_14_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_14_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_14_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_14_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_14_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_14_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_14_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_14_Data.Data  = LoadFile("LevelData/Level_14/Level_14.mpak");


    Level_15_Data.LevelWidth = 512;

    Level_15_Data.LevelHeight = 24;
    Level_15_Data.VisableTiles = 32;

    // Shader MConfs
    Level_15_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_15_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_15_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_15_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_15_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_15_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_15_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_15_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_15_Data.Data  = LoadFile("LevelData/Level_15/Level_15.mpak");


    Level_16_Data.LevelWidth = 512;

    Level_16_Data.LevelHeight = 24;
    Level_16_Data.VisableTiles = 32;

    // Shader MConfs
    Level_16_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_16_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_16_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_16_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_16_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_16_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_16_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_16_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_16_Data.Data  = LoadFile("LevelData/Level_16/Level_16.mpak");


    Level_17_Data.LevelWidth = 512;

    Level_17_Data.LevelHeight = 24;
    Level_17_Data.VisableTiles = 32;

    // Shader MConfs
    Level_17_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_17_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_17_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_17_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_17_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_17_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_17_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_17_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_17_Data.Data  = LoadFile("LevelData/Level_17/Level_17.mpak");

    Level_18_Data.LevelWidth = 512;

    Level_18_Data.LevelHeight = 24;
    Level_18_Data.VisableTiles = 32;

    // Shader MConfs
    Level_18_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_18_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_18_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_18_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_18_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_18_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_18_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_18_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_18_Data.Data  = LoadFile("LevelData/Level_18/Level_18.mpak");


    Level_19_Data.LevelWidth = 512;

    Level_19_Data.LevelHeight = 24;
    Level_19_Data.VisableTiles = 32;

    // Shader MConfs
    Level_19_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_19_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_19_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_19_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_19_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_19_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_19_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_19_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_19_Data.Data  = LoadFile("LevelData/Level_19/Level_19.mpak");

    Level_20_Data.LevelWidth = 512;

    Level_20_Data.LevelHeight = 24;
    Level_20_Data.VisableTiles = 32;

    // Shader MConfs
    Level_20_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_20_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_20_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_20_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_20_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_20_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_20_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_20_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_20_Data.Data  = LoadFile("LevelData/Level_20/Level_20.mpak");

    Level_21_Data.LevelWidth = 512;

    Level_21_Data.LevelHeight = 24;
    Level_21_Data.VisableTiles = 32;

    // Shader MConfs
    Level_21_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_21_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_21_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_21_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_21_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_21_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_21_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_21_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_21_Data.Data  = LoadFile("LevelData/Level_21/Level_21.mpak");

    Level_22_Data.LevelWidth = 512;

    Level_22_Data.LevelHeight = 24;
    Level_22_Data.VisableTiles = 32;

    // Shader MConfs
    Level_22_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_22_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_22_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_22_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_22_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_22_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_22_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_22_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_22_Data.Data  = LoadFile("LevelData/Level_22/Level_22.mpak");

    Level_23_Data.LevelWidth = 512;

    Level_23_Data.LevelHeight = 24;
    Level_23_Data.VisableTiles = 32;

    // Shader MConfs
    Level_23_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_23_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_23_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_23_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_23_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_23_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_23_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_23_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_23_Data.Data  = LoadFile("LevelData/Level_23/Level_23.mpak");

    Level_24_Data.LevelWidth = 512;

    Level_24_Data.LevelHeight = 24;
    Level_24_Data.VisableTiles = 32;

    // Shader MConfs
    Level_24_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_24_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_24_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_24_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_24_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_24_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_24_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_24_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_24_Data.Data  = LoadFile("LevelData/Level_24/Level_24.mpak");

    Level_25_Data.LevelWidth = 512;

    Level_25_Data.LevelHeight = 24;
    Level_25_Data.VisableTiles = 32;

    // Shader MConfs
    Level_25_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_25_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_25_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_25_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_25_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_25_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_25_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_25_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_25_Data.Data  = LoadFile("LevelData/Level_25/Level_25.mpak");

    Level_26_Data.LevelWidth = 512;

    Level_26_Data.LevelHeight = 24;
    Level_26_Data.VisableTiles = 32;

    // Shader MConfs
    Level_26_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_26_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_26_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_26_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_26_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_26_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_26_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_26_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_26_Data.Data  = LoadFile("LevelData/Level_26/Level_26.mpak");

    Level_27_Data.LevelWidth = 512;

    Level_27_Data.LevelHeight = 24;
    Level_27_Data.VisableTiles = 32;

    // Shader MConfs
    Level_27_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_27_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_27_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_27_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_27_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_27_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_27_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_27_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_27_Data.Data  = LoadFile("LevelData/Level_27/Level_27.mpak");

    Level_28_Data.LevelWidth = 512;

    Level_28_Data.LevelHeight = 24;
    Level_28_Data.VisableTiles = 32;

    // Shader MConfs
    Level_28_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_28_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_28_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_28_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_28_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_28_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_28_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_28_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_28_Data.Data  = LoadFile("LevelData/Level_28/Level_28.mpak");

    Level_29_Data.LevelWidth = 512;

    Level_29_Data.LevelHeight = 24;
    Level_29_Data.VisableTiles = 32;

    // Shader MConfs
    Level_29_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_29_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_29_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_29_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_29_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_29_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_29_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_29_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_29_Data.Data  = LoadFile("LevelData/Level_29/Level_29.mpak");

    Level_30_Data.LevelWidth = 512;

    Level_30_Data.LevelHeight = 24;
    Level_30_Data.VisableTiles = 32;

    // Shader MConfs
    Level_30_Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level_30_Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level_30_Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level_30_Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level_30_Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level_30_Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level_30_Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level_30_Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level_30_Data.Data  = LoadFile("LevelData/Level_30/Level_30.mpak");
}

