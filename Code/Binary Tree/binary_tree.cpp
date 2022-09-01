#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *createNode(int data) {
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return (node);
};

//cac thao tac

NODE *insertNode(NODE *root, int value) {
    if (root == NULL) return createNode(value);

    if (root -> data < value) root -> right = insertNode(root -> right, value);
        else root -> left = insertNode(root -> left, value);

    return root;
}
//Tìm nốt kế thừa
NODE *minValueNode(NODE *node) {
    NODE *current = node;
    while (current && current -> left != NULL)
        current = current -> left;
    return current;
}
//Deleting a node
NODE *deleteNode(NODE *root, int value) {
    if (root = NULL) return root;
    //Find the node to be deleted
    if (value < root -> data)
        root -> left = deleteNode(root -> left, value);
    else if (value > root -> data)
        root -> right = deleteNode(root -> right, value);
    else {
        if (root -> left = NULL) {
            NODE *temp = root -> right;
            free(root);
            return temp;
        } else if (root -> right = NULL) {
            NODE *temp = root -> left;
            free(root);
            return temp;
        }

        NODE *temp = minValueNode(root -> right);
        root -> data = temp -> data;
        root -> right = deleteNode(root -> right, temp -> data);
    }
    return root;
}

void traversePreOrder(NODE *root) {
    if(root != NULL) {
        cout << " " << root -> data;
        traversePreOrder(root -> left);
        traversePreOrder(root -> right);
    }
}

void traverseInOrder(NODE *root) {
    if (root != NULL) {
        traverseInOrder(root -> left);
        cout << " " << root -> data;
        traverseInOrder(root -> right);
    }
}

void traversePostOrder(NODE *root) {
    if (root != NULL) {
        traversePostOrder(root -> left);
        traversePostOrder(root -> right);
        cout << " " << root -> data;
    }
}

int main() {
    NODE *root = NULL;

    //Giả sử cho mảng A n roothần tử
    int n = 10;
    int a[n] = {10,4,2,1,7,4,9,11,2,5};
    for (int i = 0; i < n; i++) root = insertNode(root, a[i]);

    //-------------
    cout << "Preorder traversal: ";
    traversePreOrder(root);
    cout << "\nInorder traversal: ";
    traverseInOrder(root);
    cout << "\nPostorder traversal: ";
    traversePostOrder(root);
}


