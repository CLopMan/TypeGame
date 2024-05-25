#include "game.hpp"

#include <iostream>
#include <csignal>
#include <cstring>
#include <filesystem>
#include <thread>

#define COMM_MAXSIZE 512
const std::string PATH = std::filesystem::current_path().string();

std::stringstream buff;

void reader() {
    
}

void writer() {

}

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
    getc(stdin);

}

void sigint_handdler(int sig) {
    std::cout << "Exiting game...\n"; 
    
    exit(0);
}

void start_new_game_handdler(int sig) {
    std::cout << "new text:\n";
    start_new_game();
}
/*
void set_up() {
    close(0);
    dup(buff.)
}
*/
void game_init() {
    std::signal(SIGINT, sigint_handdler);
    std::cout << "====TYPEGAME====\n";
    std::cout << "ctrl + z: new game\nctrl + c: exit\n";
//    set_up();
}

// consola 
int shell() {
    printf("COMMANDS\n\t1. new game\n\t2. add text\n\t3.quit\n");
    char command[COMM_MAXSIZE];
    printf("c>");
    scanf("%s", &command);
    if (!strcmp(command, "new_game")) {
        start_new_game(); 
    } else if (!strcmp(command, "quit")) {
        return 1;
    } else if (!strcmp(command, "add_text")) {
        
    } else {
        printf("\nNot recognised command: %s\n", command);
    }
    return 0;
}

int main() {
    game_init();
    while (!shell()) {}

    return 0;
    
}
