#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include "cat.h"

int main()
{
    std::cout << "Hello World!";
    std::srand(time(NULL));
    std::thread first(&Cat::Cat, snowball, "Snowball", 50, 1);
    std::thread second(&Cat::Cat, spot, "Spot", 25, 2);
    first.join();
    second.join();
}
