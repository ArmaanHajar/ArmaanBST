/*
 * Author: Armaan Hajar
 * Date: 
 * Description: Binary Search Tree Data Structure
 * Used the Wikipedia to learn how to implement a binary search tree
 * Link: https://en.wikipedia.org/wiki/Binary_search_tree
 */

#include <iostream>
#include <fstream>

using namespace std;

// Binary Tree struct
struct BinaryTree {
    int data;
    BinaryTree* right;
    BinaryTree* left;
    BinaryTree(int newData) {
        data = newData;
        right = NULL;
        left = NULL;
    }
};

void insert(BinaryTree* &tree, BinaryTree* newData);
void print(BinaryTree* tree, int indent);

int main() {
    char input[10];
    bool running = true;
    BinaryTree* tree = NULL;

    while (running == true) {
        cout << "------------------------------------------------------------------" << endl;
        cout << "What Would You Like To Do? (INPUT/GENERATE/PRINT/DELETE/QUIT/HELP)" << endl;

        cin.get(input, 10);
        cin.ignore(1, '\n');

        if (input[0] == 'I' || input[0] == 'i') { // inputs numbers into the tree
            int inputNum;
            bool done = false;
            cout << "Begin Inputting Numbers Between 1-999, Type '0' When Done" << endl;
            while (done == false) { // loops until user is done inputting numbers
                cin >> inputNum;
                cin.ignore(1, '\n');
                if (inputNum >= 1 && inputNum <= 999) {
                    BinaryTree* newNode = new BinaryTree(inputNum);
                    insert(tree, newNode);
                }
                else if (inputNum == 0) {
                    cout << "Done Inputting Numbers" << endl;
                    done = true;
                }
                 else {
                    cout << "Invalid Input" << endl;
                }
            }
        }
        if (input[0] == 'G' || input[0] == 'g') { // generates numbers from a file
            cout << "Generating Numbers From File" << endl;
            ifstream numbers;
            numbers.open("numbers.txt");
            int newNum;
            while (numbers >> newNum) { // loops until end of file
                BinaryTree* newNode = new BinaryTree(newNum);
                insert(tree, newNode);
            }
            numbers.close();
        }
        if (input[0] == 'P' || input[0] == 'p') { // prints tree
            cout << "Printing Tree" << endl;
            print(tree, 0);
        }
        if (input[0] == 'D' || input[0] == 'd') { // deletes tree or value from the tree

        }
        if (input[0] == 'Q' || input[0] == 'q') { // quits the program
            cout << "Thank you for using the Binary Search Tree Program!" << endl;
            running = false;
        }
        if (input[0] == 'H' || input[0] == 'h') {
            cout << "INPUT: Allows you to input numbers to be added to the tree" << endl;
            cout << "GENERATE: Generates numbers from a file of numbers to be added to the tree" << endl;
            cout << "PRINT: Prints the tree in order" << endl;
            cout << "DELETE: Either deletes the tree or deletes a specified value from the tree" << endl;
            cout << "QUIT: Quits the program" << endl;
            cout << "HELP: Displays this message" << endl;
        }
    }
}

// left is smaller, right is bigger
void insert(BinaryTree* &tree, BinaryTree* newData) {
    if (tree == NULL) {
        tree = newData;
    }
    else if (newData->data < tree->data) {
        insert(tree->left, newData);
    }
    else if (newData->data > tree->data) {
        insert(tree->right, newData);
    }
}

void print(BinaryTree* tree, int indent) {
    if (tree == NULL) {
        return;
    }
    indent += 10;

    print(tree->right, indent);
    cout << endl;
    for (int i = 10; i < indent; i++) {
        cout << " ";
    }
    cout << tree->data << endl;
    print(tree->left, indent);
}