// Pair Sum Binary Tree
// Send Feedback
// Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
// Note:
// 1. Assume the given binary tree contains all unique elements.
// 2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
// The following line of input contains an integer, that denotes the value of S.
// Output Format :
// Print each pair in a new line, as described in the task. 
// Constraints:
// Time Limit: 1 second
// Sample Input 1:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 15
// Sample Output 1:
// 5 10
// 6 9

#include <vector>
#include<algorithm>
vector<int>* Convert(BinaryTreeNode<int> *root, vector<int> *arr = 0) {
  if (root->left == 0) {
    if (arr == 0) {
		arr = new vector<int>;
    }
	arr->push_back(root->data);
	if(root->right){
		arr = Convert(root->right,arr);
	}
	return arr;
  }
  arr = Convert(root->left, arr);
  arr->push_back(root->data);
if (root->right){
  	arr = Convert(root->right, arr);
}
return arr;
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    vector<int>* arr = Convert(root);
	sort(arr->begin(),arr->end());
	int j = arr->size()-1;
	int i=0;
	while(i<j){
		int l = arr->at(i)+ arr->at(j);
		if(l==sum){
			cout<<arr->at(i)<<" "<<arr->at(j)<<endl;
			i++;
			j--;
		}
		else if(l<sum){
			i++;
		}
		else{
			j--;
		}
	}
}