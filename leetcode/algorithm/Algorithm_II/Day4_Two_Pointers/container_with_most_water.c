int min(int a, int b)
{
    return (a < b) ? a : b;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int maxArea(int *height, int heightSize)
{
    int left = 0, right = heightSize - 1;
    int area = 0;
    while (left < right)
    {
        int leftH = height[left], rightH = height[right];
        int width = right - left;
        int trueHeight = min(leftH, rightH);
        int currArea = width * trueHeight;
        area = max(currArea, area);
        if (leftH > rightH)
            left++;
        else
            right--;
    }
    return area;
}
