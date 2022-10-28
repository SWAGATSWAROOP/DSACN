/*
Maximum Profit on App
Send Feedback
You have made a smartphone app and want to set its subscription price such that the profit earned is maximised. There are certain users who will subscribe to your app only if their budget is greater than or equal to your price.
You will be provided with a list of size N having budgets of subscribers and you need to return the maximum profit that you can earn.
Lets say you decide that price of your app is Rs. x and there are N number of subscribers. So maximum profit you can earn is :
 m * x
where m is total number of subscribers whose budget is greater than or equal to x.
Input format :
Line 1 : N (No. of subscribers)
Line 2 : Budget of subscribers (separated by space)
Output Format :
 Maximum profit
Constraints :
1 <= N <= 10^6
1 <=budget[i]<=9999
Sample Input 1 :
4
30 20 53 14
Sample Output 1 :
60
Sample Output 1 Explanation :
Price of your app should be Rs. 20 or Rs. 30. For both prices, you can get the profit Rs. 60.
Sample Input 2 :
5
34 78 90 15 67
Sample Output 2 :
201
Sample Output 2 Explanation :
Price of your app should be Rs. 67. You can get the profit Rs. 201 (i.e. 3 * 67).
*/
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

int maximumProfit(int budget[], int n) {
    MergeSort(budget,0,n-1);
    int i=0,j=n-1;
    int k = n,l = 1;
    int mx;
    while(i<j){
        if(budget[i]*k > budget[j]*l){
            j--;
            l++;
            mx = budget[i]*k;
        }
        else if(budget[i]*k < budget[j]*l){
            i++;
            k--;
            mx = budget[j]*l;
        }
        else{
            j--;
            l++;
            i++;
            k--;
        }
    }
    return mx;
}