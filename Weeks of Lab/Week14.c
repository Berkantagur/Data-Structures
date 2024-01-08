// leaf node her zaman 0 değerini verir.
// Right Rotation ortadaki node root olacak.
// -2 veya +2 durumları balance factor, rotation yap
// node -> left or right = NULL, height = 0;
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
struct Node* root = NULL;

int height (root) {
    if (root == NULL) 
        return 0;
    
    return root->height;
}

int max( int a, int b) {
    return (a > b)? a : b ;
};

struct Node* new_node(int root) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = root;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
};

struct Node* right_notation(struct Node* y){
    y->height=max(height(y->left),height(y->right))+1;
    return y;
};

struct Node* left_rotation(struct Node* x){
    struct Node* y=x->right;
    x->right=y->left;
    y->left=x;
    x->height=height(x);
    y->height=height(y);
    return y;
};
struct Node* balanceInsertion(struct Node* node , struct Node **root) {
    int balance = height(node->left) - height(node->right);
    node = right_notation(node);

    if (balance > 1) {
        if (height(node->right) > height(node->left)) {
            node = left_rotation(node);
            } else {
                struct Node *y = node->right;
                node->right = left_rotation(y);
                node = left_rotation(node);
                }
    }

    *root = node;
    return (*root)->data;
}

void postOrder(struct Node* root)
{
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->data);
    }
}

void inOrder(struct Node* root)
{
    if (root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    }
}
 
void preOrder(struct Node* root)
{
    if (root != NULL) {
        printf(" %d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
        
int main(){

    root = insert(root, 21);
    root = insert(root, 24);
    root = insert(root, 30);
    root = insert(root, 9);
    root = insert(root, 4);
    root = insert(root, 14);
    root = insert(root, 28);
    root = insert(root, 18);
    root = insert(root, 15);
    root = insert(root, 10);
    
    printf("\nIn-Order traversal of binary tree is: ");
    inOrder(root);
    printf("\n");
    
    printf("\nPre-Order traversal of binary tree is: ");
    preOrder(root);
    return 0;
}