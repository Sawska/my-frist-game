#include <iostream>
#include "MonsterSpawner.h"
template <typename MoveStrategy>
MonsterSpawner<MoveStrategy>::MonsterSpawner(int init_monster_x_spawn, int init_monster_y_spawn)
    : monster_x_spawn(init_monster_x_spawn), monster_y_spawn(init_monster_y_spawn) {}

template <typename MoveStrategy>
void MonsterSpawner<MoveStrategy>::spawn_monster() {
    MoveStrategy strategy;
    
    std::cout << monster_x_spawn << std::endl;
    std::cout << monster_y_spawn << std::endl;

    monsters.emplace_back(monster_x_spawn, monster_y_spawn, 1, strategy);
}

template <typename MoveStrategy>
void MonsterSpawner<MoveStrategy>::check_if_monster_took_damage(int bullet_x) {
    for (auto& monster : monsters) {
        monster.check_if_took_damage(bullet_x);
    }
}



template <typename MoveStrategy>
void MonsterSpawner<MoveStrategy>::update_monsters() {
    for (auto& monster : monsters) {
        monster.move();
        monster.print_monster();
    }

    monsters.erase(std::remove_if(monsters.begin(), monsters.end(),
                                  [](const Monster<MoveStrategy>& monster) { return !monster.is_alive; }),
                   monsters.end());
}
