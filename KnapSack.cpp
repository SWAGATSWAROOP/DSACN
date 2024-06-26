// Code : Knapsack
// Send Feedback
// A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?
// Input Format :
// The first line of the input contains an integer value N, which denotes the total number of items.

// The second line of input contains the N number of weights separated by a single space.

// The third line of input contains the N number of values separated by a single space.

// The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.
// Output Format :
// Print the maximum value of V that the thief can steal.
// Constraints :
// 1 <= N <= 20
// 1<= Wi <= 100
// 1 <= Vi <= 100

// Time Limit: 1 sec
// Sample Input 1 :
// 4
// 1 2 4 5
// 5 4 8 6
// 5
// Sample Output 1 :
// 13
// Sample Input 2 :
// 5
// 12 7 11 8 9
// 24 13 23 15 16
// 26
// Sample Output 2 :
// 51

//Brute Force
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	if(n == 0){
		return 0;
	}

	if(weights[0] > maxWeight){
		return knapsack(weights+1, values+1, n-1, maxWeight);
	}
	else{
		int a = knapsack(weights+1, values+1, n-1, maxWeight-weights[0]) + values[0];
		int b = knapsack(weights+1,values+1,n-1,maxWeight);

		return max(a,b);
	}
}

//Dynamic
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    // Write your code here
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        output[i] = new int[maxWeight + 1];

    for (int i = 0; i <= n; i++)
        output[i][0] = 0;

    for (int i = 0; i <= maxWeight; i++)
        output[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            if (j < weights[n - i])
                output[i][j] = output[i - 1][j];
            else
                output[i][j] = max(output[i - 1][j - weights[n - i]] + values[n - i], output[i - 1][j]);
        }
    }
    return output[n][maxWeight];
}
