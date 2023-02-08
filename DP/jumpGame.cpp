/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array 
represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Input: nums = [3,2,1,0,4]
Output: false
*/
//Recursion: TC:O(n^n) SC:O(N)
bool rec(int str, int end, vector<int> &arr){
    if(str==end)
        return true;

    for(int i=str+1; i<=str+arr[str]; i++){
        if(rec(i, end, arr))
            return true;
    }
    
    return false;
}

bool canJump(vector<int>& nums) {
    return rec(0, nums.size()-1, nums);
}

//Memoization: TC:O(N*N) SC:O(N)
bool rec(int str, int end, vector<int> &arr, vector<int> &dp){
    if(str==end)
        return true;

    if(dp[str]!=-1)
        return dp[str];

    for(int i=str+1; i<=str+arr[str]; i++){
        if(rec(i, end, arr, dp))
            return dp[str]=true;
    }
    
    return dp[str]=false;
}

bool canJump(vector<int>& nums) {
    vector<int> dp(nums.size()+1, -1);
    return rec(0, nums.size()-1, nums, dp);
}

//Greedy: TC:O(N) SC:O(1)
//Approach hill and valley.
bool canJump(vector<int>& nums) {
    //it shows at max what index can I reach.
    //initially I can only reach index 0, hence reach = 0
    int reach = 0; 

    for(int idx = 0; idx < nums.size(); idx++) {
        //at every index I'll check if my reach was atleast able to 
        //reach that particular index.
        
        //reach >= idx -> great, carry on. Otherwise, 
        if(reach < idx) return false;
        
        //now as you can reach this index, it's time to update your reach
        //as at every index, you're getting a new jump length.
        reach = max(reach, idx + nums[idx]);
    }
    
    //this means that you reached till the end of the array, wohooo!! 
    return true;
    
}




/*
Jump game-2
Minimum jumps required to reach end index.

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/
//Recusion: TC: O(N!) SC:O(N)
int jump(vector<int>& nums, int pos = 0) {
	if(pos >= size(nums) - 1) 
        return 0;        

	int minJumps = 10001;  // initialising to max possible jumps + 1

	for(int j = 1; j <= nums[pos]; j++)  // explore all possible jump sizes from current position
		minJumps = min(minJumps, 1 + jump(nums, pos + j));     

	return minJumps;
}

//Memoization: TC: O(N*N) SC:O(N)
int jump(vector<int>& nums) {
	vector<int> dp(size(nums), 10001); // initialise all to max possible jumps + 1 denoting dp[i] hasn't been computed yet
	return solve(nums, dp, 0);
}

// recursive solver to find min jumps to reach end
int solve(vector<int>& nums, vector<int>& dp, int pos) {
	if(pos >= size(nums) - 1) 
        return 0;    // when we reach end, return 0 denoting no more jumps required

	if(dp[pos] != 10001) 
        return dp[pos];    // number of jumps from pos to end is already calculated, so just return it

	// explore all possible jump sizes from current position. Store & return min jumps required
	for(int j = 1; j <= nums[pos]; j++)
		dp[pos] = min(dp[pos], 1 + solve(nums, dp, pos + j));       

	return dp[pos];
}

//Iterative dp TC: O(N*N) SC:O(N)
int jump(vector<int>& nums) {
	int n = size(nums);
	vector<int> dp(n, 10001);
	dp[n - 1] = 0;  // start from last index. No jumps required to reach end if we are already here
	// same as above. For each index, explore all jump sizes and use the one requiring minimum jumps to reach end

	for(int i = n - 2; i >= 0; i--) 
		for(int jumpLen = 1; jumpLen <= nums[i]; jumpLen++) 
			dp[i] = min(dp[i], 1 + dp[min(n - 1, i + jumpLen)]);  // min(n-1, i + jumpLen) for bounds handling

	return dp[0];
}

//Approach for greedy: TC:O(N) SC:O(1)
//https://leetcode.com/problems/jump-game-ii/solutions/18028/o-n-bfs-solution/?orderBy=most_votes
int jump(int A[], int n) {
    if(n<2)return 0;
    int level=0,currentMax=0,i=0,nextMax=0;

    while(currentMax-i+1>0){		//nodes count of current level>0
        level++;
        for(;i<=currentMax;i++){	//traverse current level , and update the max reach of next level
        nextMax=max(nextMax,A[i]+i);
        if(nextMax>=n-1)return level;   // if last element is in level+1,  then the min jump=level 
        }
        currentMax=nextMax;
    }
    return 0;
}