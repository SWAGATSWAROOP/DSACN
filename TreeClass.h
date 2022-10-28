#include<vector>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data = data;
    }

    ~TreeNode  
};

TreeNode<int>* takeinput(){
    int rootdata;
    cout<<"Enter data: ";
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    cout<<"Enter The number of children: ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child = takeinput();
        root->children.push_back(child);
    }
    return root;
}

template<typename T>
void output(TreeNode<T>* root){
    if(root == 0){
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        output(root->children[i]);
    }
}

