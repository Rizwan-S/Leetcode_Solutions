/*    https://leetcode.com/problems/count-primes/   */

int countPrimes(int n)
{
  if(n <= 1) return 0;
  int m = sqrt(n);
	int counter = 0;
	int* prime = (int*)calloc(n + 1, sizeof(int));
	prime[0] = 1;
	prime[1] = 1;
	for(int i = 2; i < m + 1; i++)
	{
		for(int j = 2; (i*j) < n; j++)
		{
			prime[i*j] = 1;
		}
	}
	for(int i = 2; i < n; i++)
	{
		if(prime[i]==0)
		{
			counter++;
		}
	}
    return counter;
}
