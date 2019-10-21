#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include "home.h"

int main()
{
    std::srand(time(NULL));
    std::mutex mtx;
    Home home;
    Cat papper, snowball, spot;
    Cat allcats[2] = {snowball, spot};
    std::thread addcats_thread(&Home::AddCatsInVector, home, allcats, std::ref(mtx));
    std::thread rmcats_thread(&Home::RemoveCatsFromVector, home, allcats, std::ref(mtx));
    std::thread papper_thread(&Cat::SetValues, papper, "papper", 100, 1);
    std::thread snowball_thread(&Cat::SetValues, snowball, "Snowball", 50, 2);
    std::thread spot_thread(&Cat::SetValues, spot, "Spot", 25, 4);
    while(true)
    {
        std::string action;
        std::cout << "Print \"print\" if wan't see all cats in home" << std::endl;
        std::cin >> action;
        std::cout << std::endl;
        if (action == "print")
        {
            home.ShowAllCatsInHome(mtx);
        }
    }
    addcats_thread.join();
    rmcats_thread.join();
    papper_thread.join();
    snowball_thread.join();
    spot_thread.join();
}
