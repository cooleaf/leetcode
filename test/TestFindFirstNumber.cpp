//
// Created by Xiaoguang Zhao on 2020/6/27.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "NumberSolution.h"
#include <vector>
using std::vector;
class TestFindFirstNumber : public ::testing::Test
{
protected:
    ns::Solution solution;
};


TEST_F(TestFindFirstNumber, testFilterNumber_when_sorted)
{
    vector<int> nums {1,2,3};
    auto output = solution.filterNumsInArray(nums);

    EXPECT_THAT(output, ::testing::ElementsAreArray({1,2,3}));
}

TEST_F(TestFindFirstNumber, testFilterNumber_when_reverse_sorted)
{
    vector<int> nums {3,2,1};
    auto output = solution.filterNumsInArray(nums);

    EXPECT_THAT(output, ::testing::ElementsAreArray({1,2,3}));
}
TEST_F(TestFindFirstNumber, testFilterNumber_when_there_is_negtive_number)
{
    vector<int> nums {3,-1,1};
    auto output = solution.filterNumsInArray(nums);

    EXPECT_THAT(output, ::testing::ElementsAreArray({1,INT_MIN,3}));
}

TEST_F(TestFindFirstNumber, testFilterNumber_when_there_is_large_number)
{
    vector<int> nums {4,-1,1};
    auto output = solution.filterNumsInArray(nums);

    EXPECT_THAT(output, ::testing::ElementsAreArray({1,INT_MIN,INT_MIN}));
}
TEST_F(TestFindFirstNumber, when_list_is_sorted)
{
    vector<int> nums {1, 2, 3};
    int output = solution.firstMissingPositive(nums);

    EXPECT_THAT(output, ::testing::Eq(4));

}
TEST_F(TestFindFirstNumber, when_list_is_reverse_sorted)
{
    vector<int> nums {3,2,1};
    int output = solution.firstMissingPositive(nums);

    EXPECT_THAT(output, ::testing::Eq(4));

}

TEST_F(TestFindFirstNumber, when_list_there_is_negtive_number)
{
    vector<int> nums {3,2,INT_MIN};
    int output = solution.firstMissingPositive(nums);

    EXPECT_THAT(output, ::testing::Eq(1));
}

TEST_F(TestFindFirstNumber, when_list_there_is_large_number)
{
    vector<int> nums {3, 4, 1};
    int output = solution.firstMissingPositive(nums);

    EXPECT_THAT(output, ::testing::Eq(2));
}