//
// Created by Xiaoguang Zhao on 7/3/20.
//

#include "TreeSolution.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <unordered_set>
using namespace std;

class TestTreeSolution : public ::testing::Test
{
protected:
    TreeSolution ts;
};

TEST_F(TestTreeSolution, give_only_3_items_for_sort)
{
    unordered_set<int> IntSet;

    vector<int> nums{1, 2, 3};

    TreeNode *output = ts.sortedArrayToBST(nums);

    EXPECT_THAT(output, ::testing::Ne(nullptr));
}

TEST_F(TestTreeSolution, give_only_5_items_for_sort)
{
    vector<int> nums{1, 2, 3, 4, 5};

    TreeNode *output = ts.sortedArrayToBST(nums);

    EXPECT_THAT(output, ::testing::Ne(nullptr));
    EXPECT_THAT(output->right->val, ::testing::Eq(4));
    EXPECT_THAT(output->left->val, ::testing::Eq(1));
}
