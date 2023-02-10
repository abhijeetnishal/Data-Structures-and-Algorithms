/*
You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and 
every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.

*/

//Recursion: TC:O(2^N) 
int solve(vector<int> &arr, int i){
    if(i >= arr.size()) // if i is greater than size of array
    {
        return 0; // then simply returnn zero
    }
    
    // current 'i' on which we are standing
    int currValue = arr[i];  // current value
    int currSum = arr[i]; // intial make sum as same as value
    int index = i + 1; // index to take elemets, so  i + 1
    
    // while it is the same as the current value, include in our sum
    while(index < arr.size() && arr[index] == currValue)
    {
        currSum += arr[i];
        index++;
    }
    
    // Now, we have to skip all the elements, whose value is equal to
    // currValue + 1
    while(index < arr.size() && arr[index] == currValue + 1)
    {
        index++;
    }
    
    //And lastly, we have two choices-
    //whether to include the sum of this current element in our answer
    // or not include the sum of current element in our answer
    // so we explore all possibility and take maximum of them
    
    return max(currSum + solve(arr, index), solve(arr, i + 1));
    
    // If we decide to take the curr element in our answer, then upto the elemet we skip the next value, we paas that index
    // but if decided no to make this vurrent element then simply paas
    // i + 1
}
int deleteAndEarn(vector<int>& arr) {
    int n = arr.size(); // take the size of the array
    
    // sort the array to get rid of all arr[i] - 1 elements
    sort(arr.begin(), arr.end());
    
    // solve function which give us our final answer
    return solve(arr, 0);
    //                ↑
    //                we start from zero index
}


//Memoization: TC:O(N)
int t[20001]; // declaring 1 d array, to store some already computed results
int solve(vector<int> &arr, int i){
    if(i >= arr.size()) // if i is greater than size of array
    {
        return 0; // then simply returnn zero
    }
    
        // if result is already computed, then return from here
    // this one line which we say to add
    if(t[i] != -1)
    {
        return t[i];
    }
    
    // current 'i' on which we are standing
    int currValue = arr[i];  // current value
    int currSum = arr[i]; // intial make sum as same as value
    int index = i + 1; // index to take elemets, so  i + 1
    
    // while it is the same as the current value, include in our sum
    while(index < arr.size() && arr[index] == currValue)
    {
        currSum += arr[i];
        index++;
    }
    
    // Now, we have to skip all the elements, whose value is equal to
    // currValue + 1
    while(index < arr.size() && arr[index] == currValue + 1)
    {
        index++;
    }
    
    //And lastly, we have two choices-
    //whether to include the sum of this current element in our answer
    // or not include the sum of current element in our answer
    // so we explore all possibility and take maximum of them
    
    return t[i] = max(currSum + solve(arr, index), solve(arr, i + 1));
    
    // If we decide to take the curr element in our answer, then upto the elemet we skip the next value, we paas that index
    // but if decided no to make this vurrent element then simply paas
    // i + 1
}
int deleteAndEarn(vector<int>& arr) {
    int n = arr.size(); // take the size of the array
    
    memset(t, -1, sizeof(t));
    
    // sort the array to get rid of all arr[i] - 1 elements
    sort(arr.begin(), arr.end());
    
    // solve function which give us our final answer
    return solve(arr, 0);
    //                ↑
    //                we start from zero index
}