/*
 * Author: Armaan Hajar
 * Date: April 9th, 2023
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
void deleteValueFromTree(BinaryTree* &tree, int value);
void search(BinaryTree* tree, int value);

int main() {
    char input[10];
    bool running = true;
    BinaryTree* tree = NULL;

    while (running == true) { // loops until user quits the program
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "What Would You Like To Do? (INPUT/GENERATE/PRINT/DELETE/SEARCH/QUIT/HELP)" << endl;

        cin.get(input, 10);
        cin.ignore(1, '\n');

        if (input[0] == 'I' || input[0] == 'i') { // inputs numbers into the tree
            int inputNum;
            bool done = false;
            cout << "Begin Inputting Numbers Between 1-999, Type '0' When Done" << endl;
            while (done == false) { // loops until user is done inputting numbers
                cin >> inputNum;
                cin.ignore(1, '\n');
                if (inputNum >= 1 && inputNum <= 999) { // checks if input is valid
                    BinaryTree* newNode = new BinaryTree(inputNum);
                    insert(tree, newNode);
                }
                else if (inputNum == 0) { // checks if user is done inputting numbers
                    done = true;
                }
                 else { // if input is invalid
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
            cout << "What Value Would You Like To Delete From The Tree" << endl;
            int deleteValue;
            cin >> deleteValue;
            cin.ignore(1, '\n');
            deleteValueFromTree(tree, deleteValue);
        }
        if (input[0] == 'S' || input[0] == 's') { // searches for a value in the tree
            int searchValue;
            cout << "What Value Would You Like To Search For?" << endl;
            cin >> searchValue;
            cin.ignore(1, '\n');
            search(tree, searchValue);
        }
        if (input[0] == 'Q' || input[0] == 'q') { // quits the program
            cout << "Thank you for using the Binary Search Tree Program!" << endl;
            running = false;
        }
        if (input[0] == 'H' || input[0] == 'h') { // displays help message
            cout << "INPUT: Allows you to input numbers to be added to the tree" << endl;
            cout << "GENERATE: Generates numbers from a file of numbers to be added to the tree" << endl;
            cout << "PRINT: Prints the tree in order" << endl;
            cout << "DELETE: Deletes a specified value from the tree" << endl;
            cout << "SEARCH: Searches for a specified value in the tree" << endl;
            cout << "QUIT: Quits the program" << endl;
            cout << "HELP: Displays this message" << endl;
        }
    }
}

// left is smaller, right is bigger
void insert(BinaryTree* &tree, BinaryTree* newData) { // inserts a new node into the tree
    if (tree == NULL) { // if the tree is empty
        tree = newData;
    }
    else if (newData->data < tree->data) { // if the new data is less than the current node, go left
        insert(tree->left, newData);
    }
    else if (newData->data > tree->data) { // if the new data is greater than the current node, go right
        insert(tree->right, newData);
    }
}

void print(BinaryTree* tree, int indent) { // prints the tree in order
    if (tree == NULL) { // if the tree is empty
        return;
    }
    indent += 10;

    print(tree->right, indent); // prints the right side of the tree
    cout << endl;
    for (int i = 10; i < indent; i++) { // prints the indent
        cout << " ";
    }
    cout << tree->data << endl;
    print(tree->left, indent); // prints the left side of the tree
}

void deleteValueFromTree(BinaryTree* &tree, int value) { // deletes a value from the tree
    if (tree == NULL) { // if the tree is empty
        cout << "Value Not Found, No Value Deleted" << endl;
        return;
    }
    else if (value < tree->data) { // if value is less than the current node, go left
        deleteValueFromTree(tree->left, value);
    }
    else if (value > tree->data) { // if value is greater than the current node, go right
        deleteValueFromTree(tree->right, value);
    }
    else if (value == tree->data) { // if value is equal to the current node, delete it
        if (tree->left == NULL && tree->right == NULL) { // if the node has no children
            cout << "Deleted Value: " << value << endl;
            delete tree;
            tree = NULL;
        }
        else if (tree->left == NULL) { // if the node has one child to the right
            cout << "Deleted Value: " << value << endl;
            BinaryTree* temp = tree;
            tree = tree->right;
            delete temp;
        }
        else if (tree->right == NULL) { // if the node has one child to the left
            cout << "Deleted Value: " << value << endl;
            BinaryTree* temp = tree;
            tree = tree->left;
            delete temp;
        }
        else { // if the node has two children
            cout << "Deleted Value: " << value << endl;
            BinaryTree* temp = tree->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            tree->data = temp->data;
            deleteValueFromTree(tree->right, temp->data);
        }
    }
    else { // if the value is not in the tree
        cout << "Value Not Found, No Value Deleted" << endl;
    }
}

void search(BinaryTree* tree, int value) { // searches for a value in the tree
    if (tree == NULL) { // if the tree is empty
        cout << "Value Not Found" << endl;
        return;
    }
    else if (value < tree->data) { // if value is less than the current node, go left
        search(tree->left, value);
    }
    else if (value > tree->data) { // if value is greater than the current node, go right
        search(tree->right, value);
    }
    else if (value == tree->data) { // if value is equal to the current node, delete it
        cout << "Value Found: " << value << endl;
    }
    else { // if the value is not in the tree
        cout << "Value Not Found" << endl;
    }
}