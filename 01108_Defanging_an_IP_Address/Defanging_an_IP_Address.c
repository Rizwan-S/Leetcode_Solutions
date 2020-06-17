/*  https://leetcode.com/problems/defanging-an-ip-address/  */

char * defangIPaddr(char * address)
{
    int len = strlen(address);
    char* ans = (char*)malloc((len + 10)*sizeof(char));
    int k = 0;
    for(int i = 0; address[i] != '\0'; i++)
    {
        if(address[i] == '.')
        {
            ans[k++] = '[';
            ans[k++] = '.';
            ans[k++] = ']';
        }
        else
        {
            ans[k++] = address[i];
        }
    }
    ans[k] = '\0';
    return ans;
}
