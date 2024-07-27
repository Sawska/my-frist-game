#ifndef MONSTER_H
#define MONSTER_H

template <typename MoveStrategy>
class Monster {
private:
    int x;
    int y;
    int hp;
    bool is_alive;
    MoveStrategy move_strategy;

public:
    Monster(int init_x, int init_y, int init_hp, MoveStrategy strategy);

    void take_damage();
    void move();
    void print_monster();
    bool is_alive() const;
};

#endif
