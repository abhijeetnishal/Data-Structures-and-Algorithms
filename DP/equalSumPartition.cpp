/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the 
elements in both subsets is equal or false otherwise.

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

//Recursion  TC: O(2^N)  SC:O(N)
bool equalSumPartition(int n, vector<int> &arr, int sum){
    if(n<0 || sum<0)
        return false;
    if(sum==0)
        return true;
    else
        return equalSumPartition(n-1,arr,sum-arr[n]) |
                equalSumPartition(n-1,arr,sum);
}

bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int i=0;i<nums.size();i++)
        sum+=nums[i];

    if(sum%2!=0)
        return false;
    else
        return equalSumPartition(nums.size()-1,nums,sum/2);
}

//Memoization  TC:O(N*N) SC:O(N*N)
bool equalSumPartition(int n, vector<int> &arr, int sum, vector<vector<int>> &dp){
    if(n<0 || sum<0)
        return false;
    if(sum==0)
        return true;
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    else
        return dp[n][sum]=equalSumPartition(n-1,arr,sum-arr[n],dp) |
                equalSumPartition(n-1,arr,sum,dp);
}

bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int i=0;i<nums.size();i++)
        sum+=nums[i];

    if(sum%2!=0)
        return false;
    else{
        vector<vector<int>> dp(nums.size()+1, vector<int>((sum/2)+1,-1));
        return equalSumPartition(nums.size()-1,nums,sum/2,dp);
    }
}

//Iterative  TC: O(N*N) SC:O(N*N)
