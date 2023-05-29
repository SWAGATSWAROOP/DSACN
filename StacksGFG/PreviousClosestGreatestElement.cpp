#include<iostream>
#include<stack>
using namespace std;

int main(){

    int n;
    cout<<"Enter the number of elements int the array: -";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    stack<int> s;
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[s.top()]<=arr[i])s.pop();
        if(s.empty())cout<<"-1"<<" ";
        else cout<<arr[s.top()]<<" ";
        s.push(i);
    }
    cout<<endl;
    return 0;
}