#include <string>
#include <chrono>

class Game {
private:
    std::string text;
    char nextChar;
    std::string buff;
    std::chrono::steady_clock::time_point timestamp_start;
    std::chrono::steady_clock::time_point timestamp_stop;
    int c_correct;
    int c_failed;

public:
    Game(std::string path);
    std::chrono::steady_clock::time_point start();
    std::chrono::steady_clock::time_point stop();
    float time();
    float accuracy();
    float wpm();
    void evaluate();
    void stadistics();
};