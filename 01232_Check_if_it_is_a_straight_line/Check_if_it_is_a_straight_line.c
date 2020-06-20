/*   https://leetcode.com/problems/check-if-it-is-a-straight-line/   */

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize)
{
    if(coordinatesSize == 2) return true;
    int x0 = coordinates[0][0], y0 = coordinates[0][1];
    int dx = coordinates[1][0] - coordinates[0][0], dy = coordinates[1][1] - coordinates[0][1];
    for(int i = 2; i < coordinatesSize; i++)
    {
        int x = coordinates[i][0], y = coordinates[i][1];
        if(dx * (y - y0) != dy * (x - x0)) return false;
    }
    return true;
}
