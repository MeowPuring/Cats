#include <iostream>
#include "home.h"

void Home::AddCatInVector(Cat cat, std::mutex& mtx)
{
    mtx.lock();
    this->cats_in_home.push_back(cat);
    mtx.unlock();
}

void Home::RemoveCatFromVector(Cat cat, std::mutex& mtx)
{
    mtx.lock();
    for(int i = 0; i < this->cats_in_home.size(); i++)
    {
        if(cat.name == this->cats_in_home[i].name)
        {
            this->cats_in_home.erase(this->cats_in_home.begin() + i);
        }
    }
    mtx.unlock();
}

void Home::ShowAllCatsInHome(std::mutex& mtx)
{
    mtx.lock();
    for(int i = 0; i < this->cats_in_home.size(); i++)
    {
        std::cout << this->cats_in_home[i].name;
    }
    mtx.unlock();
}
