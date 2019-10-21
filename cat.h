#ifndef CAT_H
#define CAT_H
#include <string>
#include <mutex>

class Cat
{
private:
    std::string name;
    int chance_of_arrival;
    int avarage_stay_time;
    bool near;

    void WaitingOfArrivel(std::mutex&);
    void GoAway(std::mutex&);
public:
    void GetValues(std::mutex& mtx, std::string, int, int);
};

#endif // CAT_H
