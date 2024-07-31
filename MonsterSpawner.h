#ifndef MONSTERSPAWNER_H
#define MONSTERSPAWNER_H

#include <vector>
#include <random>
#include "Monster.h"
#include "RightToLeftMove.h"
#include "LeftToRightMove.h"



template <typename MoveStrategy>
class MonsterSpawner {
public:
    MonsterSpawner(int init_monster_x_spawn, int init_monster_y_spawn, int init_monster_rate);

    void spawn_monster();
    int check_if_monster_took_damage(int bullet_x);
    void update_monsters();
    std::vector<Monster<MoveStrategy>> monsters;

private:
    int monster_x_spawn;
    int monster_y_spawn;
    int monster_rate;
    std::mt19937 rng;
    std::uniform_real_distribution<> dist;
};

#include "MonsterSpawner.tpp" 

#endif // MONSTERSPAWNER_H
