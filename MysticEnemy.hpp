#define EMC 20
typedef struct Enemy{
    int x;
    int y;
    int Velocity_X;
    int Velocity_Y;
    int direction;
    int health;
    int isalive;
    int JumpCount;
    int IsJumping;
    int Jumper_CoolDown;

    int DT;

}Enemy;


static Enemy MysticEnemy[EMC];


typedef struct Boss{
    int Projectile_x;
    int Projectile_y;
    int Projectile_trigger;
    int Projectile_timer;
    int Alive;
}Boss;

static Boss MysticBoss;


