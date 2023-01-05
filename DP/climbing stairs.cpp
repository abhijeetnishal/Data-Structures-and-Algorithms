/*
Introduction:

Dynamic programming is a technique to solve problems by breaking it down into a collection of sub-problems, solving each of those sub-problems just once and 
storing these solutions inside the cache memory in case the same problem occurs the next time.

Dynamic Programming is mainly an optimization over plain recursion.
Wherever we see a recursive solution that has repeated calls for same inputs, we can optimize it using Dynamic Programming. 

There are two different ways to store our values so that they can be reused at a later instance. They are as follows:
1. Memoization or the Top Down Approach.
2. Tabulation or the Bottom Up approach.

In Memoization we start from the extreme state and compute result by using values that can reach the destination state i.e the base state.

In Tabulation we start from the base state and then compute results all the way till the extreme state.

You can use DP if the problem can be,
1. Divided into sub-problems
2. Solved using a recursive solution 
3. Containing repetitive sub-problems
*/


//Q. Given value n, we need to find no. of ways to reach n with jumps possible are 1 or 2.

//Recursion: TC:O(2^n)  SC:O(n)
int climbingStairs(int str,int end){
    if(str==end)
        return 1;
    if(str>end)
        return 0;
    
    return climbingStairs(str+1,end)+climbingStairs(str+2,end);
}

int climbStairs(int n) {
    return climbingStairs(0,n);
}

//Memoization: TC:O(n^2)  SC:O((n^2)
int climbingStairs(int str,int end,vector<vector<int>> &dp){
    if(str==end)
        return 1;
    if(str>end)
        return 0;
    if(dp[str][end]!=-1)
        return dp[str][end];
    
    return dp[str][end]=climbingStairs(str+1,end,dp)+climbingStairs(str+2,end,dp);
}

int climbStairs(int n) {
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return climbingStairs(0,n,dp);
}

//Iterative: TC:O(n)  SC:O(n)
/*
we observed that current ans is sum of prev two answer:
dp[3]=dp[2]+dp[1]=2+1=3

so we can simply add previously calculated value.
*/
int climbStairs(int n) {
    if(n==1)
        return 1;

    int dp[n+1];
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];

    return dp[n];
}
