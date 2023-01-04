//Program to get prime factors in TC:O(logN) and SC:O(N):
vector<int> getFactors(int n){
    vector<int> fac;
    
    int divisor=2;
    while(n>1)
    {
        if(n%divisor==0) 
        {
            fac.push_back(divisor);
            n=n/divisor;
        }
        else 
            divisor++;
    }
    return fac;
}