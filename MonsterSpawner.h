#ifndef MONSTERSPAWNER_H
#define MONSTERSPAWNER_H

#include <vector>
#include "Monster.h"
#include "RightToLeftMove.h"
#include "LeftToRightMove.h"

template <typename MoveStrategy>
class MonsterSpawner {
public:
    MonsterSpawner(int init_monster_x_spawn, int init_monster_y_spawn);

    void spawn_monster();
    void check_if_monster_took_damage(int bullet_x);
    void update_monsters();
    std::vector<Monster<MoveStrategy>> monsters;

private:
    int monster_x_spawn;
    int monster_y_spawn;
};

#include "MonsterSpawner.tpp" // Include the template implementation here

#endif // MONSTERSPAWNER_H
