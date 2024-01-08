#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

struct Node* root = NULL;

int height(struct Node* root) {
    if (root == NULL)
        return 0;

    return root->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct Node* new_node(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

struct Node* right_rotation(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node* left_rotation(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct Node* balanceInsertion(struct Node* node, int data) {
    if (node == NULL) {
        return new_node(data);
    }

    if (data < node->data) {
        node->left = balanceInsertion(node->left, data);
    } else if (data > node->data) {
        node->right = balanceInsertion(node->right, data);
    } else {
        // Duplicate data not allowed
        return node;
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = height(node->left) - height(node->right);

    // Left Left Case
    if (balance > 1 && data < node->left->data) {
        return right_rotation(node);
    }
    // Right Right Case
    if (balance < -1 && data > node->right->data) {
        return left_rotation(node);
    }
    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = left_rotation(node->left);
        return right_rotation(node);
    }
    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = right_rotation(node->right);
        return left_rotation(node);
    }

    return node;
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->data);
    }
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf(" %d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node* root){
    if (root != NULL) {
       postOrder(root->left);
       postOrder(root->right);
       printf(" %d ", root->data); 

    }
}

int main() {
    struct Node *root = NULL;
    root = balanceInsertion(root, 21);
    root = balanceInsertion(root, 24);
    root = balanceInsertion(root, 30);
    root = balanceInsertion(root, 9);
    root = balanceInsertion(root, 4);
    root = balanceInsertion(root, 14);
    root = balanceInsertion(root, 28);
    root = balanceInsertion(root, 18);
    root = balanceInsertion(root, 15);
    root = balanceInsertion(root, 10);

    printf("\nIn-Order traversal of binary tree is: \n");
    postOrder(root);
    printf("\n");

    printf("\nIn-Order traversal of binary tree is: \n");
    inOrder(root);
    printf("\n");

    printf("\nPre-Order traversal of binary tree is: \n");
    preOrder(root);
    printf("\n");

    return 0;
}