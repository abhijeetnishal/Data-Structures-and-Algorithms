/*
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