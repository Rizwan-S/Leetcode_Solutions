/*   https://leetcode.com/problems/couples-holding-hands/     */

int find(int i, int P[])
{
    if(P[i] == i) return i;
    P[i] = find(P[i], P);
    return P[i];
}

void Union(int i, int j, int P[], int* count)
{
    int x = find(i, P);
    int y = find(j, P);
    if(x != y)
    {
        P[x] = y;
        *count -= 1;
    }
}

int minSwapsCouples(int* row, int rowSize)
{
    int N = rowSize / 2;
    int P[N], count = N;
    for(int i = 0; i < N; i++) P[i] = i;
    for(int i = 0; i < N; i++)
    {
        int a = row[2*i];
        int b = row[2*i + 1];
        Union(a/2, b/2, P, &count);
    }
    return N - count;
}
