#ifndef CAT_H
#define CAT_H
#include <string>

class Cat
{
private:
    int chance_of_arrival;
    int avarage_stay_time;

    void WaitingOfArrivel();
    void GoAway();
public:
    std::string name;
    bool near;

    void SetValues(std::string, int, int);
};

#endif // CAT_H
