# Binary Search Tree (BST) Implementation in C

A comprehensive implementation of Binary Search Tree data structure with various operations including insertion, deletion, searching, and traversal methods.

## 🌳 Overview

A Binary Search Tree is a hierarchical data structure where each node has at most two children, and it maintains the following properties:
- All nodes in the left subtree have values less than the parent node
- All nodes in the right subtree have values greater than the parent node
- Both subtrees are also valid Binary Search Trees
- No duplicate values are allowed

## 📊 Data Structure

```c
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
```

## 🔧 Functions Reference

### Node Creation

#### `createNode(int data)`
- **Type:** Utility Function
- **Time Complexity:** O(1)
- **Space Complexity:** O(1)
- **Description:** Allocates memory and creates a new node with the specified data value. Initializes left and right pointers to NULL.
- **Parameters:** `data` - integer value to store in the node
- **Returns:** Pointer to the newly created node

---

### Insertion Operations

#### `insert(struct Node* root, int data)`
- **Type:** Modification Function
- **Time Complexity:** 
  - Average: O(log n)
  - Worst: O(n)
  - Best: O(1)
- **Space Complexity:** O(h) - recursive stack space
- **Description:** Inserts a new node with the given value into the BST while maintaining the binary search tree property. Uses recursive approach.
- **Parameters:** 
  - `root` - pointer to the root node
  - `data` - value to insert
- **Returns:** Updated root pointer

---

### Search Operations

#### `search(struct Node* root, int key)`
- **Type:** Query Function
- **Time Complexity:**
  - Average: O(log n)
  - Worst: O(n)
  - Best: O(1)
- **Space Complexity:** O(h) - recursive stack
- **Description:** Searches for a node containing the specified key value in the BST.
- **Parameters:**
  - `root` - pointer to the root node
  - `key` - value to search for
- **Returns:** Pointer to the node if found, NULL otherwise

#### `findMin(struct Node* root)`
- **Type:** Query Function
- **Time Complexity:**
  - Average: O(log n)
  - Worst: O(n)
  - Best: O(1)
- **Space Complexity:** O(1) or O(h) depending on implementation
- **Description:** Finds the node with the minimum value in the tree by traversing to the leftmost node.
- **Returns:** Pointer to the node with minimum value

#### `findMax(struct Node* root)`
- **Type:** Query Function
- **Time Complexity:**
  - Average: O(log n)
  - Worst: O(n)
  - Best: O(1)
- **Space Complexity:** O(1) or O(h) depending on implementation
- **Description:** Finds the node with the maximum value in the tree by traversing to the rightmost node.
- **Returns:** Pointer to the node with maximum value

---

### Deletion Operations

#### `deleteNode(struct Node* root, int key)`
- **Type:** Modification Function
- **Time Complexity:**
  - Average: O(log n)
  - Worst: O(n)
  - Best: O(1)
- **Space Complexity:** O(h) - recursive stack
- **Description:** Deletes a node with the specified key from the BST. Handles three cases:
  1. Node with no children (leaf node)
  2. Node with one child
  3. Node with two children (replaces with inorder successor/predecessor)
- **Parameters:**
  - `root` - pointer to the root node
  - `key` - value of the node to delete
- **Returns:** Updated root pointer after deletion

---

### Traversal Operations

#### `inorderTraversal(struct Node* root)`
- **Type:** Traversal Function
- **Time Complexity:** O(n)
- **Space Complexity:** O(h) - recursive stack
- **Description:** Traverses the tree in Left → Root → Right order. Produces sorted sequence for BST.
- **Output Order:** Sorted ascending order

#### `preorderTraversal(struct Node* root)`
- **Type:** Traversal Function
- **Time Complexity:** O(n)
- **Space Complexity:** O(h) - recursive stack
- **Description:** Traverses the tree in Root → Left → Right order. Useful for creating a copy of the tree.
- **Output Order:** Root first, then subtrees

#### `postorderTraversal(struct Node* root)`
- **Type:** Traversal Function
- **Time Complexity:** O(n)
- **Space Complexity:** O(h) - recursive stack
- **Description:** Traverses the tree in Left → Right → Root order. Useful for deleting the tree.
- **Output Order:** Children first, then root

#### `levelOrderTraversal(struct Node* root)`
- **Type:** Traversal Function
- **Time Complexity:** O(n)
- **Space Complexity:** O(w) - where w is maximum width
- **Description:** Traverses the tree level by level from top to bottom, left to right. Also known as Breadth-First Search (BFS).
- **Output Order:** Level by level

---

### Tree Properties

#### `height(struct Node* root)`
- **Type:** Query Function
- **Time Complexity:** O(n)
- **Space Complexity:** O(h) - recursive stack
- **Description:** Calculates the height of the tree (length of the longest path from root to any leaf). Height of empty tree is -1, single node is 0.
- **Returns:** Integer representing tree height

