#include <iostream>
#include <chrono>
#include <string>
#include <time.h>

const int LAST_MINUTES = 20;

void printNow() { // a function just to print now time format.
    time_t timer;
    char buffer[26];
    struct tm* tm_info;
    timer = time(NULL);
    tm_info = localtime(&timer);
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    std::string str = "Notify time: " + std::string(buffer);
    std::cout << str << std::endl;
}

int main(int, char**) {
    std::chrono::seconds now = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now().time_since_epoch());
    std::chrono::seconds lastTime =  std::chrono::seconds(LAST_MINUTES * 60);
    std::chrono::seconds notifySeconds = now + lastTime;
    while(true) {
        std::chrono::seconds n = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now().time_since_epoch());
        if(n > notifySeconds) {
            system("notify-send 'you need take a rest at least for twenty seconds' -t 6000");
            printNow();
            now = n + std::chrono::seconds(60);
            notifySeconds = now + lastTime;
        }
    }


}
