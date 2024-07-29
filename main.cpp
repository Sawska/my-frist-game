#include <ncurses.h>
#include <unistd.h>
#include <thread>
#include <atomic>
#include <iostream>
#include "Player.h"
#include "MonsterSpawner.h"
#include "LeftToRightMove.h"
#include "RightToLeftMove.h"

std::atomic<int> keypress(-1);

void input_thread() {
    while (true) {
        int ch = getch();
        keypress.store(ch);
    }
}

void monster_thread(Player& player) {
    while (true) {
        player.leftToRightSpawner.update_monsters();
        player.rightToLeftSpawner.update_monsters();
        usleep(100000); 
    }
}

void bullet_thread(Player& player) {
    while (true) {
        player.shoot();
        usleep(100000); 
    }
}

void player_thread(Player& player) {
    while (true) {
        int ch = keypress.load();
        switch (ch) {
            case 'a': player.turn_left(); keypress = -1; break;
            case 'd': player.turn_right(); keypress = -1; break;
            case 'w': player.jump(); keypress = -1; break;
            case 's': keypress = -1; break; 
        }
        player.print_character();
        player.check_if_player_got_hit();
        usleep(100000); 
    }
}

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    Player player(cols / 2, rows / 2, 100);

    player.leftToRightSpawner = MonsterSpawner<LeftToRightMove>(25, rows / 2);
    player.leftToRightSpawner.spawn_monster();
    player.rightToLeftSpawner = MonsterSpawner<RightToLeftMove>(cols - 1, rows / 2);
    player.rightToLeftSpawner.spawn_monster();

    std::thread inputThread(input_thread);
    std::thread monsterThread(monster_thread, std::ref(player));
    std::thread bulletThread(bullet_thread, std::ref(player));
    std::thread playerThread(player_thread, std::ref(player));

    inputThread.join();
    monsterThread.join();
    bulletThread.join();
    playerThread.join();

    endwin();
    return 0;
}
