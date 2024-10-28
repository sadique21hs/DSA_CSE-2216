//Tree max min
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree() {
    int data, choice;
    printf("Enter node value (or 0 if no node): ");
    scanf("%d", &data);

    if (data == 0) {
        return NULL;
    }

    
    struct Node* newNode = createNode(data);

    
    printf("Does node %d have a left child? (1 for yes, 0 for no): ", data);
    scanf("%d", &choice);
    if (choice == 1) {
        newNode->left = buildTree();
    }

    
    printf("Does node %d have a right child? (1 for yes, 0 for no): ", data);
    scanf("%d", &choice);
    if (choice == 1) {
        newNode->right = buildTree();
    }

    return newNode;
}

int findMax(struct Node* root) {
    if (root == NULL) return INT_MIN;

    int root_val = root->data;
    int left_max = findMax(root->left);
    int right_max = findMax(root->right);

    int max_val = root_val;
    if (left_max > max_val) max_val = left_max;
    if (right_max > max_val) max_val = right_max;

    return max_val;
}

int findMin(struct Node* root) {
    if (root == NULL) return INT_MAX;

    int root_val = root->data;
    int left_min = findMin(root->left);
    int right_min = findMin(root->right);

    int min_val = root_val;
    if (left_min < min_val) min_val = left_min;
    if (right_min < min_val) min_val = right_min;

    return min_val;
}

int main() {
    struct Node* root = NULL;
    int choice;

    printf("Press 1 to build the tree, or 0 to exit: ");
    scanf("%d", &choice);

    if (choice == 1) {
        root = buildTree();
        printf("Maximum value in the tree: %d\n", findMax(root));
        printf("Minimum value in the tree: %d\n", findMin(root));
    } else {
        printf("Exiting...\n");
    }

    return 0;
}
