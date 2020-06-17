/*    https://leetcode.com/problems/keys-and-rooms/     */

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize)
{
    int* stack = (int*)malloc(roomsSize*roomsSize*sizeof(int));
    int top = -1;
    int Phi[roomsSize];
    bool V[roomsSize];
    for(int i = 0; i < roomsSize; i++)
    {
        Phi[i] = -2;
        V[i] = false;
    }
    stack[++top] = 0;
    Phi[0] = -1;
    int u;
    while(top != -1)
    {
        u = stack[top--];
        if(V[u] == false)
        {
            V[u] = true;
            for(int i = 0; i < roomsColSize[u]; i++)
            {
                stack[++top] = rooms[u][i];
                Phi[rooms[u][i]] = u;
            }
        }
    }
    for(int i = 0; i < roomsSize; i++)
    {
        if(Phi[i] == -2) return false;
    }
    return true;
}
