#include <iostream>
#include "home.h"
#include <thread>
#include <chrono>

void Home::AddCatsInVector(Cat allcats[], std::mutex& mtx)
{
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::minutes(1));
        mtx.lock();
        for(int i = 0; i < sizeof(allcats); i++)
        {
            bool find = false;
            if(allcats[i].near == true)
            {
                for(int j = 0; j < this->cats_in_home.size(); j++)
                {
                    if(allcats[i].name == cats_in_home[j].name)
                    {
                        find = true;
                    }
                }

                if(find == false)
                {
                    this->cats_in_home.push_back(allcats[i]);
                }
            }
        }
        mtx.unlock();
    }
}

void Home::RemoveCatsFromVector(Cat allcats[], std::mutex& mtx)
{
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::minutes(1));
        mtx.lock();
        for(int i = 0; i < sizeof(allcats); i++)
        {
            bool find = false;
            if(allcats[i].near == false)
            {
                for(int j = 0; j < this->cats_in_home.size(); j++)
                {
                    if(allcats[i].name == cats_in_home[j].name)
                    {

                        cats_in_home.erase(this->cats_in_home.begin() + j);
                    }
                }
            }
        }
        mtx.unlock();
    }
}

void Home::ShowAllCatsInHome(std::mutex& mtx)
{
    mtx.lock();
    for(int i = 0; i < this->cats_in_home.size(); i++)
    {
        std::cout << this->cats_in_home[i].name << std::endl;
    }
    mtx.unlock();
}
