/*   https://leetcode.com/problems/find-all-anagrams-in-a-string/   */


struct node
{
    int index;
    struct node* next;
};

struct node *newNode(int index)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->index = index;
    new->next = NULL;
    return new;
}

void insert(struct node** table, int index, int tc)
{
    if(!table[tc])
    {
        table[tc] = newNode(index);
    }
    else
    {
        struct node *head = table[tc];
        while(head->next) head = head->next;
        head->next = newNode(index);
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char * s, char * p, int* returnSize)
{
    struct node** table = calloc(996,sizeof(struct node*));
    int slen = strlen(s), plen = strlen(p);
    int *ans = (int*)malloc(100000*sizeof(int));
    *returnSize = 0;
    if(slen < plen || slen == 0 || plen == 0) return ans;
    int sc = s[0] - '0', pc = p[0] - '0', prime = 997;
    for(int i = 1; i < plen; i++)
    {
        sc = (sc + s[i] - '0') % prime;
        pc = (pc + p[i] - '0') % prime;
    }
    //printf("sc0: %d pc0: %d ", sc, pc);
    insert(table, 0, sc);
    for(int i = 1; i <= slen - plen; i++)
    {
        sc = (sc + (s[i - 1 + plen] - '0') - (s[i - 1] - '0')) % prime;
        if(sc < 0) sc += prime;
        //printf("sc%d: %d ", i, sc);
        insert(table, i, sc);
    }
    
    struct node *head = table[pc];
    if(!head)
    {
        return ans;
    }
    int flag = 0;
    while(head)
    {
        flag = 0;
        int* alpha = (int*)calloc(26, sizeof(int));
        for(int i = 0; i < plen; i++)
        {
            alpha[s[head->index + i] - 'a'] += 1;
            alpha[p[i] - 'a'] -= 1;
        }
        for(int i = 0; i < 26; i++)
        {
            if(alpha[i] != 0) flag = 1;
        }
        if(flag == 0) 
        {
            ans[*returnSize] = head->index;
            *returnSize += 1;
        }
        head = head->next;
    }
    return ans;
}

