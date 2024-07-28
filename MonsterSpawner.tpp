#include "MonsterSpawner.h"

template <typename MoveStrategy>
MonsterSpawner<MoveStrategy>::MonsterSpawner(int init_monster_x_spawn, int init_monster_y_spawn)
    : monster_x_spawn(init_monster_x_spawn), monster_y_spawn(init_monster_y_spawn) {}

template <typename MoveStrategy>
void MonsterSpawner<MoveStrategy>::spawn_monster() {
    MoveStrategy strategy;
    monsters.emplace_back(monster_x_spawn, monster_y_spawn, 10, strategy);
}

template <typename MoveStrategy>
void MonsterSpawner<MoveStrategy>::check_if_monster_took_damage(int bullet_x, int bullet_y) {
    for (auto& monster : monsters) {
        monster.check_if_took_damage(bullet_x, bullet_y);
    }
}
