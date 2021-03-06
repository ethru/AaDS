#pragma once
#include <iostream>
using namespace std;

int size(node* root){
    if(!root) return 0;
    return 1 + size(root->left) + size(root->right);
}

int height(node* root){
    if(!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int leaves(node* root){
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return leaves(root->left) + leaves(root->right);
}

int nodesOnLevel(node* root, int level){
    if(!root) return 0;
    if(!level) return 1;
    return nodesOnLevel(root->left, level-1) + nodesOnLevel(root->right, level-1);
}

bool isInTree(node* root, int number){
    if(!root) return false;
    if(root->value == number) return true;
    return isInTree(root->left, number) || isInTree(root->right, number);
}

void deleteTree(node* root){
    if(!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void deleteBelow(node*& root, int level){
    if(!root) return;
    if(!level){
        deleteTree(root->left);
        deleteTree(root->right);
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    deleteBelow(root->left, level-1);
    deleteBelow(root->right, level-1);
}

void print(node* root){
    if(root){
        print(root->left);
        cout << root->value << " ";
        print(root->right);
    }
}
