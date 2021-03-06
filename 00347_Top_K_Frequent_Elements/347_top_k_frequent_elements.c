/*	https://leetcode.com/problems/top-k-frequent-elements/	*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define SIZE 1001
struct HashArray
{
    int key;
    int count;
    struct HashArray* next;
}Hash[SIZE];       
void addHash(int num)     
{
    int temp=abs(num%SIZE);   
    if(Hash[temp].key==0)
    {
        Hash[temp].key=num;
        Hash[temp].count++;
    }else if(Hash[temp].key==num)
    {
        Hash[temp].count++;  
    }else
    {
        struct HashArray *p=&Hash[temp]; 
        while(p->key!=num&&p->next!=NULL)    
        {p=p->next;}
        if(p->key==num)
        {
            p->count++;
        }
        else
        {
            p->next=(struct HashArray*)malloc(sizeof(struct HashArray));
            p=p->next;
            p->key=num;
            p->count=1;
            p->next=NULL;
        }
    }   
}
int partition(int** array,int low,int high)
{
    int temp_1=array[0][low];
    int temp_2=array[1][low];
    while(low<high)
    {
        while(low<high&&array[0][high]>=temp_1)
        {high--;}
        if(low<high) 
        {
            array[0][low]=array[0][high];
            array[1][low]=array[1][high];
            low++;
        }
        while(low<high&&array[0][low]<temp_1)
        {low++;}
        if(low<high)
        {
            array[0][high]=array[0][low];
            array[1][high]=array[1][low];
            high--;
        }
    }
    array[0][low]=temp_1;
    array[1][low]=temp_2;
    return low;
}
void quick_sort(int** array,int s,int t)
{   
    int i=0;
    if(s<t)
    {
        i=partition(array,s,t);
        quick_sort(array,s,i-1);
        quick_sort(array,i+1,t);
    }
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    for(int i=0;i<SIZE;i++){
        Hash[i].key=0;
        Hash[i].count=0;
        Hash[i].next=NULL;
    }
    *returnSize=0;
    int *ret=(int*)malloc(sizeof(int)*k);
    int **array=(int**)malloc(sizeof(int*)*2);
    array[0]=(int*)calloc(numsSize,sizeof(int));
    array[1]=(int*)calloc(numsSize,sizeof(int));
    int count=0;
    for(int i=0;i<numsSize;i++){
        addHash(nums[i]);   
    }
    for(int i=0;i<SIZE;i++){
        if(Hash[i].count==0)
        {
            continue;
        }
        else 
        {
            array[0][count]=Hash[i].count;  
            array[1][count]=Hash[i].key;
            count++;
            if(Hash[i].next!=NULL){
                struct HashArray *p=Hash[i].next;
                while(p!=NULL){
                    array[0][count]=p->count;  
                    array[1][count]=p->key;
                    count++;
                    p=p->next;
                }
            }
        }
    }
    quick_sort(array,0,count-1);
    int i=count;
    while(*returnSize<k){
        i--;
        ret[(*returnSize)++]=array[1][i];
    }
    return ret;
}




