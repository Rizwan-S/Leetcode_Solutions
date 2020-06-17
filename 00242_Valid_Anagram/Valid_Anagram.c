/* https://leetcode.com/problems/valid-anagram/ */

bool isAnagram(char * s, char * t)
{
    if(strlen(s) != strlen(t)) return false;
    int* a = (int *)malloc(26*sizeof(int));
    int l = strlen(s);
    for(int i = 0; i < 26; i++) 
    {
        a[i] = 0;
    }
    for(int i = 0; i < l; i++)
    {
        a[s[i] - 'a']++;
    }
    for(int i = 0; i < l; i++)
    {
        a[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++)
    {
        if(a[i] != 0)
        {
            return false;
        }
    }
    return true;
}
