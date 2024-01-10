#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *searchNode(Node *root, int target){
    if(root == NULL)
        return NULL;
    if(root->data == target)
        return root;
    if(target < root->data)
        return searchNode(root->left, target);
    else
        return searchNode(root->right, target);
}

Node *insertNode(Node *node, int data) {
    if (node == NULL)
        return createNode(data);
    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
}

void inOrder(Node *root) {
    if (root != NULL) {
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
    }
}

void preOrder(Node *root){
    if(root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root){
    if(root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

Node *deleteNode(Node *root, int x){

    if(root == NULL)
    return root;

    if(x > root->data)
        root->right = deleteNode(root->right, x);

    else if(x < root->data)
        root->left = deleteNode(root->left, x);

    else{//(root->data == x)

        if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = root->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(){
    Node *root = NULL;
    int x, choice;

    while(1){
        printf("\n1. Insert a node \n2. Delete a node \n3. List nodes \n4. Search for a node \n5. Exit \nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value of the node to be inserted: ");
                scanf("%d", &x);
                root = insertNode(root, x);
                break;
            case 2:
                printf("Enter the value of the node to be deleted: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                if (root != NULL){
                    printf("The node is deleted and after deleting: \n");
                    inOrder(root);
                }else
                    printf("The node is not found\n");
                break;
            case 3:
                if(root != NULL){
                printf("\nIn-Order Traversal:\nInorder: ");
                inOrder(root);
                printf("\nPre-Order Traversal:\nPreorder: ");
                preOrder(root);
                printf("\nPost-Order Traversal:\nPostorder: ");
                postOrder(root);
                }else 
                    printf("Tree is empty\n");
                break;
            case 4:
                printf("Enter the value of the node to be searched for: ");
                scanf("%d", &x);
                root = searchNode(root, x);
                if (root == NULL)
                    printf("The node is not found\n");
                else
                    printf("Node is found: %d \n", root->data);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}