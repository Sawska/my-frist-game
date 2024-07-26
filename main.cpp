#include <ncurses.h>
#include <unistd.h>
#include <thread>
#include <atomic>
#include <iostream>
#include "Player.h"

std::atomic<int> keypress(-1);

void input_thread() {
    while (true) {
        int ch = getch(); 
        keypress.store(ch); 
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

    // Initialize player and gun
    Player player(cols / 2, rows / 2, 100, (cols / 2) + 1, rows / 2); 

    std::thread inputThread(input_thread);

    while (true) {
        clear();

        int ch = keypress.load();
        switch (ch) {
            case 'a': player.turn_left(); keypress = -1; break;
            case 'd': player.turn_right(); keypress = -1; break;
            case 'w': player.jump(); keypress = -1; break;
            case 's': player.shoot(); keypress = -1; break;
        }

        player.print_character(); 

        mvprintw(LINES - 1, 0, "Player position: %d, %d", player.getX(), player.getY());

        refresh();
        usleep(1000000); // Sleep for 1 second
    }

    inputThread.join();
    endwin(); 
    return 0;
}
