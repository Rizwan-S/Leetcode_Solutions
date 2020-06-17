/*  https://leetcode.com/problems/buddy-strings/  */

bool buddyStrings(char * A, char * B)
{
    int lenA = strlen(A);
    int lenB = strlen(B);
    if(lenA != lenB || lenA == 0) return false;
    int count = 0, dif1 = -1, dif2 = -1;
    for(int i = 0; i < lenA; i++)
    {
        if(A[i] != B[i])
        {
            count++;
            if(dif2 == -1 && dif1 != -1) dif2 = i;
            if(dif1 == -1) dif1 = i;
        }
    }
    if(count > 2 || count == 1) return false;
    if(count == 0)
    {
        int* a = (int*)calloc(26, sizeof(int));
        for(int i = 0; i < lenA; i++)
        {
            a[A[i] - 'a'] += 1;
            if(a[A[i] - 'a'] == 2) return true;
        }
        return false;
    }
    if(count == 2)
    {
        char temp = A[dif1];
        A[dif1] = A[dif2];
        A[dif2] = temp;
        for(int i = 0; i < lenA; i++)
        {
            if(A[i] != B[i]) return false;
        }
        return true;
    }
    return true;
}
