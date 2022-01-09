/**
 * You can assume that you can always reach the last index
 */
/**
 * The key idea behind is that, all the positions before the maximum reachable
 * distance would be able to be reached! Then we linear scan the array to keep
 * updating the current maximum and the next maximum as well as the number of
 * steps. We can achieve the linear time algorithm. The key idea behind the
 * linear algorithm is that instead of keeping to know every position is
 * reachable by how many steps, we only need to keep a single maximum reachable
 * distances and the steps needed. So every time we only need to update this
 * single value in constant time rather than update a linear portion of
 * positions.
 */
int jump(int *nums, int numsSize)
{
    int maxDistance, maxNext, steps;
    maxDistance = maxNext = steps = 0;
    for (int i = 0; i < numsSize - 1; ++i)
    {
        maxNext = (maxNext > (i + nums[i])) ? maxNext : (i + nums[i]);
        if (i == maxDistance)
        {
            steps++;
            maxDistance = maxNext;
        }
    }
    return steps;
}
