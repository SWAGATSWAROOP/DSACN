// Pair sum in a BST
// Send Feedback
// Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
// Note:
// 1. Assume BST contains all unique elements.
// 2. In a pair, print the smaller element first.
// Input Format :
// The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
// The following line of input contains an integer, that denotes the value of S.
// Output format:
// You have to print each pair in a different line (pair elements separated by space). The order of different pairs, to be printed, does not matter.
// Constraints:
// Time Limit: 1 second   
// Sample Input 1:
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// 12
// Sample Output 1:
// 2 10
// 5 7

#include <algorithm>
#include <vector>

vector<int> *Convert(BinaryTreeNode<int> *root, vector<int> *arr = 0) {
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
  if (root->right) {
    arr = Convert(root->right, arr);
  }
  return arr;
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
	if(root==0){
		return;
	}
  vector<int> *arr = Convert(root);
  //sort(arr->begin(), arr->end());
  int j = arr->size() - 1;
  int i = 0;
  while (i < j) {
    int l = arr->at(i) + arr->at(j);
    if (l == s) {
      cout << arr->at(i) << " " << arr->at(j) << endl;
      i++;
      j--;
    } else if (l < s) {
      i++;
    } else {
      j--;
    }
  }
}