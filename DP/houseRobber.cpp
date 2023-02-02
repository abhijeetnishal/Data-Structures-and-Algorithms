/*
House Robber-1
Given an array representing amount of money of houses. Find the maximum amount of money 
that can be robbed without choosing adjacent houses.

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


*/
//Recusion: TC:O(2^N)  SC:O(N)
int houseRob(int n, vector<int> &arr){
    if(n<0)
        return 0;
    return max(arr[n]+houseRob(n-2,arr), houseRob(n-1,arr));
}

int rob(vector<int>& nums) {
    return houseRob(nums.size()-1,nums);
} 

//Memoiation: TC:O(N)  SC:O(N)
int houseRob(int n, vector<int> &arr, vector<int> &dp){
    if(n<0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=max(arr[n]+houseRob(n-2,arr,dp), houseRob(n-1,arr,dp));
}

int rob(vector<int>& nums) {
    vector<int> dp(nums.size()+1,-1);
    return houseRob(nums.size()-1, nums, dp);
}

//Buttom up DP: TC:O(N)  SC:O(N)
int rob(vector<int>& nums) {
    int n=nums.size();

    if(n==1) //below for loop starts from 2
        return nums[0];
        
    int dp[n];

    dp[0]=nums[0]; //we need i-2 and i-1 value
    dp[1]=max(nums[0] ,nums[1]);

    for(int i=2;i<n;i++){
        dp[i]=max(nums[i]+dp[i-2], dp[i-1]);
    }

    return dp[n-1];
}


/*
House Robber-2
This problem is same as previous but all houses at this place are arranged in a circle.
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Approach: 
we know we need to distinguish Rob the first or do not rob the first
If we rob the first: then we cannot rob the last, so nums[:-1]
if we do not rob the first, then we can rob the last, so nums[1:]
And the final answer is just max of them using the old algorithm.

*/
//Recursion: TC: O(2^N) SC:O(h)
int houseRobber(int curIdx, int lastIdx, vector<int> arr){
    if(curIdx>lastIdx)
        return 0;
    return max(arr[curIdx]+houseRobber(curIdx+2,lastIdx,arr), 
               houseRobber(curIdx+1,lastIdx,arr));
}

int rob(vector<int>& nums) {
    int n=nums.size();

    if(n==1)
        return nums[0];

    int robFirstHouse=houseRobber(0,n-2,nums);
    int robLastHouse=houseRobber(1,n-1,nums);

    return max(robFirstHouse, robLastHouse);
}

//Memoization: TC: O(N) SC:O(N)
int houseRobber(int curIdx, int lastIdx, vector<int> arr, vector<int> &dp){
    if(curIdx>lastIdx)
        return 0;
    if(dp[curIdx]!=-1)
        return dp[curIdx];
    return dp[curIdx]=max(arr[curIdx]+houseRobber(curIdx+2,lastIdx,arr,dp), 
               houseRobber(curIdx+1,lastIdx,arr,dp));
}

int rob(vector<int>& nums) {
    int n=nums.size();

    if(n==1)
        return nums[0];

    vector<int> dp1(n+1,-1), dp2(n+1,-1);

    int robFirstHouse=houseRobber(0,n-2,nums,dp1);
    int robLastHouse=houseRobber(1,n-1,nums,dp2);

    return max(robFirstHouse, robLastHouse);
}
