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

