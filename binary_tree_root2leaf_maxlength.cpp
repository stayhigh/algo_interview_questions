#include<iostream>

using namespace std;

struct Node{
    struct Node* left;
    struct Node* right;
    int data;
};


#define MAX(x,y) ((x>y)?(x):(y))

int max_length_path(struct Node* root){
    int root2leaf_path = 0;
    if (root == NULL){  //degenerate case
        return 0;
    } else if ((root->left != NULL && root->left->left == NULL && root->left->right == NULL) || (root->right != NULL && root->right->left == NULL && root->right->right == NULL)){ // base case
        root2leaf_path = 1;
    } else if (root->left != NULL || root->right != NULL){ // get the max length path from left and right subtrees
        root2leaf_path += (1 + MAX(max_length_path(root->left), max_length_path(root->right)));
    } else if (root != NULL && root->left == NULL && root->right == NULL){ // leaf nodes have length 0
        return 0;
    }

    return root2leaf_path;
}

int main(void){
      /* Constructed binary tree is
       *             10
       *            /   \
       *           8      2
       *         /  \    /
       *       3     5  2
       *                                           */
    struct Node *root;
    struct Node n0;
    struct Node n1;
    struct Node n2;
    struct Node n3;
    struct Node n4;
    struct Node n5;

    root = &n0;
    root->data = 10;
    root->left = &n1; 
    root->left->data = 8;

    root->right = &n2; 
    root->right->data = 2;
    root->right->left = &n3;
    root->right->right = NULL;

    root->right->left->data = 2;
    root->right->left->left = NULL;
    root->right->left->right = NULL;

    root->left->left = &n4;
    root->left->left->data = 3;
    root->left->left->left = NULL;
    root->left->left->right = NULL;

    root->left->right = &n5;
    root->left->right->data = 5;
    root->left->right->left = NULL;
    root->left->right->right = NULL;

    int max_length = max_length_path(root);
    cout << "max_length_path: " << max_length << endl;
    return 0;
}
