/*   https://leetcode.com/problems/valid-parentheses/   */

bool isValid(char * s)
{
    
    int len = strlen(s);
    if(len == 0) return true;
    if(len % 2 == 1) return false;
    char stack[len];
    int top = -1;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == '{') stack[++top] = '{';
        else if(s[i] == '(') stack[++top] = '(';
        else if(s[i] == '[') stack[++top] = '[';
        else if(s[i] == '}')
        {
            if(top == -1) return false;
            if(stack[top] == '{') top--;
            else return false;
        }
        else if(s[i] == ')')
        {
            if(top == -1) return false;
            if(stack[top] == '(') top--;
            else return false;
        }
        else
        {
            if(top == -1) return false;
            if(stack[top] == '[') top--;
            else return false;
        }
    }
    if(top == -1) return true;
    return false;
}
