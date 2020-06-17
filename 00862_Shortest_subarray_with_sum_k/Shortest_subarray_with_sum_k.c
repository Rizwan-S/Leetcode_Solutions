

int min(int a, int b)
{
    return a < b ? a : b;
}

int shortestSubarray(int* A, int ASize, int K)
{
    if(ASize < 1)return -1;
    int st = 0, en = 0, res = INT_MAX, sum[ASize + 1], q[ASize + 1];
    sum[0] = 0;
    for(int i = 0; i < ASize; ++i) sum[i + 1] = sum[i] + A[i];
    for(int i = 0; i < ASize + 1; ++i)
    {
        if(en == st)q[en++] = i;
        else
        {
            while(en != st && sum[i] <= sum[q[en - 1]]) --en;
            while(en != st && sum[i] - sum[q[st]] >= K)
            {
                res = min(res, i - q[st]);
                ++st;
            }
            q[en++] = i;
        }
    }
    return res == INT_MAX ? -1 : res;
}
