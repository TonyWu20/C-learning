
void duplicateZeros(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize - 1; ++i)
    {
        if (arr[i] == 0)
        {
            for (int j = arrSize - 2; j > i; --j)
            {
                arr[j + 1] = arr[j];
            }
            arr[i + 1] = 0;
            i++;
        }
    }
    return;
}
