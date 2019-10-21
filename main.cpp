#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include "home.h"

int main()
{
    std::srand(time(NULL));
    std::mutex mtx;
    Home *home = new Home;
    Cat snowball, spot;
    std::thread first(&Cat::SetValues, snowball, "Snowball", 5, 60);
    std::thread second(&Cat::SetValues, spot, "Spot", 2, 120);
    first.join();
    second.join();
}
