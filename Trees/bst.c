#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Find minimum value node
struct Node* minimum(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Find maximum value node
struct Node* maximum(struct Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

// Delete a node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search a node
bool search(struct Node* root, int key) {
    if (root == NULL)
        return false;
    if (key == root->data)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Traversal functions
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Level order traversal
void levelorder(struct Node* root) {
    if (root == NULL)
        return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);
        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
}

// Height of tree
int height(struct Node* root) {
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

// Size of tree
int size(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

// Find parent of a node
struct Node* findParent(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return NULL;
    if ((root->left && root->left->data == key) ||
        (root->right && root->right->data == key))
        return root;
    if (key < root->data)
        return findParent(root->left, key);
    else
        return findParent(root->right, key);
}

// Check if tree is balanced
bool isBalanced(struct Node* root) {
    if (root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}

// Check if valid BST
bool isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL)
        return true;
    if (root->data <= min || root->data >= max)
        return false;
    return isBSTUtil(root->left, min, root->data) && 
           isBSTUtil(root->right, root->data, max);
}

bool isBST(struct Node* root) {
    return isBSTUtil(root, -100000, 100000);
}

// Menu-driven main function
int main() {
    struct Node* root = NULL;
    int choice, value;
    printf("\n=== Binary Search Tree Operations ===\n");
    do {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Preorder\n6. Postorder\n");
        printf("7. Level Order\n8. Height\n9. Size\n10. Minimum\n11. Maximum\n");
        printf("12. Find Parent\n13. Is Balanced?\n14. Is BST?\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                printf(search(root, value) ? "Found\n" : "Not Found\n");
                break;
            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("Level Order: ");
                levelorder(root);
                printf("\n");
                break;
            case 8:
                printf("Height of tree: %d\n", height(root));
                break;
            case 9:
                printf("Size of tree: %d\n", size(root));
                break;
            case 10:
                if (root) printf("Minimum value: %d\n", minimum(root)->data);
                else printf("Tree is empty\n");
                break;
            case 11:
                if (root) printf("Maximum value: %d\n", maximum(root)->data);
                else printf("Tree is empty\n");
                break;
            case 12:
                printf("Enter value to find parent: ");
                scanf("%d", &value);
                {
                    struct Node* parent = findParent(root, value);
                    if (parent)
                        printf("Parent of %d is %d\n", value, parent->data);
                    else
                        printf("Parent not found or node is root\n");
                }
                break;
            case 13:
                printf(isBalanced(root) ? "Tree is balanced\n" : "Tree is not balanced\n");
                break;
            case 14:
                printf(isBST(root) ? "Tree is a valid BST\n" : "Tree is not a valid BST\n");
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
    return 0;
}
