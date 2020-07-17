/*	https://leetcode.com/problems/is-graph-bipartite/	*/

bool isBipartite(int** graph, int graphSize, int* graphColSize)
{
    int L[graphSize], head = -1, tail = 0, u;
    int queue[5000];
    for(int i = 0; i < graphSize; i++)
    {
        L[i] = -1;
    }
    for(int i = 0; i < graphSize; i++)
    {
        if(L[i] < 0)
        {
            queue[++head] = i;
            L[i] = 0;
            while(head >= tail)
            {
                u = queue[tail++];
                for(int i = 0; i < graphColSize[u]; i++)
                {
                    if(L[graph[u][i]] < 0)
                    {
                        queue[++head] = graph[u][i];
                        L[graph[u][i]] = L[u] + 1;
                    }
                }
            }
        }
    }
    for(int i = 0; i < graphSize; i++) printf("%d ", L[i]);
    for(int i = 0; i < graphSize; i++)
    {
        for(int j = 0; j < graphColSize[i]; j++)
        {
            if(L[graph[i][j]] % 2 == L[i] % 2) return false;
        }
    }
    return true;
}


