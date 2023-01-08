/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
Input: cost = [10,15,20]
Output: 15
*/

//Recursion: TC:O(2^n)  SC:O(n)    //my approach
int minCostOfClimbing(int str,int end,vector<int> &cost){
    if(str>=end)
        return 0;
    return min(cost[str]+minCostOfClimbing(str+1,end,cost),
               cost[str+1]+minCostOfClimbing(str+2,end,cost));
}

int minCostClimbingStairs(vector<int>& cost) {
    vector<int> c=cost;
    c.push_back(0);      //for handling the cost[n] case which is zero because we reach destination.

    return minCostOfClimbing(0,cost.size(),c);
}


//Recursion (another approach):
int minCostOfClimbing(int str,int end,vector<int> &cost){
    if(str==end)
        return 0;
    if(str>end)     //for handling index greater than cost size
        return 10000;
    return min(cost[str]+minCostOfClimbing(str+1,end,cost),
               cost[str]+minCostOfClimbing(str+2,end,cost));
}

int minCostClimbingStairs(vector<int>& cost) {
    return min(minCostOfClimbing(0,cost.size(),cost),
           minCostOfClimbing(1,cost.size(),cost));
}

//Memoization: TC:O(n^2)  SC:O(N)
int minCostOfClimbing(int str,int end,vector<int> &cost,unordered_map<int,int> &mp){
    if(str==end)
        return 0;
    if(str>end)
        return 10000;

    if(mp.find(str)!=mp.end())
        return mp[str];
    
    int oneJump=cost[str]+minCostOfClimbing(str+1,end,cost,mp);
    int twoJump=cost[str]+minCostOfClimbing(str+2,end,cost,mp);
    
    return mp[str]=min(oneJump,twoJump);
}

int minCostClimbingStairs(vector<int>& cost) {
    unordered_map<int,int> mp;
    return min(minCostOfClimbing(0,cost.size(),cost,mp),
           minCostOfClimbing(1,cost.size(),cost,mp));
}

//iterative: TC:O(n)  SC:O(n)
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1);  // dp[i] is minimum cost to reach to i_th floor
    for (int i = 2; i <= n; i++) {
        int jumpOneStep = dp[i - 1] + cost[i - 1];  // Minimum cost if we jump 1 step from floor (i-1)_th to i_th floor
        int jumpTwoStep = dp[i - 2] + cost[i - 2];  // Minimum cost if we jump 2 steps from floor (i-2)_th to i_th floor
        dp[i] = min(jumpOneStep, jumpTwoStep);
    }
    return dp[n];
}
