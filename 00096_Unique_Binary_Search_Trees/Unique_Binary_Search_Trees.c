/*  https://leetcode.com/problems/unique-binary-search-trees/  */


int numTrees(int n){
    
    long long int l = n + 1, r = 2 * n, k = 1;
    long long int f = 1;
    while(k <= n + 1)
    {
        f *= r;
        f /= k;
        k++;
        r--;
    }
    f /= n;    
    return f;
}





unsigned long int catalanDP(unsigned int n) 
{ 
    // Table to store results of subproblems 
    unsigned long int catalan[n+1]; 
  
    // Initialize first two values in table 
    catalan[0] = catalan[1] = 1; 
  
    // Fill entries in catalan[] using recursive formula 
    for (int i=2; i<=n; i++) 
    { 
        catalan[i] = 0; 
        for (int j=0; j<i; j++) 
            catalan[i] += catalan[j] * catalan[i-j-1]; 
    } 
  
    // Return last entry 
    return catalan[n]; 
} 
int numTrees(int n){
    return catalanDP(n);
}
