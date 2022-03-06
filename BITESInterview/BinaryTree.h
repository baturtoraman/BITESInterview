#pragma once
#include "BinaryTreeInterface.h"

class BinaryTree : public BinaryTreeInterface
{
private:
    void connectionManager(Node* leftNode, Node* rightNode) {

        if (leftNode->left != nullptr) {
            //this if block will be enough for perfect binary tree
            if (leftNode->right != nullptr) {

                leftNode->left->next = leftNode->right;

                if (rightNode != nullptr) {

                    if (rightNode->left != nullptr) {
                        if(rightNode->right != nullptr)
                            rightNode->left->next = rightNode->right;

                        leftNode->right->next = rightNode->left;

                        connectionManager(leftNode->right, rightNode->left);
                        connectionManager(rightNode->left, rightNode->right);
                    }
                    else if (rightNode->right != nullptr) {
                        leftNode->right->next = rightNode->right;

                        connectionManager(leftNode->right, rightNode->right);
                    }
                    else {
                        connectionManager(leftNode->left, leftNode->right);
                    }
                }

                connectionManager(leftNode->left, leftNode->right);
            }
            //if unbalanced subtree, leftNode->right = nullptr and leftNode->left is defined
            else {

                if (rightNode != nullptr) {
                    //rightNode->left != nullptr
                    if (rightNode->left != nullptr) {
                        rightNode->left->next = rightNode->right;

                        leftNode->left->next = rightNode->left;

                        connectionManager(leftNode->left, rightNode->left);
                        connectionManager(rightNode->left, rightNode->right);
                    }
                    //rightNode->right != nullptr
                    else if (rightNode->right != nullptr) {
                        leftNode->left->next = rightNode->right;

                        connectionManager(leftNode->left, rightNode->right);
                    }
                    else {
                        //in case of unbalanced tree, new left and right node are defined for rightNode.
                        
                        if(rightNode->left == nullptr)
                            return;

                        connectionManager(leftNode->left, nullptr);
                    }
                }

            }

        }

        //leftNode.left = nullptr
        else {
            
            if (leftNode->right != nullptr) {
                
                leftNode->next = rightNode;

                if (rightNode != nullptr) {
                    //rightNode->left != nullptr
                    if (rightNode->left != nullptr) {
                        leftNode->right->next = rightNode->left;

                        connectionManager(leftNode->right, rightNode->left);
                        connectionManager(rightNode->left, rightNode->right);
                    }
                    //rightNode->right != nullptr
                    else if (rightNode->right != nullptr) {
                        leftNode->right->next = rightNode->right;

                        connectionManager(leftNode->right, rightNode->right);
                    }
                    else {
                        connectionManager(leftNode->left, leftNode->right);
                    }
                }
                connectionManager(leftNode->right, leftNode->right);
            }
            // leftNode->right = nullptr
            else {

                if (rightNode != nullptr) {

                    if (rightNode->left != nullptr) {
                        rightNode->left->next = rightNode->right;

                        connectionManager(rightNode->left, rightNode->right);
                    }
                    else if (rightNode->right != nullptr) {

                        connectionManager(rightNode->right, nullptr);
                    }
                    else {
                        //if there is no child
                        return;
                    }
                }
                //decision making after if and else if blocks
                if (leftNode == nullptr) {
                    if (rightNode != nullptr) {
                        if (rightNode->right == nullptr)
                            return;
                        else
                            connectionManager(rightNode->right, nullptr);
                    }
                    else {
                        return;
                    }
                }
                else {
                    if (leftNode->left != nullptr) {
                        if (rightNode->right == nullptr)
                            connectionManager(leftNode->left, nullptr);
                        else
                            connectionManager(leftNode->left, rightNode->right);
                    }
                    else
                    {
                        if (rightNode != nullptr) {
                            if (rightNode->right == nullptr)
                                return;
                            else
                                connectionManager(rightNode->right, nullptr);
                        }
                        else {
                            return;
                        }
                    }
                }
            }
        }
    }

public:

    BinaryTree(){}
    ~BinaryTree(){}

	Node* connect(Node* root) override
	{
        //Dont start if root is null
		if (root == nullptr) 
            return root;

		connectionManager(root, nullptr);

		return root;
	}
};