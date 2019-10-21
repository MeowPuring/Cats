#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include "cat.h"

int main()
{
    std::srand(time(NULL));
    std::mutex mtx;
    Cat snowball;
    Cat spot;
    std::thread first(&Cat::GetValues, snowball, std::ref(mtx), "Snowball", 100, 1);
    std::thread second(&Cat::GetValues, spot, std::ref(mtx), "Spot", 25, 2);
    first.join();
    second.join();
}
