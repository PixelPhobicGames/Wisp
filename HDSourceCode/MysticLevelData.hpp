#include <string>
#include <fstream>
#include <iostream>

using namespace std;



static int R = 0;
static int G = 0;
static int B = 0;

#define SplashColor  CLITERAL(Color){ R, G, B, 255 } 

#define SPRO  CLITERAL(Color){ 74, 74, 74, 255 } 
#define SPRO2  CLITERAL(Color){ 32, 32, 32, 255 } 

static int TextAnimationValue = 0;

static int HomeScreenScroller = 0;

static int LevelEditorXOffset = 8;

static int Help = false;

static int Splash = true;

static int SplashCounter = 0 ;

static int SaveMessageCounter = 0;

static int ColorCounter = 0;

static wchar_t CurrrentSelectedTile = L'0';

static int Scroller = 0;

static int FrameCounter = 0;

static int TextCounter = 1;

static int BonusLevelsEnabled = false;

static int BonusScroll = 0;

static int Start = false;

static int ExportMessageCounter = 0;



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
    int LevelID;
    int FPS;
    int AnimationTicker;
    int Debug;
    int HoverAnimationTicker;
    int HoverAnimationDirection;
    int GameType;
    int GravityStrength;
    int BreakTimer;
    int CanMoveOn;
    int TrackNumber;
    int LowEndHardware;
    int LevelEditor;
    float Scale;
    int Difficulty;
    int BonusMenu;
    
    Shader shader;
    Music TitleMusic;
    Music GameMusic1;
    Music GameMusic2;
    Music GameMusic3;
    Music GameMusic4;

    Music KillSound;
    Music ShootSound;
    Music JumpSound;
}GameData;

static GameData MysticCoreData;

typedef struct MCamera{
    int XOffset;
    int YOffset;
    int BackgroundParrallaxX1;
    int BackgroundParrallaxX2;
    int BackgroundParrallaxX3;
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

    Music Music1;

}LevelData;

static LevelData Level1Data;

static LevelData Level2Data;

static LevelData Level3Data;

static LevelData Level4Data;

static LevelData Level5Data;

static LevelData Level6Data;

static LevelData Level7Data;

static LevelData Level8Data;

static LevelData Level9Data;

static LevelData Level10Data;

static LevelData Level11Data;

static LevelData Level12Data;

static LevelData Level13Data;

static LevelData Level14Data;

static LevelData Level15Data;

static LevelData Level16Data;

static LevelData Level17Data;

static LevelData Level18Data;

static LevelData Level19Data;

static LevelData Level20Data;

static LevelData Level21Data;

static LevelData Level22Data;

static LevelData Level23Data;

static LevelData Level24Data;

static LevelData Level25Data;

static LevelData Level26Data;

static LevelData Level27Data;

static LevelData Level28Data;

static LevelData Level29Data;

static LevelData Level30Data;

static LevelData LevelCustomData;

static LevelData BonusData1;


typedef struct MShaders{
    Shader Water;
    Shader General;
}MShaders;

