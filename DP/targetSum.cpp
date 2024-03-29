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
/*
let us say we have the array as [1,1,1,1,1] and the target = 3;
We just need to add (+ or -) signs in front of the integers.

e.g +1 +1 +1 -1 -1 = 3

Essentially, what we are doing is that we are just splitting the numbers into two subsets, 
one with positive signs and the other with negative signs

(1 , 1 , 1) => with positive signs
(1 , 1) => with negative signs

and we are calculating the difference of the sum of these two sets
(1 , 1 , 1) => with positive signs , sum = 3
(1 , 1) => with negative signs , sum = 2

diff = target = (3-2) = 1

So we just need to find all such pairs of subsets whose sum difference is equal to our given target.

Consider S1 and S2 to be one such pair then the following equations holds

S1 - S2 = target
S1 + S2 = sum of all the elements

By simplifing the above 2 equations we get, 2* S1 = target + Sum of all the elements

=> S1 = (target + Sum of all the elements) / 2

So, this problem now reduces to just finding count of subsets which are having sum equal to S1.

*/

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

