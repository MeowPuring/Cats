#ifndef HOME_H
#define HOME_H
#include <vector>
#include <mutex>
#include "cat.h"

class Home
{
public:
    std::vector<Cat> cats_in_home;

    void AddCatsInVector(Cat[], std::mutex&);
    void RemoveCatsFromVector(Cat[], std::mutex&);
    void ShowAllCatsInHome(std::mutex&);
};

#endif // HOME_H
