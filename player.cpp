#include "Player.h"
#include <ncurses.h>

Player::Player(int init_x, int init_y, int init_hp, int init_x_gun, int init_y_gun)
    : x(init_x), y(init_y), hp(init_hp), x_gun(init_x_gun), y_gun(init_y_gun), gun_direction('R') {}

void Player::shoot() {
   
}

void Player::turn_left() {
    // switch (gun_direction) {
    //     case 'R': gun_direction = 'U'; break;
    //     case 'U': gun_direction = 'L'; break;
    //     case 'L': gun_direction = 'D'; break;
    //     case 'D': gun_direction = 'R'; break;
    // }
}

void Player::turn_right() {
    switch (gun_direction) {
        case 'R': gun_direction = 'D'; break;
        case 'D': gun_direction = 'L'; break;
        case 'L': gun_direction = 'U'; break;
        case 'U': gun_direction = 'R'; break;
    }
    print_character();
}

void Player::jump() {
    if (y > 0) y--; 
}

void Player::print_character() {
    mvaddch(y, x, '@');

    
    // switch (gun_direction) {
    //     case 'R': mvaddch(y, x_gun, 'z'); break; // Right
    //     case 'L': mvaddch(y, x_gun, 'z'); break; // Left
    //     case 'U': mvaddch(y_gun, x, 'z'); break; // Up
    //     case 'D': mvaddch(y_gun, x, 'z'); break; // Down
    // }
}

void Player::take_damage() {
    // Implement damage logic if needed
}
