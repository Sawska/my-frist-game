#ifndef PLAYER_H
#define PLAYER_H

#include "MonsterSpawner.h"
#include "LeftToRightMove.h"
#include "RightToLeftMove.h"

class Player {
private:
    int x;
    int y;
    int hp;
    bool is_gun_left;

public:
    Player(int init_x, int init_y, int init_hp);

    void shoot();
    void turn_left();
    void turn_right();
    void jump();
    void print_character();
    void take_damage();
    void print_gun_right();
    void print_gun_left();
    void jump_gun();
    void print_gun();
    void clear_gun();
    void bullet_trace(int x_temp);
    void check_if_player_got_hit();


    int getX() const { return x; }
    int getY() const { return y; }
    MonsterSpawner<LeftToRightMove> leftToRightSpawner;
    MonsterSpawner<RightToLeftMove> rightToLeftSpawner;
};

#endif // PLAYER_H