static MShaders CoreShaders;


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

    MysticCoreData.KillSound = LoadMusicStream("GameAssets/Sound/Kill.mp3");
    MysticCoreData.ShootSound = LoadMusicStream("GameAssets/Sound/Shoot.mp3");
    MysticCoreData.JumpSound = LoadMusicStream("GameAssets/Sound/Jump.mp3");


    Level1Data.LevelWidth = 512;

    Level1Data.LevelHeight = 24;
    Level1Data.VisableTiles = 32;

    // Shader MConfs
    Level1Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level1Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level1Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level1Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level1Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level1Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level1Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level1Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_1/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level1Data.Data  = LoadFile("LevelData/Level_1/Level_1.mpak");


    Level2Data.LevelWidth = 512;

    Level2Data.LevelHeight = 24;
    Level2Data.VisableTiles = 32;

    // Shader MConfs
    Level2Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level2Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level2Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level2Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level2Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level2Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level2Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level2Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_2/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level2Data.Data  = LoadFile("LevelData/Level_2/Level_2.mpak");

    

    Level3Data.LevelWidth = 512;

    Level3Data.LevelHeight = 24;
    Level3Data.VisableTiles = 32;

    // Shader MConfs
    Level3Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level3Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level3Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level3Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level3Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level3Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level3Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level3Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_3/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level3Data.Data  = LoadFile("LevelData/Level_3/Level_3.mpak");

    Level4Data.LevelWidth = 512;

    Level4Data.LevelHeight = 24;
    Level4Data.VisableTiles = 32;

    // Shader MConfs
    Level4Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level4Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level4Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level4Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level4Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level4Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level4Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level4Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_4/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level4Data.Data  = LoadFile("LevelData/Level_4/Level_4.mpak");

    Level5Data.LevelWidth = 512;

    Level5Data.LevelHeight = 24;
    Level5Data.VisableTiles = 32;

    // Shader MConfs
    Level5Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level5Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level5Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level5Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level5Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level5Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level5Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level5Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_5/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level5Data.Data  = LoadFile("LevelData/Level_5/Level_5.mpak");

    Level6Data.LevelWidth = 512;

    Level6Data.LevelHeight = 24;
    Level6Data.VisableTiles = 32;

    // Shader MConfs
    Level6Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level6Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level6Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level6Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level6Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level6Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level6Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level6Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_6/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level6Data.Data  = LoadFile("LevelData/Level_6/Level_6.mpak");

    Level7Data.LevelWidth = 512;

    Level7Data.LevelHeight = 24;
    Level7Data.VisableTiles = 32;

    // Shader MConfs
    Level7Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level7Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level7Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level7Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level7Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level7Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level7Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level7Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_7/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level7Data.Data  = LoadFile("LevelData/Level_7/Level_7.mpak");

    Level8Data.LevelWidth = 512;

    Level8Data.LevelHeight = 24;
    Level8Data.VisableTiles = 32;

    // Shader MConfs
    Level8Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level8Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level8Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level8Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level8Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level8Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level8Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level8Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_8/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level8Data.Data  = LoadFile("LevelData/Level_8/Level_8.mpak");

    Level9Data.LevelWidth = 512;

    Level9Data.LevelHeight = 24;
    Level9Data.VisableTiles = 32;

    // Shader MConfs
    Level9Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level9Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level9Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level9Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level9Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level9Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level9Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level9Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_9/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level9Data.Data  = LoadFile("LevelData/Level_9/Level_9.mpak");
    
    Level10Data.LevelWidth = 512;

    Level10Data.LevelHeight = 24;
    Level10Data.VisableTiles = 32;

    // Shader MConfs
    Level10Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level10Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level10Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level10Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level10Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level10Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level10Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level10Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level10Data.Data  = LoadFile("LevelData/Level_10/Level_10.mpak");

    Level10Data.LevelWidth = 512;

    Level10Data.LevelHeight = 24;
    Level10Data.VisableTiles = 32;

    // Shader MConfs
    Level10Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level10Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level10Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level10Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level10Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level10Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level10Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level10Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_10/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level10Data.Data  = LoadFile("LevelData/Level_10/Level_10.mpak");

    Level11Data.LevelWidth = 512;

    Level11Data.LevelHeight = 24;
    Level11Data.VisableTiles = 32;

    // Shader MConfs
    Level11Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level11Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level11Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level11Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level11Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level11Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level11Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level11Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_11/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level11Data.Data  = LoadFile("LevelData/Level_11/Level_11.mpak");


    Level12Data.LevelWidth = 512;

    Level12Data.LevelHeight = 24;
    Level12Data.VisableTiles = 32;

    // Shader MConfs
    Level12Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level12Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level12Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level12Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level12Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level12Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level12Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level12Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_12/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level12Data.Data  = LoadFile("LevelData/Level_12/Level_12.mpak");

    Level13Data.LevelWidth = 512;

    Level13Data.LevelHeight = 24;
    Level13Data.VisableTiles = 32;

    // Shader MConfs
    Level13Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level13Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level13Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level13Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level13Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level13Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level13Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level13Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_13/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level13Data.Data  = LoadFile("LevelData/Level_13/Level_13.mpak");

    Level14Data.LevelWidth = 512;

    Level14Data.LevelHeight = 24;
    Level14Data.VisableTiles = 32;

    // Shader MConfs
    Level14Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level14Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level14Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level14Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level14Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level14Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level14Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level14Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_14/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level14Data.Data  = LoadFile("LevelData/Level_14/Level_14.mpak");


    Level15Data.LevelWidth = 512;

    Level15Data.LevelHeight = 24;
    Level15Data.VisableTiles = 32;

    // Shader MConfs
    Level15Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level15Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level15Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level15Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level15Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level15Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level15Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level15Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_15/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level15Data.Data  = LoadFile("LevelData/Level_15/Level_15.mpak");


    Level16Data.LevelWidth = 512;

    Level16Data.LevelHeight = 24;
    Level16Data.VisableTiles = 32;

    // Shader MConfs
    Level16Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level16Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level16Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level16Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level16Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level16Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level16Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level16Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_16/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level16Data.Data  = LoadFile("LevelData/Level_16/Level_16.mpak");


    Level17Data.LevelWidth = 512;

    Level17Data.LevelHeight = 24;
    Level17Data.VisableTiles = 32;

    // Shader MConfs
    Level17Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level17Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level17Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level17Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level17Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level17Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level17Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level17Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_17/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level17Data.Data  = LoadFile("LevelData/Level_17/Level_17.mpak");

    Level18Data.LevelWidth = 512;

    Level18Data.LevelHeight = 24;
    Level18Data.VisableTiles = 32;

    // Shader MConfs
    Level18Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level18Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level18Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level18Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level18Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level18Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level18Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level18Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_18/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level18Data.Data  = LoadFile("LevelData/Level_18/Level_18.mpak");


    Level19Data.LevelWidth = 512;

    Level19Data.LevelHeight = 24;
    Level19Data.VisableTiles = 32;

    // Shader MConfs
    Level19Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level19Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level19Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level19Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level19Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level19Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level19Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level19Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_19/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level19Data.Data  = LoadFile("LevelData/Level_19/Level_19.mpak");

    Level20Data.LevelWidth = 512;

    Level20Data.LevelHeight = 24;
    Level20Data.VisableTiles = 32;

    // Shader MConfs
    Level20Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level20Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level20Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level20Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level20Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level20Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level20Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level20Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_20/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level20Data.Data  = LoadFile("LevelData/Level_20/Level_20.mpak");

    Level21Data.LevelWidth = 512;

    Level21Data.LevelHeight = 24;
    Level21Data.VisableTiles = 32;

    // Shader MConfs
    Level21Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level21Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level21Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level21Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level21Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level21Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level21Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level21Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_21/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level21Data.Data  = LoadFile("LevelData/Level_21/Level_21.mpak");

    Level22Data.LevelWidth = 512;

    Level22Data.LevelHeight = 24;
    Level22Data.VisableTiles = 32;

    // Shader MConfs
    Level22Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level22Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level22Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level22Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level22Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level22Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level22Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level22Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_22/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level22Data.Data  = LoadFile("LevelData/Level_22/Level_22.mpak");

    Level23Data.LevelWidth = 512;

    Level23Data.LevelHeight = 24;
    Level23Data.VisableTiles = 32;

    // Shader MConfs
    Level23Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level23Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level23Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level23Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level23Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level23Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level23Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level23Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_23/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level23Data.Data  = LoadFile("LevelData/Level_23/Level_23.mpak");

    Level24Data.LevelWidth = 512;

    Level24Data.LevelHeight = 24;
    Level24Data.VisableTiles = 32;

    // Shader MConfs
    Level24Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level24Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level24Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level24Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level24Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level24Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level24Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level24Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_24/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level24Data.Data  = LoadFile("LevelData/Level_24/Level_24.mpak");

    Level25Data.LevelWidth = 512;

    Level25Data.LevelHeight = 24;
    Level25Data.VisableTiles = 32;

    // Shader MConfs
    Level25Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level25Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level25Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level25Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level25Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level25Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level25Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level25Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_25/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level25Data.Data  = LoadFile("LevelData/Level_25/Level_25.mpak");

    Level26Data.LevelWidth = 512;

    Level26Data.LevelHeight = 24;
    Level26Data.VisableTiles = 32;

    // Shader MConfs
    Level26Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level26Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level26Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level26Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level26Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level26Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level26Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level26Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_26/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level26Data.Data  = LoadFile("LevelData/Level_26/Level_26.mpak");

    Level27Data.LevelWidth = 512;

    Level27Data.LevelHeight = 24;
    Level27Data.VisableTiles = 32;

    // Shader MConfs
    Level27Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level27Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level27Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level27Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level27Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level27Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level27Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level27Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_27/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level27Data.Data  = LoadFile("LevelData/Level_27/Level_27.mpak");

    Level28Data.LevelWidth = 512;

    Level28Data.LevelHeight = 24;
    Level28Data.VisableTiles = 32;

    // Shader MConfs
    Level28Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level28Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level28Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level28Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level28Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level28Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level28Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level28Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_28/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level28Data.Data  = LoadFile("LevelData/Level_28/Level_28.mpak");

    Level29Data.LevelWidth = 512;

    Level29Data.LevelHeight = 24;
    Level29Data.VisableTiles = 32;

    // Shader MConfs
    Level29Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level29Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level29Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level29Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level29Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level29Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level29Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level29Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_29/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level29Data.Data  = LoadFile("LevelData/Level_29/Level_29.mpak");

    Level30Data.LevelWidth = 512;

    Level30Data.LevelHeight = 24;
    Level30Data.VisableTiles = 32;

    // Shader MConfs
    Level30Data.ShaderBlock1 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    Level30Data.ShaderBlock2 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    Level30Data.ShaderBlock3 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    Level30Data.ShaderBlock4 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    Level30Data.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    Level30Data.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    Level30Data.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    Level30Data.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_30/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    Level30Data.Data  = LoadFile("LevelData/Level_30/Level_30.mpak");

    LevelCustomData.LevelWidth = 512;

    LevelCustomData.LevelHeight = 24;
    LevelCustomData.VisableTiles = 32;

    // Shader MConfs
    LevelCustomData.ShaderBlock1 = LoadMconfFile("LevelData/Level_Custom/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    LevelCustomData.ShaderBlock2 = LoadMconfFile("LevelData/Level_Custom/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    LevelCustomData.ShaderBlock3 = LoadMconfFile("LevelData/Level_Custom/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    LevelCustomData.ShaderBlock4 = LoadMconfFile("LevelData/Level_Custom/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");

    // Non Collision Blocks 
    LevelCustomData.NonCollisionBlock1 = LoadMconfFile("LevelData/Level_Custom/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    LevelCustomData.NonCollisionBlock2 = LoadMconfFile("LevelData/Level_Custom/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    LevelCustomData.NonCollisionBlock3 = LoadMconfFile("LevelData/Level_Custom/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    LevelCustomData.NonCollisionBlock4 = LoadMconfFile("LevelData/Level_Custom/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    LevelCustomData.Data  = LoadFile("LevelData/Level_Custom/Level_Custom.mpak");

    BonusData1.LevelWidth = 512;

    BonusData1.LevelHeight = 24;
    BonusData1.VisableTiles = 32;

    // Shader MConfs
    BonusData1.ShaderBlock1 = LoadMconfFile("LevelData/Bonus_Data_1/ProgrammableComponents/ShaderConf/Custom_ShaderBlock1.mconf");
    BonusData1.ShaderBlock2 = LoadMconfFile("LevelData/Bonus_Data_1/ProgrammableComponents/ShaderConf/Custom_ShaderBlock2.mconf");
    BonusData1.ShaderBlock3 = LoadMconfFile("LevelData/Bonus_Data_1/ProgrammableComponents/ShaderConf/Custom_ShaderBlock3.mconf");
    BonusData1.ShaderBlock4 = LoadMconfFile("LevelData/Bonus_Data_1/ProgrammableComponents/ShaderConf/Custom_ShaderBlock4.mconf");


    BonusData1.NonCollisionBlock1 = LoadMconfFile("LevelData/Bonus_Data_1/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block1.mconf");
    BonusData1.NonCollisionBlock2 = LoadMconfFile("LevelData/Bonus_Data_1/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block2.mconf");
    BonusData1.NonCollisionBlock3 = LoadMconfFile("LevelData/Bonus_Data_1/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block3.mconf");
    BonusData1.NonCollisionBlock4 = LoadMconfFile("LevelData/Bonus_Data_1/ProgrammableComponents/CollisionBlockConf/Custom_NonCollision_Block4.mconf");

    BonusData1.Data  = LoadFile("LevelData/Bonus_Data_1/Bonus_Data_1.mpak");
}

