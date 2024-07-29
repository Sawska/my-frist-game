#include "Monster.h"

template <typename MoveStrategy>
Monster<MoveStrategy>::Monster(int init_x, int init_y, int init_hp, MoveStrategy strategy)
    : x(init_x), y(init_y), hp(init_hp), is_alive(true), move_strategy(strategy) {}

template <typename MoveStrategy>
void Monster<MoveStrategy>::take_damage() {
    hp--;
    if (hp <= 0) {
        is_alive = false;
        mvaddch(y, x, ' ');
    }
}

template <typename MoveStrategy>
void Monster<MoveStrategy>::move() {
    mvaddch(y, x, ' ');
    move_strategy.move(x, y);
    if (x < 0 || x >= COLS || y < 0 || y >= LINES) {
        is_alive = false;
    }
}

template <typename MoveStrategy>
void Monster<MoveStrategy>::print_monster() {
    if (is_alive) {
        mvaddch(y, x, 'M');
    }
}

template <typename MoveStrategy>
void Monster<MoveStrategy>::check_if_took_damage(int bullet_x) {
    if (bullet_x == x) {
        take_damage();
    }
}
