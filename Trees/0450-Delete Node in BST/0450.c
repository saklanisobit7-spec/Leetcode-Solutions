/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    struct TreeNode *parent = NULL;
    struct TreeNode *current = root;

    // Search for the node
    while(current != NULL && current->val != key) {
        parent = current;

        if(key < current->val)
            current = current->left;
        else
            current = current->right;
    }

    if(current == NULL)
        return root;

    // Case 1: Node has two children
    if(current->left != NULL && current->right != NULL) {
        struct TreeNode *succParent = current;
        struct TreeNode *succ = current->right;

        // Find inorder successor (smallest in right subtree)
        while(succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        current->val = succ->val;

        // Now delete the successor instead
        parent = succParent;
        current = succ;
    }

    // Case 2 and 3: Node has zero or one child
    struct TreeNode *child;

    if(current->left != NULL)
        child = current->left;
    else
        child = current->right;

    // If deleting the root
    if(parent == NULL) {
        root = child;
    }
    else if(parent->left == current) {
        parent->left = child;
    }
    else {
        parent->right = child;
    }

    free(current);

    return root;
}