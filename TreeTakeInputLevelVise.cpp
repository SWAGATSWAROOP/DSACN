#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data = data;
    }
};

TreeNode<int>* takeinput(){
    int n;
    cout<<"Enter the root data:- ";
    cin>>n;
    TreeNode<int>* root = new TreeNode<int>(n);
    cout<<"Enter the number of children:-";
    int z;
    cin>>z;
    for(int i=0;i<z;i++){
        TreeNode<int>* child = takeinput();
        root->children.push_back(child);
    }
    return root;
}

template<typename T>
void print(TreeNode<T>* root){
    cout<<root->data<<": ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        print(root->children[i]);
    }
}

TreeNode<int>* TakeinputLevelvise(){
    int rootdata;
    cout<<"Enter root data:-";
    cin>>rootdata;
    queue<TreeNode<int>*> pendingNodes;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        cout<<"Enter the number of children of "<<front->data<<" :-";
        int numchild;
        cin>>numchild;
        pendingNodes.pop();
        for(int i=0;i<numchild;i++){
            int childData;
            cout<<"Enter the data of "<<i<<"th child of "<<front->data<<" : ";
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> toprint;
    toprint.push(root);
    while(!toprint.empty()){
        TreeNode<int>* front = toprint.front();
        toprint.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            if(i==front->children.size()-1){
                cout<<front->children[i]->data;
            }
            else{
            	cout<<front->children[i]->data<<",";
            }
            toprint.push(front->children[i]);
        }
        cout<<endl;
    }
}

template<typename T>
void printAtLevelk(TreeNode<T>* root,int k){
    if(root == 0){
        return;
    }
    else if(k==0){
        cout<<root->data<<", ";
        return;
    }
    else{
        for(int i=0;i<root->children.size();i++){
            printAtLevelk(root->children[i],k-1);
        }
    }
}

int main(){
    TreeNode<int>* root = TakeinputLevelvise();
    printAtLevelk(root,3);
    cout<<endl;
    return 0;
}