// Largest BST
// Send Feedback
// Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
// Output format:
// The first and only line of output contains the height of the largest BST.
// Constraints:
// Time Limit: 1 second
// Sample Input 1:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// Sample Output 1:
// 2

#include<utility>
#include<climits>
pair<pair<int,int>,pair<bool,int>>*   L(BinaryTreeNode<int>* root){
	if(root == 0){
        pair<pair<int, int>, pair<bool, int>> *p =new pair<pair<int, int>, pair<bool, int>>;
        p->first.first = INT_MAX;
        p->first.second = INT_MIN;
        p->second.first = true;
        p->second.second = 0;
		return p;
    }
    pair<pair<int, int>, pair<bool, int>> * p1 = L(root->left);
    pair<pair<int, int>, pair<bool, int>> * p2 = L(root->right);
	int mn = min(root->data,min(p1->first.first,p2->first.first));
    int mx = max(root->data, max(p1->first.second, p2->first.second));
	bool l = false;
	if(root->data > p1->first.second && root->data < p2->first.first && p1->second.first && p2->second.first){
		l = true;
	}
	int h = max(p1->second.second,p2->second.second);
	if(l){
		h += 1;
	}
    pair<pair<int, int>, pair<bool, int>> *p =new pair<pair<int, int>, pair<bool, int>>;
    p->first.first = mn;
    p->first.second = mx;
    p->second.first = l;
    p->second.second = h;
    return p;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
  pair<pair<int, int>, pair<bool, int>> * p = L(root);
  return p->second.second;
}