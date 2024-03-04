/*
 * bst.h
 */

#ifndef BST_H
#define BST_H

struct node {
    int data;
    char* question;
    char* guess;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data, char* question, char* guess); //Function prototype to create a new tree node with specified data, question, and guess

struct node* insert(struct node* root, int data, char* question, char* guess); //Function prototype to insert a new node into the binary tree

#endif
