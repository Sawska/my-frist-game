#include <ncurses.h>
#include <unistd.h>
#include <thread>
#include <atomic>
#include <iostream>
#include "Player.h"
#include "MonsterSpawner.h"
#include "LeftToRightMove.h"
#include "RightToLeftMove.h"

#define MONSTER_RATE 2


std::atomic<int> keypress(-1);
std::atomic<bool> game_running(true);

void input_thread() {
    while (game_running) {
        int ch = getch();
        keypress.store(ch);
    }
}

void monster_thread(Player& player) {
    while (game_running) {
        player.leftToRightSpawner.update_monsters();
        player.rightToLeftSpawner.update_monsters();
        usleep(100000);
    }
}

void player_action_thread(Player& player, char action) {
    switch (action) {
        case 'a': player.turn_left(); break;
        case 'd': player.turn_right(); break;
        case 'w': player.jump(); break;
        case 's': player.shoot(); break;
    }
}

void player_thread(Player& player) {
    while (game_running) {
        int ch = keypress.load();
        if (ch != -1) {
            std::thread actionThread(player_action_thread, std::ref(player), ch);
            actionThread.detach();
            keypress.store(-1);
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

    Player player(cols / 2, rows / 2, 1);

    player.leftToRightSpawner = MonsterSpawner<LeftToRightMove>(25, rows / 2,MONSTER_RATE);
    
    player.rightToLeftSpawner = MonsterSpawner<RightToLeftMove>(cols - 1, rows / 2,MONSTER_RATE);
    

    std::thread inputThread(input_thread);
    std::thread monsterThread(monster_thread, std::ref(player));
    std::thread playerThread(player_thread, std::ref(player));

    while (game_running) {
        clear();
        player.increment_lifetime();
        player.print_character();
        player.leftToRightSpawner.spawn_monster();
        player.rightToLeftSpawner.spawn_monster();
        player.leftToRightSpawner.update_monsters();
        player.rightToLeftSpawner.update_monsters();
        player.check_if_player_got_hit();
        refresh();
        usleep(100000);
    }

    inputThread.join();
    monsterThread.join();
    playerThread.join();

    endwin();
    return 0;
}
