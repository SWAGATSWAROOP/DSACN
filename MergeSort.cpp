/*
Merge Sort Code
Send Feedback
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/

#include <iostream>
using namespace std;

void MergeSort(int input[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid = (si+ei)/2;
    MergeSort(input,si,mid);
    MergeSort(input,mid+1,ei);
    int size1 = mid - si + 1;
    int size2 = ei - mid;
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    for(int i=0;i<size1;i++){
        arr1[i] = input[si+i];
    }
    for(int j=0;j<size2;j++){
        arr2[j] = input[mid+j+1];
    }
    int* arr= new int[size1+size2];
    int i=0,j=0,k=0;
    while(i<size1 && j<size2){
        if(arr1[i]>arr2[j]){
            arr[k++] = arr2[j++];
        }
        else{
            arr[k++]=arr1[i++];
        }
    }
    for(;i<size1;i++){
        arr[k++]=arr1[i];
    }
    for(;j<size2;j++){
        arr[k++]=arr2[j];
    }
    for(int i=0;i<size1+size2;i++){
        input[i+si] = arr[i];
    }
    delete[]arr1;
    delete[]arr2;
    delete[]arr;
}

void mergeSort(int input[], int size){
	MergeSort(input,0,size-1);
}

int main() {
  int length;
  cout<<"Enter Array Length:- ";
  cin >> length;
  int* input = new int[length];
  cout<<"Enter Array Elements:- "<<endl;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
  cout<<endl;
  delete[]input;
}