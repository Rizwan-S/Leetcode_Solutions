/*    https://leetcode.com/problems/find-the-town-judge/    */

int findJudge(int N, int** trust, int trustSize, int* trustColSize)
{
    
    int* p = (int*)malloc(N * sizeof(int));
    int* pc = (int*)calloc(N,sizeof(int));
    for(int i = 0; i < N; i++) p[i] = -1;
    for(int i = 0; i < trustSize; i++)
    {
        p[trust[i][0] - 1] = trust[i][1] - 1;
        pc[trust[i][1] - 1]++;
    }
    for(int i = 0; i < N; i++)
    {
        if(pc[i] == N - 1) return i + 1;
    }
    return -1;
}
