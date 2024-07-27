#include "Player.h"
#include <ncurses.h>
#include <unistd.h>
#include <iostream>

Player::Player(int init_x, int init_y, int init_hp)
    : x(init_x), y(init_y), hp(init_hp), is_gun_left(true) {}

void Player::shoot() {
    if (is_gun_left) {
        int x_temp = x - 1;
        while (x_temp > 0) {
            mvaddch(y, x_temp, '-');
            print_character();
            refresh();
            usleep(50000);
            mvaddch(y, x_temp, ' ');
            x_temp--;
        }
    } else {
        int x_temp = x + 1;
        while (x_temp < COLS) {
            mvaddch(y, x_temp, '-');
            print_character();
            refresh();
            usleep(50000);
            mvaddch(y, x_temp, ' ');
            x_temp++;
        }
    }
}

void Player::bullet_trace(int x_temp) {
    while(x_temp < 1000) {
        mvaddch(y, x_temp+2, '-');
    }
}

void Player::turn_left() {
    is_gun_left = true;
    print_gun();
}

void Player::turn_right() {
    is_gun_left = false;
    print_gun();
}

void Player::jump() {
    if (y > 0) {
        mvaddch(y, x, ' ');
        clear_gun();
        y--;
        mvaddch(y, x, '@');
        print_gun();
        refresh();
        usleep(500000);
        mvaddch(y, x, ' ');
        clear_gun();
        y++;
        mvaddch(y, x, '@');
        print_gun();
        refresh();
    }
}

void Player::clear_gun() {
    if (is_gun_left) {
        mvaddch(y, x - 1, ' ');
    } else {
        mvaddch(y, x + 1, ' ');
    }
}

void Player::print_gun() {
    if(is_gun_left) {
        print_gun_left();
    } else {
        print_gun_right();
    }
}

void Player::jump_gun() {
    if(is_gun_left) {
            mvaddch(y, x-1, 'z');
        } else {
            mvaddch(y, x+1, 'z');
        }
}

void Player::print_gun_right() {
    mvaddch(y, x-1, ' ');
    mvaddch(y, x+1, 'z');
}
void Player::print_gun_left() {
    mvaddch(y, x+1, ' ');
    mvaddch(y, x-1, 'z');
}


void Player::print_character() {
    mvaddch(y, x, '@');
    print_gun();
}

void Player::take_damage() {
    if(hp == 0) {
        clear();
        std::cout << "You lost" << std::endl;
        exit(0)
    }
}
