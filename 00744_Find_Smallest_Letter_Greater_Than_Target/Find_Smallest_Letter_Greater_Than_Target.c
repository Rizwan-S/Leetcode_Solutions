/*   https://leetcode.com/problems/find-smallest-letter-greater-than-target/    */

char nextGreatestLetter(char* letters, int lettersSize, char target)
{
    int i;
    for(int i = 0; i < lettersSize; i++)
    {
        if(target < letters[i]) return letters[i];
    }
    return letters[0];
}
