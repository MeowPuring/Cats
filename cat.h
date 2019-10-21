#ifndef CAT_H
#define CAT_H
#include <string>

class Cat
{
private:
    std::string name;
    int chance_of_arrival;
    int avarage_stay_time;
    bool near;

    void WaitingOfArrivel();
    void GoAway();
public:
    void GetValues(std::string, int, int);
};

#endif // CAT_H
