#ifndef MONSTER_H
#define MONSTER_H

#include <ncurses.h>

template <typename MoveStrategy>
class Monster {
public:
    Monster(int init_x, int init_y, int init_hp, MoveStrategy strategy);

    void take_damage();
    void move();
    void print_monster();
    void check_if_took_damage(int bullet_x, int bullet_y);

private:
    int x;
    int y;
    int hp;
    bool is_alive;
    MoveStrategy move_strategy;
};

#include "Monster.tpp"

#endif // MONSTER_H
