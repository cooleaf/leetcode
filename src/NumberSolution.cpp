#include "NumberSolution.h"
#include "Random.h"
#include <sstream>
namespace ns{
int Add(int a, int b ) 
{
    return a + b;
}

Game24::Game24(const Random* r) 
{
    random_ = r;
}
std::string Game24::GenerateNumbers()
{
    std::ostringstream os;
    os << random_->Rand() << random_->Rand() << random_->Rand() << random_->Rand();
    return os.str();
}
}
