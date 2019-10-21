#ifndef CAT_H
#define CAT_H
#include <string>
#include "home.h"

class Cat
{
private:
    int chance_of_arrival;
    int avarage_stay_time;
    bool near;

    void WaitingOfArrivel(Home);
    void GoAway(Home);
public:
    std::string name;

    void SetValues(std::string, int, int);
};

#endif // CAT_H
