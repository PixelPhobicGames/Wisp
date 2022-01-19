


typedef struct MysticPlayer
{
    int x;
    int y;
    int Direction;
    int FacingDirection;
    int VelocityX;
    int VelocityY;
    int Level;
    int Health;
    int Charge;

    int IsJumping;
    int JumpCounter;
    int IsOnGround;

    int ProjectileDirection;
    int JumpCoolDown;
    int Acceloration;
    int Lives;
    int TextSize;

    int ProjectileTrigger;
    int ProjectileX;
    int ProjectileY;

    int CanShoot;

    int HeartVisable;

    int RocketX;
    int RocketY;
    int RocketTrigger;

    int ClickTimer;
    int ClickX;
    int ClickY;

    int HasRocket;
    

}MysticPlayer;


static MysticPlayer MysticPlayerOne;


typedef struct Controls{
    bool Right;
    bool Left;
    bool Up;
    bool Shoot;

    bool VirtualMouseEnabled;

    int VirtualMouseX;
    int VirtualMouseY;

    bool VirtualMouseClick;
}Controls;

static Controls MysticControls;


int MysticGetVirtualMouseX(){
    if (MysticControls.VirtualMouseEnabled){
        return MysticControls.VirtualMouseX;
    }
    else {
        return GetMouseX();
    }
}

int MysticGetVirtualMouseY(){
    if (MysticControls.VirtualMouseEnabled){
        return MysticControls.VirtualMouseY;
    }
    else {
        return GetMouseY();
    }
}

bool MysticGetVirtualMouseClick(int Test){
    if (MysticControls.VirtualMouseEnabled){
        return MysticControls.VirtualMouseClick;
    }
    else {
        if (IsMouseButtonDown(Test)){
            return true;
        }
        else {
            return false;
        }
    }
}