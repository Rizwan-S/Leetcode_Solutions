/*   https://leetcode.com/problems/search-a-2d-matrix/   */

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    if(matrixSize == 0 || matrixColSize[0] == 0) return false;
    if(target < matrix[0][0] || target > matrix[matrixSize - 1][matrixColSize[matrixSize - 1] - 1]) return false;
    int l = 0, r = matrixSize - 1, mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(matrix[mid][0] == target) return true;
        else if(matrix[mid][0] < target) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d", l);
    l--;
    int i = 0, j = matrixColSize[l] - 1;
    while(i <= j)
    {
        mid = (i + j) / 2;
        if(matrix[l][mid] == target) return true;
        else if(matrix[l][mid] < target) i = mid + 1;
        else j = mid - 1;
    }
    return false;
}
