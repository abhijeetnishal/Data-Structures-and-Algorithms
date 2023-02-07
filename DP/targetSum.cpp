/*
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and 
then concatenate all the integers.
Return the number of different expressions that you can build, which evaluates to target.

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
*/

//Recursion: TC:O(2^N) 
int targetSum(int n, int target, vector<int> &arr){
    if(n<0){
        if(target==0)
            return 1;
        else
            return 0;
    }
    return targetSum(n-1, target-arr[n], arr)+
            targetSum(n-1, target+arr[n], arr);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    int sum=nums[n-1];

    return targetSum(n-1, target, nums);
}


//Memoization:
//https://leetcode.com/problems/target-sum/solutions/1470377/c-dp-similar-to-count-of-subset-with-given-sum-inspired-by-aditya-verma/?orderBy=most_votes


//Itearative DP:
int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for(int x: nums)
        sum += x;
    if (abs(target) > sum || (sum + target) % 2 != 0){ 
        return 0;
    }
    int s1 = (sum + target)/2;
    int ans = subsetCount(nums,s1);
    return ans;
}

int subsetCount(vector<int>& nums, int s1){
    int n = nums.size();
    int t[n+1][s1+1];
    t[0][0] = 1;
    for(int i=1;i<s1+1;i++)
        t[0][i] = 0;
    for(int i=1;i<n+1;i++)
        for(int j=0;j<s1+1;j++){
            if(nums[i-1] > j)
                t[i][j] = t[i-1][j];
            else
                t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
        }
    
    return t[n][s1];
}

