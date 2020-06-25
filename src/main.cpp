#include "NumberSolution.h"
#include "Random.h"
#include <string>
#include <iostream> 


int main() 
{
    ns::Random r;
    int n = r.Rand();
    ns::Add(1,2);
    std::cout << "The random number is " << n << std::endl;
    return 0;
}