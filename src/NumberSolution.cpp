#include "NumberSolution.h"
#include "Random.h"
#include <sstream>
#include <vector>
#include <cmath>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
namespace ns{
int Add(int a, int b ) 
{
    return a + b;
}
double Solution::myPostivePow(double x, long long n)
{
    double answer = 1.0;
    long long m = 1;
    vector<double> dp (33, 0);
    dp[0] = 1;
    dp[1] = x;
    cout << "x = " << x << ", n = " << n << endl;
    for (size_t i = 1; m <= n; i++) {
        if (dp[i] == 0) {
            dp[i] = dp[i-1] * dp[i-1];
        }
        cout << "i = " << i << ", m = " << m << ", dp[" << i <<"]=" << dp[i] << endl;
        cout << "n & m " << (n & m) << endl;
        if ((n & m)) {
            answer = answer * dp[i];
            cout << ", answer = " << answer;
        }
        cout << endl;
        m = m * 2;

    }
    return answer;

}
double Solution::myPow(double x, int n)
{
    if (std::abs(x) < std::numeric_limits<double>::epsilon() && n != 0) {
        return 0.0;
    }
    if (n == 0 ){
        return 1.0;
    }
    double answer = 0.0;
    long long m = static_cast<long long>(n);
    cout << " m is " << m << endl;
    double x1 = x;
    if (m < 0){
        x1 = 1.0 /x ;
        m = m * -1;
    }
    
    answer = myPostivePow(x1, m);
    return answer; 
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
