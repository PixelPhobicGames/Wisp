


typedef struct MysticPlayer
{
    /* data */
    int x;
    int y;
    int direction;
    int facing_direction;
    int Velocity_X;
    int Velocity_Y;
    int Level;
    int Health;

    int IsJumping;
    int JumpCounter;
    int IsOnGround;

    int Projectile_Direction;
    int JumpCoolDown;
    int acceloration;
    int Lives;
    int Text_Size;

    int Projectile_trigger;
    int Projectile_x;
    int Projectile_y;

    int CanShoot;

    int HeartVisable;

    int Rocket_x;
    int Rocket_y;
    int Rocket_trigger;

    int Click_Timer;
    int Click_x;
    int Click_y;

    int HasRocket;
    


}MysticPlayer;


static MysticPlayer MysticPlayerOne;
