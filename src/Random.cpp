#include "Random.h"
#include <cmath>
#include <random>
namespace ns
{
int Random::Rand() const
{
    std::random_device rd;
    return rd() % 10;
}
Random::Random(const Random& r)
{

}
}