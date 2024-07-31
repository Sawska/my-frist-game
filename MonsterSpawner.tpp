#include "MonsterSpawner.h"
#include <iostream>

template <typename MoveStrategy>
MonsterSpawner<MoveStrategy>::MonsterSpawner(int init_monster_x_spawn, int init_monster_y_spawn, int init_monster_rate)
    : monster_x_spawn(init_monster_x_spawn), monster_y_spawn(init_monster_y_spawn), monster_rate(init_monster_rate),
    rng(std::chrono::steady_clock::now().time_since_epoch().count()), 
      dist(0.0, 1.0)
    {}

template <typename MoveStrategy>
void MonsterSpawner<MoveStrategy>::spawn_monster() {
    
    double random_value = dist(rng);


    if (monsters.size() <= monster_rate && random_value >= 0.999) {
        MoveStrategy strategy;
        monsters.emplace_back(monster_x_spawn, monster_y_spawn, 1, strategy);
    }
}


template <typename MoveStrategy>
int MonsterSpawner<MoveStrategy>::check_if_monster_took_damage(int bullet_x) {
    int sum = 0;
    for (auto& monster : monsters) {
        sum += monster.check_if_took_damage(bullet_x);
    }
    return sum;
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
