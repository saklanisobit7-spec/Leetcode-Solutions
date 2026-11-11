/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = malloc(100 * sizeof(int));
    struct TreeNode* stack[100];
    int top = -1;
    *returnSize = 0;

    if(root != NULL)
        stack[++top] = root;

    while(top != -1) {
        struct TreeNode* temp = stack[top--];
        ans[(*returnSize)++] = temp->val;

        if(temp->right != NULL)
            stack[++top] = temp->right;

        if(temp->left != NULL)
            stack[++top] = temp->left;
    }

    return ans;

}