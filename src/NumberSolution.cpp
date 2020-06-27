#include "NumberSolution.h"
#include "Random.h"
#include <sstream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <iostream>
using std::vector;
using std::unordered_set;
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
//    cout << "x = " << x << ", n = " << n << endl;
    for (size_t i = 1; m <= n; i++) {
        if (dp[i] == 0) {
            dp[i] = dp[i-1] * dp[i-1];
        }
//        cout << "i = " << i << ", m = " << m << ", dp[" << i <<"]=" << dp[i] << endl;
//        cout << "n & m " << (n & m) << endl;
        if ((n & m)) {
            answer = answer * dp[i];
//            cout << ", answer = " << answer;
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
//    cout << " m is " << m << endl;
    double x1 = x;
    if (m < 0){
        x1 = 1.0 /x ;
        m = m * -1;
    }
    
    answer = myPostivePow(x1, m);
    return answer; 
}

int Solution::firstMissingPositive(vector<int>& nums)
{
    int answer = nums.size() + 1;
    filterNumsInArray(nums);
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < 0 ) {
            answer = i + 1;
            break;
        }
    }
    return answer;
}

vector<int>& Solution::filterNumsInArray(vector<int> &nums) const
{
    size_t count = nums.size();
    for (size_t i = 0; i < count; i++) {
        auto num = nums[i];
        nums[i] = INT_MIN;
        while ((num > 0) && (num <= count)) {
            int j = nums[num - 1];
            if (j != num) {
                nums[num - 1] = num;
                num = j;
            }else{
                break;
            }
        }
    }
    return nums;
}

void Solution::solveSudoku(vector<vector<char>>& board ) const
{
    if (board.size() != 9 || board[0].size() != 9) {
        return;
    }
    backTrackSoduku(board, 0, 0);
}

bool Solution::backTrackSoduku(vector<vector<char>> &board, int lastx, int lasty) const
{
    int x = lastx;
    int y = lasty;
    auto found = foundNextEmptyElement(board, x, y);
    if (!found) {
        return true;
    }
    bool ret = false;
    unordered_set<char> candidates {'1','2','3','4','5','6','7','8','9'};
    for (int i = 0; i < board[x].size(); ++i) {
        candidates.erase(board[x][i]);
    }
    for (int j = 0; j < board.size(); ++j) {
        candidates.erase(board[j][y]);
    }
    int top = (y / 3) * 3;
    int left = (x / 3) * 3;
    for (int i = left; i < left + 3; ++i) {
        for (int j = top; j < top + 3; ++j) {
            candidates.erase(board[i][j]);
        }
    }
    while (!candidates.empty()){
        auto n = *(candidates.begin());
        board[x][y] = n;
        ret = backTrackSoduku(board, x, y);
        if (ret){
            break;
        }
        board[x][y] = '*';
        candidates.erase(n);
    }
    return ret;
}

bool Solution::foundNextEmptyElement(vector<vector<char>> &board, int &x, int &y) const
{
    for (int j = y; j < board[x].size(); ++j) {
        if (board[x][j] == '*') {
            y = j;
            return true;
        }
    }
    for (int i = x + 1; i < board.size(); ++i) {
        for (int j = 0; j < board[x].size(); ++j) {
            if (board[i][j] == '*') {
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
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
