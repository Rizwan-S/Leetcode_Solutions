/*  https://leetcode.com/problems/search-a-2d-matrix-ii/ */

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) 
{
    if(matrixRowSize == 0 || matrixColSize == 0) return false;
    int smallest = matrix[0][0], largest = matrix[matrixRowSize - 1][matrixColSize - 1];
    if(target < smallest || target > largest) return false;
    int i = 0, j = matrixColSize - 1;
    while(i < matrixRowSize && j >= 0)
    {
        if(matrix[i][j] == target) return true;
        else if(matrix[i][j] > target) j--;
        else i++;
    }
    return false;
}

