#include "game.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


// constructor
Game::Game(std::string path) {
    std::stringstream buffer;
    std::ifstream txt(path);
    if (!txt.is_open()) {
        std::cerr << "cannot open file " + path + "\n";
    }
    buffer << txt.rdbuf();
    this->text = buffer.str();
    
    std::cout << this->text << "\n";

}
// timestamp when started
std::chrono::steady_clock::time_point Game::start(){
    this->timestamp_start = std::chrono::steady_clock::now();
    std::getline(std::cin, this->buff); 
    this->stop();
    return this->timestamp_start;
}
// timestamp finish
std::chrono::steady_clock::time_point Game::stop(){
    return this->timestamp_stop = std::chrono::steady_clock::now();
}
// calculate time (s) 
float Game::time(){
    return std::chrono::duration_cast<std::chrono::milliseconds>(this->timestamp_stop - this->timestamp_start).count()/(float)1000;
}
// calculate accuracy 
float Game::accuracy(){
    return ((this->c_correct) /(float) (this->c_correct + this-> c_failed))*100;
}
// calculate wpm write * accuracy
float Game::wpm(){
    return (this->c_correct + this->c_failed)*this->accuracy()*12/(float)(this->time()*100);
}

void Game::evaluate() {
    for (int i = 0; i < std::min(text.length(), buff.length()); ++i) {
        
        if (text[i] == this->buff[i]) ++this->c_correct;
        else ++this->c_failed;
        
    }
    c_failed += abs(this->buff.length() - this->text.length());
    std::cout << "c_correct: " << c_correct << "\nc_failed: " << c_failed << "\n";
}

// print stadistics
void Game::stadistics() {
    std::cout << "time (s): " << this->time() << "\naccuracy (%): " << this->accuracy() << "\nwpm: " << this->wpm() << "\n";
}
