#include <chrono>
#include <thread>
#include <iostream>
#include "cat.h"

void Cat::GetValues(std::string name, int chance_of_arrival, int avarage_stay_time)
{
    this->name = name;
    this->chance_of_arrival = chance_of_arrival;
    this->avarage_stay_time = avarage_stay_time;
    this->near = false;

    this->WaitingOfArrivel();
}

void Cat::WaitingOfArrivel()
{
    while(this->near == false)
    {
        std::this_thread::sleep_for(std::chrono::minutes(1));
        if ( rand() % 101 <= this->chance_of_arrival)
        {
            this->near = true;
        }
    }

    std::cout << this->name << " is arrived :3";

    this->GoAway();
}

void Cat::GoAway()
{
    int current_stay_time = this->avarage_stay_time;

    while(this->near == true)
    {
        std::this_thread::sleep_for(std::chrono::minutes(1));
        current_stay_time -= 1;
        if(current_stay_time == 0)
        {
            this->near = false;
        }
    }

    std::cout << this->name << " go away :c";
    this->WaitingOfArrivel();
}
