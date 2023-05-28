#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int n;
    std::cout<<"Enter the number of elements:- ";
    cin>>n;
    int arr[10];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int> s;
    s.push(0);
    std::cout<<"1"<<" ";
    int i = 1;
    while(i<n){
        while(!s.empty() && arr[s.top()]<=arr[i])s.pop();
        if(!s.empty())cout<<i-s.top()<<" ";
        else cout<<i+1<<" ";
        s.push(i);
        i++;
    }
    std::cout<<endl;
    return 0;
}