#### `countNodes(struct Node* root)`
- **Type:** Query Function
- **Time Complexity:** O(n)
- **Space Complexity:** O(h) - recursive stack
- **Description:** Counts the total number of nodes in the tree.
- **Returns:** Integer count of nodes

#### `countLeafNodes(struct Node* root)`
- **Type:** Query Function
- **Time Complexity:** O(n)
- **Space Complexity:** O(h)
- **Description:** Counts the number of leaf nodes (nodes with no children) in the tree.
- **Returns:** Integer count of leaf nodes

---

### Validation & Utility

#### `isBST(struct Node* root)`
- **Type:** Validation Function
- **Time Complexity:** O(n)
- **Space Complexity:** O(h)
- **Description:** Validates whether the given tree satisfies all BST properties. Checks if for every node, all left descendants are smaller and all right descendants are larger.
- **Returns:** Boolean (1 for true, 0 for false)

#### `findSuccessor(struct Node* root, int key)`
- **Type:** Query Function
- **Time Complexity:** O(h)
- **Space Complexity:** O(1)
- **Description:** Finds the inorder successor (next larger element) of a given key in the BST.
- **Returns:** Pointer to successor node or NULL

#### `findPredecessor(struct Node* root, int key)`
- **Type:** Query Function
- **Time Complexity:** O(h)
- **Space Complexity:** O(1)
- **Description:** Finds the inorder predecessor (previous smaller element) of a given key in the BST.
- **Returns:** Pointer to predecessor node or NULL

---

## 📈 Complexity Analysis

### Time Complexity Summary

| Operation | Best Case | Average Case | Worst Case | Notes |
|-----------|-----------|--------------|------------|-------|
| Insert | O(1) | O(log n) | O(n) | Worst case for skewed tree |
| Delete | O(1) | O(log n) | O(n) | Worst case for skewed tree |
| Search | O(1) | O(log n) | O(n) | Worst case for skewed tree |
| Find Min | O(1) | O(log n) | O(n) | Left-most traversal |
| Find Max | O(1) | O(log n) | O(n) | Right-most traversal |
| Inorder Traversal | O(n) | O(n) | O(n) | Visits all nodes |
| Preorder Traversal | O(n) | O(n) | O(n) | Visits all nodes |
| Postorder Traversal | O(n) | O(n) | O(n) | Visits all nodes |
| Level Order Traversal | O(n) | O(n) | O(n) | Visits all nodes |
| Height | O(n) | O(n) | O(n) | Must visit all nodes |
| Count Nodes | O(n) | O(n) | O(n) | Must visit all nodes |
| Validate BST | O(n) | O(n) | O(n) | Must check all nodes |

### Space Complexity Summary

| Operation | Space Complexity | Reason |
|-----------|------------------|--------|
| Insert | O(h) | Recursive call stack |
| Delete | O(h) | Recursive call stack |
| Search | O(h) | Recursive call stack |
| Traversals (Recursive) | O(h) | Recursive call stack |
| Level Order Traversal | O(w) | Queue space (w = max width) |
| Tree Storage | O(n) | n nodes in memory |

**Where:**
- `n` = number of nodes in the tree
- `h` = height of the tree (log n for balanced, n for skewed)
- `w` = maximum width of the tree

### Performance Notes

1. **Balanced Tree**: When the tree is balanced, height h ≈ log n, giving O(log n) for most operations
2. **Skewed Tree**: In worst case (completely unbalanced), height h = n, degrading to O(n) for search, insert, and delete
3. **Self-Balancing**: For guaranteed O(log n) performance, consider AVL or Red-Black Trees

## 📝 Examples

### Example Usage
```c
int main() {
    struct Node* root = NULL;
    
    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    // Traversal
    printf("Inorder: ");
    inorderTraversal(root);  // Output: 20 30 40 50 60 70 80
    
    // Search
    struct Node* found = search(root, 40);
    if (found != NULL) {
        printf("\nFound: %d", found->data);
    }
    
    // Tree properties
    printf("\nHeight: %d", height(root));
    printf("\nTotal Nodes: %d", countNodes(root));
    
    // Delete
    root = deleteNode(root, 30);
    
    return 0;
}
```

### Tree Visualization
```
        50
       /  \
      30   70
     / \   / \
    20 40 60 80
```

## ⚠️ Important Notes

- **No Duplicates**: This implementation does not allow duplicate values
- **Memory Management**: Remember to free allocated memory to prevent memory leaks
- **Worst Case**: Performance degrades to O(n) for skewed trees; consider self-balancing trees for critical applications
- **Recursion Depth**: Deep trees may cause stack overflow in recursive implementations

## 👤 Author

**TEJAS-creator**
- GitHub: [@TEJAS-creator](https://github.com/TEJAS-creator)

**Last Updated:** October 2025
