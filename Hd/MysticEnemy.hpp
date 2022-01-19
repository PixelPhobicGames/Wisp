
#define MaxEnemys 40

typedef struct Enemy{
    int x;
    int y;
    int VelocityX;
    int VelocityY;
    int Direction;
    int Health;
    int IsAlive;
    int JumpCount;
    int IsJumping;
    int JumperCoolDown;
    int DT;

}Enemy;


static Enemy MysticEnemy[MaxEnemys];


typedef struct Boss{
    int ProjectileX;
    int ProjectileY;
    int ProjectileTrigger;
    int ProjectileTimer;
    int Alive;
}Boss;

static Boss MysticBoss;


