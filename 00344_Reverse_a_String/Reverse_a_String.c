/*      https://leetcode.com/problems/reverse-string/     */

void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}


void reverseString(char* s, int sSize)
{
    int l = 0, r = sSize - 1;
    while(l < r)
    {
        swap(&s[l], &s[r]);
        l++;
        r--;
    }
}
