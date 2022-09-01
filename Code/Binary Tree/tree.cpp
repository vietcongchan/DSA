#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *newNode(int data) {
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return (node);
};

void traversePreOrder(NODE *temp) {
    if (temp != NULL) {
        cout << " " << temp -> data;
        traversePreOrder(temp -> left);
        traversePreOrder(temp -> right);
    }
}

void traverseInOrder(NODE *temp) {
    if (temp != NULL) {
        traverseInOrder(temp -> left);
        cout << " " << temp -> data;
        traverseInOrder(temp -> right);
    }
}

void traversePostOrder(NODE *temp) {
    if (temp != NULL) {
        traversePostOrder(temp -> left);
        traversePostOrder(temp -> right);
        cout << " " << temp -> data;
    }
}

void Add_Head(NODE *temp) {

}

void Add_Tail(NODE *temp) {

}

int main() {
    NODE *root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);

    cout << "preorder traversal: ";
    traversePreOrder(root);
    cout << "\nInorder traversal: ";
    traverseInOrder(root);
    cout << "\nPostorder traversal: ";
    traversePostOrder(root);
}

