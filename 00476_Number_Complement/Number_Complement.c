/*  https://leetcode.com/problems/number-complement/  */

int findComplement(int num)
{
    long long int mul = 1;
	long long int ans = 0;
	while(num != 0)
	{
		if(num % 2 == 0) ans += 1 * mul;
		else ans += 0 * mul;
		mul *= 2;
		num /= 2;
	}
	return ans;
}
