/*
0/1 Knapsack:
Given weight, profit array and capacity we need to find mxm profit with given capacity.

input
wt:[1, 2, 3]
prof:[4, 5, 1]
capacity=4

output
9

Approach choose or not choose with given capacity for all possibility.
*/
//Recursion: O(2^N) 
int knapsack01(int W,int N,vector<int> &v,vector<int> &w) {
    /* Base case 0 items left or knapsack is full */
    if(N == 0 || W == 0) 
        return 0;

    /* if weight of current element is less than or equal to capacity we can 
    either include or exclude the item. */
    if(w[N] <= W){
         return max(v[N]+knapsack01(W-w[N],N-1,v,w),knapsack01(W,N-1,v,w));
    }

    /* if weight of current element is greater than the capacity we will
    not include it thus returning just the ignoring part. */
    return knapsack01(W,N-1,v,w);
}

//Memoization: O(N*N)
int knapSackrecur(int W,int N,vector<int> &v,vector<int> &w,vector<vector<int>>& dp){
    /* Base case 0 items left or knapsack is full */
    if(N == 0 || W == 0) 
        return 0;

    /* Checking if the result exists in DP */

    if(dp[N][W]!=-1) 
        return dp[N][W];
    
    /* if weight of current element is less than or equal to capacity we can 
    either include or exclude the item and store it to DP. */
    if(w[N] <= W){
         return dp[N][W] = max(v[N]+knapSackrecur(W-w[N],N-1,v,w,dp),knapSackrecur(W,N-1,v,w,dp));
    }
    /* if weight of current element is greater than the capacity we will
    not include it thus returning just the ignoring part and storing it to DP. */
    return dp[N][W] = knapSackrecur(W,N-1,v,w,dp);
}
int knapsack01(int W,int N,vector<int> &v,vector<int> &w) {
    // Defining Dp and initializing with -1.
    vector<vector<int>> dp(N+1,vector<int> (W+1,-1)); 
    return knapSackrecur(W,N-1,v,w,dp);
}

//Iterative DP:
int knapsack01(int W,int N,vector<int> &v,vector<int> &w) {
    int DP[N+1][W+1]; // Defining DP 
    /* If there is no space left that is W reaches 0 then DP[i][0] 
    for every i will be 0.*/
    for(int i=0;i<N+1;i++) DP[i][0] = 0;
    /* If there are no items left that is N reaches 0 then DP[0][i] 
    for every i will be 0.*/
    for(int i=0;i<W+1;i++) DP[0][i] = 0;

    for(int i=1;i<N+1;i++){
        for(int j=1;j<W+1;j++){
            if(w[i-1] <= j){
                /* Taking max of both the cases i.e to take that 
                item or to ignore it.*/
                DP[i][j] = max(v[i-1]+DP[i-1][j-w[i-1]],DP[i-1][j]); 
            }
            else{
                /* If the weight of current element is greater 
                than the space left in the bag we'll ignore it.*/
                DP[i][j] = DP[i-1][j];
            }
        }
    }
    /* returning answer for W space and N items */
    return DP[N][W]; 
}
