/*	https://leetcode.com/problems/daily-temperatures/	*/

int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int* stack = (int*)malloc(TSize*sizeof(int));
    int* result = (int*)malloc(TSize*sizeof(int));
    int stackSize = 0;
    int i;
    
    for(i=TSize-1;i>=0;i--)
    {
        while((stackSize) && (T[stack[stackSize-1]]<=T[i]))
        {
            stackSize--;
        }
        if(stackSize==0)
        {
            result[i] = 0;
        }
        else
        {
            result[i] = stack[stackSize-1]-i;
        }
        stack[stackSize++] = i;
    }
    
    free(stack);
    
    *returnSize = TSize;
    return result;
}