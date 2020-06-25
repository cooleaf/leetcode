#ifndef _RANDOM_SOLUTION_H
#define _RANDOM_SOLUTION_H
namespace ns
{
class Random
{
public:
    Random() = default;
    Random(const Random& r);
    virtual ~Random(){};
    virtual int Rand() const;
};
}
#endif