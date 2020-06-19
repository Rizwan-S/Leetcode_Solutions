/*  https://leetcode.com/problems/first-unique-character-in-a-string/  */

int firstUniqChar(char * s)
{
    int len = strlen(s);
    if(len == 0) return -1;
    if(len == 1) return 0;
    int* index = (int*)malloc(26*sizeof(int));
    int* count = (int*)calloc(26,sizeof(int));
    for(int i = 0; i < 26; i++) index[i] = -1;
    for(int i = 0; i < len; i++)
    {
        if(index[s[i] - 'a'] == -1) index[s[i] - 'a'] = i;
        count[s[i] - 'a']++;
    }
    int ans = 2147483647;
    for(int i = 0; i < 26; i++)
    {
        if(count[i] == 1 && index[i] < ans) ans = index[i];
    }
    if(ans == 2147483647) return -1;
    return ans;
}
