/*  https://leetcode.com/problems/jewels-and-stones/  */

int numJewelsInStones(char * J, char * S)
{
	int* a = (int*)calloc(26,sizeof(int));
	int* A = (int*)calloc(26,sizeof(int));
    int lenJ = strlen(J), lenS = strlen(S);
    for(int i = 0; i < lenS; i++)
    {
        if(S[i] - '0' > 48) a[S[i] - 'a'] += 1;
        else A[S[i] - 'A'] += 1;
    }
    int ans = 0;
    for(int i = 0; i < lenJ; i++)
    {
        if(J[i] - '0' > 48) ans += a[J[i] - 'a'];
        else ans += A[J[i] - 'A'];
    }
    return ans;
}
