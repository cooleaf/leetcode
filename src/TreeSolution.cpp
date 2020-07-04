//
// Created by Xiaoguang Zhao on 7/3/20.
//

#include "TreeSolution.h"

using namespace std;

TreeNode* TreeSolution::sortedArrayToBST(vector<int>& nums)
{
    int count = nums.size();
    if(count == 0) {
        return nullptr;
    }
    TreeNode* root = sortedArrayToBSTImpl(nums, 0, count - 1);
    return root;

}

TreeNode* TreeSolution::sortedArrayToBSTImpl(std::vector<int>& nums, int left, int right) const
{
    if(right < left) {
        return nullptr;
    }
    int mid = (left + right) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBSTImpl(nums, left, mid - 1);
    root->right = sortedArrayToBSTImpl(nums, mid+1, right);
    return root;
}
