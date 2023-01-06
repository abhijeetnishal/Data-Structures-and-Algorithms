//fibonacii number: f(n)=f(n-1)+f(n-2)
//f(0)=0, f(1)=1

//Recursion: TC:O(2^n)  SC:O(n)
int fib(int n) {
    if(n==0 || n==1)
        return n;
    return fib(n-1)+fib(n-2);
} 

//Iterative: TC:O(n)  SC:O(N)
int fib(int n) {
    vector<int> dp={0,1};
    for(int i=2;i<=n;i++){
        dp.push_back(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}
