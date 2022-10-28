#include<iostream>
#include "TreeClass.h"
using namespace std;

void printPreOrder(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        printPreOrder(root->children[i]);
    }
}

int main(){
    TreeNode<int>* root = takeinput();
    printPreOrder(root);
    cout<<endl;
    return 0;
}