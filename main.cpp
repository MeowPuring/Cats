#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include "cat.h"

int main()
{
    std::cout << "Hello World!";
    std::srand(time(NULL));
    Cat snowball;
    Cat spot;
    std::thread first(&Cat::GetValues, snowball, "Snowball", 100, 1);
    std::thread second(&Cat::GetValues, spot, "Spot", 25, 2);
    first.join();
    second.join();
}
