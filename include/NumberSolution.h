#ifndef _NUMBER_SOLUTION_H
#define _NUMBER_SOLUTION_H
#include "Random.h"
#include <string>
#include <memory>
#include <vector>
namespace ns {
class Solution
{
public:
    double myPow(double x, int n);
    int firstMissingPositive(std::vector<int>& nums);
    std::vector<int> &filterNumsInArray(std::vector<int> &nums) const;
private:
    double myPostivePow(double x, long long n);

};

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