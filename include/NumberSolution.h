#ifndef _NUMBER_SOLUTION_H
#define _NUMBER_SOLUTION_H
#include <string>
#include "Random.h"
#include <memory>
namespace ns {

int Add(int a, int b);


class Game24 
{
public:
    Game24() = delete;
    Game24(const Random* r);
    virtual ~Game24() = default;
    virtual std::string GenerateNumbers();
private:
    const Random* random_;
};
}
#endif