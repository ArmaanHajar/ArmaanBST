/*
 * Author: Armaan Hajar
 * Date: 
 * Description: Binary Search Tree Data Structure
 * Used the Wikipedia to learn how to implement a binary search tree
 * Link: https://en.wikipedia.org/wiki/Binary_search_tree
 */

#include <iostream>

using namespace std;

// Binary Tree struct
struct BinaryTree {
    char data;
    BinaryTree* right;
    BinaryTree* left;
    BinaryTree(char newData) {
        data = newData;
        right = NULL;
        left = NULL;
    }
};
