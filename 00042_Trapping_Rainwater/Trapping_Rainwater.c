/*   https://leetcode.com/problems/trapping-rain-water/   */

int max(int a, int b) 
{
    return a > b ? a : b;
}

int min(int a, int b) 
{
    return a > b ? b : a;
}

int trap(int* height, int heightSize)
{
    if(heightSize == 0) return 0;
    int left[heightSize], right[heightSize];
    int water = 0;
    left[0] = height[0];
    for(int i = 1; i < heightSize; i++) left[i] = max(left[i - 1], height[i]);
    right[heightSize - 1] = height[heightSize - 1];
    for(int i = heightSize - 2; i >= 0; i--) right[i] = max(right[i + 1], height[i]);
    for(int i = 0; i < heightSize; i++) water+= min(left[i], right[i]) - height[i];
    return water;
}
