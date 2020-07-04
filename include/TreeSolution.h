//
// Created by Xiaoguang Zhao on 7/3/20.
//

#ifndef LEETCODE_TREESOLUTION_H
#define LEETCODE_TREESOLUTION_H
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class TreeSolution
{
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums);
private:
    TreeNode* sortedArrayToBSTImpl(std::vector<int>& nums, int left, int right) const;

};


#endif //LEETCODE_TREESOLUTION_H
