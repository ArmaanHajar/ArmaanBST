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
    char data;
    BinaryTree* right;
    BinaryTree* left;
    BinaryTree(char newData) {
        data = newData;
        right = NULL;
        left = NULL;
    }
};

void insert(BinaryTree* tree, char newData);
void print(BinaryTree* tree);

int main() {
    char input[10];
    bool running = true;

    while (running == true) {
        cout << "------------------------------------------------------------------" << endl;
        cout << "What Would You Like To Do? (INPUT/GENERATE/PRINT/DELETE/QUIT/HELP)" << endl;

        cin.get(input, 10);
        cin.ignore(1, '\n');

        if (input[1] == 'I' || input[1] == 'i') { // inputs numbers into the tree
            int inputNum;
            bool done = false;
            cout << "Begin Inputting Numbers Between 1-999, Type '0' When Done" << endl;
            while (done == false) { // loops until user is done inputting numbers
                cin >> inputNum;
                cin.ignore(1, '\n');
                if (inputNum >= 1 && inputNum <= 999) {
                    insert(tree, inputNum);
                }
                else if (inputNum == 0) {
                    done = true;
                    cout << "Done Inputting Numbers" << endl;
                }
                 else {
                    cout << "Invalid Input" << endl;
                }
            }
        }
        if (input[1] == 'G' || input[1] == 'g') { // generates numbers from a file
            ifstream numbers;
            numbers.open("numbers.txt");
            // code to take number individually from file and add to tree
            numbers.close();
        }
        if (input[1] == 'P' || input[1] == 'p') { // prints tree in order
            print(tree);
        }
        if (input[1] == 'D' || input[1] == 'd') { // deletes tree or value from the tree

        }
        if (input[1] == 'Q' || input[1] == 'q') { // quits the program
            cout << "Thank you for using the Binary Search Tree Program!" << endl;
            running = false;
        }
        if (input[1] == 'H' || input[1] == 'h') {
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
void insert(BinaryTree* tree, char newData) {
    if (tree == NULL) {
        tree = new BinaryTree(newData);
    }
    else if (newData < tree->data) {
        if (tree->left != NULL) {
            insert(tree->left, newData);
        }
        else {
            tree->left = new BinaryTree(newData);
        }
    }
    else if (newData > tree->data) {
        if (tree->right != NULL) {
            insert(tree->right, newData);
        }
        else {
            tree->right = new BinaryTree(newData);
        }
    }
}

void print(BinaryTree* tree) {
    int indent;
    if (tree == NULL){
        return;
    }
    indent += 10;

    print(tree->right);
    cout << endl;
    for (int i = 10; i < indent; i++) {
        cout << " ";
    }
    cout << tree->data << "\n";
    print(tree->left);
}