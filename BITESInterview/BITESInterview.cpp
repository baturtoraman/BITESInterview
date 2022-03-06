#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cctype>

#include "MaxNumber.h"
#include "Node.h"
#include "BinaryTree.h"
#include "Sqrt.h"

//Prints the Result For Question 1
void printResult(vector<int> nums) {
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        cout << *it << "\n";
}

//Reads Data continuously, Runs the Program, Asks For Rerun For Question 1
void RunQ1(vector<int>& v, int &k) 
{
    int num = NULL;
    char ch = NULL;

    vector<int> result;
    
    do {

        printf("To start execution, press any letter on keyboard after entering the input data\n");
        while (true)
        {
            if (scanf("%d", &num) > 0 && v.size() <= 100000) {
                if (num < 10000 && num > -10000)
                    v.push_back(num);
                else
                    printf("Out of Bound.. The number has not been added to the container");
            }
            else {
                printf("You did not enter a number, program will start calculation.\n");
                fseek(stdin, 0, SEEK_END); //Clear the buffer
                break;
            }
        }

        if (!v.empty()) {
            printf("Enter the window size: ");
            if (scanf("%d", &k) > 0) {
                if (k > v.size())
                    k = 0;
            }
            else {
                printf("You did not enter a number, program will not start\n");
            }

            if (k != 0) {
                unique_ptr<MaxNumberInterface> maxNumVec(new MaxNumber());
                result = maxNumVec->getSolution(v, k);
                printf("The result is: \n");
                printResult(result);

            }

        }
        else {
            printf("You did not enter any number, the process did not start..\n");
        }

        printf("Do you want to rerun the application? \nPress y for YES: ");

        cin >> ch;

        v.clear();
        num = NULL;

    } while (toupper(ch) == 'Y');
}
void deleteTree(Node* node)
{
    if (node == NULL) return;

    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
    node = NULL;
}
void RunQ2() {

    printf("Example input has been given to the program.\nYou need to enter the data manually by changing the following code lines\n");
    
    //Create example tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->right->right = new Node(15);

    unique_ptr<BinaryTreeInterface> bt(new BinaryTree());

    bt->connect(root);
    cout << root->val << " ";
    cout << root->left->val<<" ";
    cout << root->left->next->val << " ";
    cout << root->left->left->val << " ";
    cout << root->left->left->next->val << " ";
    cout << root->left->left->next->next->val << " ";
    cout << root->left->left->next->next->next->val << " ";
    cout << root->left->left->left->val << " ";
    cout << root->left->left->left->next->val << " ";
    cout << root->left->left->left->next->next->val << " ";
    cout << root->left->left->left->next->next->next->val << " ";
    cout << root->left->left->left->next->next->next->next->val << " "<<endl;

    deleteTree(root);
    printf("The tree has been deleted..\n");

}

void RunQ3() {
    Sqrt* s = new Sqrt();
    cout << s->mySqrt(122) << endl;
    delete s;
    s = NULL;
}

int main() {

    vector<int> v;
    int k = NULL;
    int key = NULL;

    do {
        printf("Enter 1 for running Q1\nEnter 2 for running Q2\nEnter 3 for running Q3\nPress a letter or number bigger than 3 from keyboard to terminate the program: ");

        if (scanf("%d", &key) > 0 && key > 0 && key < 4) {
            if (key == 1) {
                RunQ1(v, k);
            }
            else if (key == 2) {
                RunQ2();
            }
            else {
                RunQ3();
            }
        }
        else {
            printf("The program has been terminated.\n");
            break;
        }
    
    } while (true);

    return 0;
}