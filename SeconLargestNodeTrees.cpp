/*
Second Largest Element In Tree
Send Feedback
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
*/


//My Code:
#include<utility>
pair<pair<TreeNode<int>*,TreeNode<int>*>,pair<int,int>> SecondMax(TreeNode<int>* root){
    pair<pair<TreeNode<int>*,TreeNode<int>*>,pair<int,int>> p = {{root,0},{root->data,INT_MIN}};
    for(int i=0;i<root->children.size();i++){
        pair<pair<TreeNode<int>*,TreeNode<int>*>,pair<int,int>> z = SecondMax(root->children[i]);
        if(p.second.second < z.second.first){
            if(p.second.first < z.second.second){
                p = z;
            }
            else if(p.second.first < z.second.first){
                p.second.second = p.second.first;
                p.first.second = p.first.first;
                p.first.first = z.first.first;
                p.second.first = z.second.first;
            }
            else{
                p.second.second = z.second.first;
                p.first.second = z.first.first; 
            }
        }
    }
    return p;
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if(root == 0){
        return 0;
    }
	pair<pair<TreeNode<int>*,TreeNode<int>*>,pair<int,int>> p = SecondMax(root);
    if(p.second.first == p.second.second){ //the line which I forgot due to which testcase 6 failed 
        return 0;
    }
    return p.first.second;
}

//Cn Ta code:-
#include<climits>
template<typename S>
class PairNode
{
    public:
    TreeNode<int>* maxm;
    TreeNode<int>* nextMaxm;
    PairNode()
    {
        maxm = NULL;
        nextMaxm = NULL;
    }
};
PairNode<int> *getSecondMax(TreeNode<int>* root)
{
    PairNode<int> *ans = new PairNode<int>();
    if(root == NULL)
    {
        return ans;
    }
    ans->maxm = root;
    if(ans->nextMaxm == NULL)
        ans->nextMaxm = root;
    
    for(int i = 0;i<root->children.size();i++)
    {
        PairNode<int>* smallAns = getSecondMax(root->children[i]);
        if(smallAns->maxm->data > ans->maxm->data)
        {
            TreeNode<int>* maxm= smallAns->maxm;
            TreeNode<int>* next=NULL;
            if(ans->maxm->data < smallAns->nextMaxm->data and smallAns->nextMaxm->data != maxm->data)
                next=smallAns->nextMaxm;
            else
                next = ans->maxm;
            ans->maxm=maxm;
            ans->nextMaxm=next;
        }
        else
        {
            TreeNode<int>* maxm= ans->maxm;
        	TreeNode<int>* next=NULL;
             if(smallAns->maxm->data > ans->nextMaxm->data or ans->nextMaxm->data==maxm->data)
            {
                next=smallAns->maxm;
            }
            else
            {
                next=ans->nextMaxm;
            }
            ans->maxm=maxm;
            ans->nextMaxm=next;
        }
    }
    return ans;
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) 
{
    if(root == NULL)
        return NULL;
    PairNode<int>* p = getSecondMax(root);
    if(p->maxm->data!=p->nextMaxm->data)
        return p->nextMaxm;
    else
        return NULL;
}