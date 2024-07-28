#ifndef MONSTERSPAWNER_H
#define MONSTERSPAWNER_H

#include <vector>
#include "Monster.h"
#include <RightToLeftMove.h>
#include <LeftToRightMove.h>
#include "MonsterSpawner.tpp"

template <typename MoveStrategy>
class MonsterSpawner {
public:
    MonsterSpawner(int init_monster_x_spawn, int init_monster_y_spawn);

    void spawn_monster();
    void check_if_monster_took_damage(int bullet_x, int bullet_y);

private:
    std::vector<Monster<MoveStrategy>> monsters;
    int monster_x_spawn;
    int monster_y_spawn;
};



#endif // MONSTERSPAWNER_H
