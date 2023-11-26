#include "game.hpp"

#include <iostream>
#include <csignal>
#include <filesystem>

const std::string PATH = std::filesystem::current_path().string();

void game_init();

void start_new_game() {
    system("clear");
    std::cout << "=====text=====\n";
    //std::cout << system("ls texts");
    Game g(PATH + "/texts/test01");
    std::cout << "=====copy!=====\n";
    g.start();
    g.evaluate();
    g.stadistics();
    std::cout << "ctrl + z: new game\nctrl + c: exit\n";

}

void sigint_handdler(int sig) {
    std::cout << "Exiting game...\n"; 
    
    exit(0);
}

void start_new_game_handdler(int sig) {
    std::cout << "new text:\n";
    start_new_game();
}

void game_init() {
    system("clear");
    std::signal(SIGINT, sigint_handdler);
    std::signal(SIGTSTP, start_new_game_handdler);
    std::cout << "====TYPEGAME====\n";
    std::cout << "ctrl + z: new game\nctrl + c: exit\n";
}

int main() {
    game_init();
    while (1) {}
    return 0;
}