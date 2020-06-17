/*   https://leetcode.com/problems/ransom-note/   */

bool canConstruct(char * ransomNote, char * magazine)
{
    int* a = (int*)calloc(26, sizeof(int));
    int maglen = strlen(magazine), lenran = strlen(ransomNote);
    for(int i = 0; i < maglen; i++)
    {
        a[magazine[i] - 'a'] += 1;
    }
    for(int i = 0; i < lenran; i++)
    {
        a[ransomNote[i] - 'a'] -= 1;
        if(a[ransomNote[i] - 'a'] < 0) return false;
    }
    return true;
}
