/*
 * bst.c
 */


#include <stdlib.h>
#include <string.h>
#include "bst.h"

//Method to create a new node and initialize its values
struct node* createNode(int data, char* question, char* guess) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->question = strdup(question);
    newNode->guess = strdup(guess);
    newNode->left = NULL; //Initializes the left child pointer to NULL
    newNode->right = NULL; //Initializes the right child pointer to NULL
    return newNode; //Returns the newly created node
}

//Method to insert a newly created node into the binary tree
struct node* insert(struct node* root, int data, char* question, char* guess) {
    if (root == NULL) { //If the tree is empty, create a new node and return it as the root
        return createNode(data, question, guess);
    }

    if (data < root->data) { //If the data is less than the current node's data, insert the new node in left subtree
        root->left = insert(root->left, data, question, guess);
    } else if (data > root->data) { //If the data is greater than the current node's data, insert the new node in right subtree
        root->right = insert(root->right, data, question, guess);
    }
    return root; //Returns the root of the subtree after insertion
}

