#include <iostream>
#include <chrono>
#include <string>
#include <time.h>
#include <thread>

const int LAST_MINUTES = 20;
const int SLEEP_MINUTES = 2;

std::string getNowStr() { // a function just to print now time format.
    time_t timer;
    char buffer[26];
    struct tm* tm_info;
    timer = time(NULL);
    tm_info = localtime(&timer);
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    std::string str = std::string(buffer);
    return str;
}

int main(int, char**) {
    std::cout << "Protect eye Starting, now is: " << getNowStr() << std::endl;
    std::chrono::minutes lastTime =  std::chrono::minutes(LAST_MINUTES);
    while (true)
    {
        std::this_thread::sleep_for(lastTime);
        system("notify-send 'you need take a rest at least for twenty seconds' -t 6000");
        std::cout << "Notify time is: " << getNowStr() << std::endl;
    }
}
