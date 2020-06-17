/*    https://leetcode.com/problems/validate-stack-sequences/   */



bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    if (pushedSize != poppedSize) return false;
    if(pushedSize == 0) return true;
    int stack[pushedSize], top = -1, j = 0;
    for(int i = 0; i < pushedSize; i++)
    {
        stack[++top] = pushed[i];
        if(stack[top] == popped[j])
        { 
            while(top != -1)
            {
                if(stack[top] != popped[j]) break;
                top--;
                j++;
            }
        }
    }
    while(j != poppedSize)
    {
        if(stack[top] == popped[j]) top--;
        j++;
    }
    if(top == -1) return true;
    return false;
}
