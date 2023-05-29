#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>* RightCElement(int arr[],int n){
    vector<int>* v = new vector<int>;
    stack<int> s;
    s.push(n-1);
    v->push_back(-1);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && arr[s.top()] <= arr[i])s.pop();
        int l = s.empty() ? -1:arr[s.top()];
        s.push(i);
        v->push_back(l);
    }
    reverse(v->begin(),v->end());
    return v;
}

int main(){

    int n;
    cout<<"Enter the number of elements of array:- ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the Array:- \n";
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int>* v = RightCElement(arr,n); 
    for(int x:*v)cout<<x<<" ";
    cout<<endl;
    return 0;
}