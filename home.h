#ifndef HOME_H
#define HOME_H
#include <vector>
#include <mutex>
#include "cat.h"

class Home
{
public:
    std::vector<Cat> cats_in_home;

    Home();
    void AddCatInVector(Cat, std::mutex&);
    void RemoveCatFromVector(Cat, std::mutex&);
    void ShowAllCatsInHome(std::mutex&);
};

#endif // HOME_H
