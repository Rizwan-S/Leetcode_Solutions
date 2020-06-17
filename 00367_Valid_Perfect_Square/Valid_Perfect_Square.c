/*  https://leetcode.com/problems/valid-perfect-square/  */

bool isPerfectSquare(int num)
{
    for(long long int i = 1; i * i <= num; i++)
    {
        if((num % i == 0) && (num / i == i)) return true;
    }
    return false;
}
