#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int x;
    int y;
    int hp;
    int x_gun;
    int y_gun;
    char gun_direction;

public:
    Player(int init_x, int init_y, int init_hp, int init_x_gun, int init_y_gun);

    void shoot();
    void turn_left();
    void turn_right();
    void jump();
    void print_character();
    void take_damage();

    int getX() const { return x; }
    int getY() const { return y; }
    int getGunX() const { return x_gun; }
    int getGunY() const { return y_gun; }
};

#endif
