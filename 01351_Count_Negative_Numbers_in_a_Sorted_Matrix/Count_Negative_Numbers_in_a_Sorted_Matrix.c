/*   https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/   */

int countNegatives(int** grid, int gridSize, int* gridColSize)
{
    int ans = 0;
    for(int i = 0; i < gridSize; i++)
    {
        int m = gridColSize[i] - 1;
        while(m >= 0)
        {
            if(grid[i][m] < 0) ans++;
            else break;
            m--;
        }
    }
    return ans;
}
