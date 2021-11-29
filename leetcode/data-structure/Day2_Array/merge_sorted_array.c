#include <stdio.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    if (n == 0 && m != 0)
    {
        ;
    }
    if (m == 0 && n != 0)
    {
        for (int i = 0; i < n; ++i)
        {
            nums1[i] = nums2[i];
        }
    }
    /* m, n > 0 */
    int s1ptr = m - 1, s2ptr = n - 1, curptr = nums1Size - 1;
    for (; s2ptr >= 0 && s1ptr >= 0; --curptr)
    {
        nums1[curptr] =
            (nums1[s1ptr] > nums2[s2ptr]) ? nums1[s1ptr--] : nums2[s2ptr--];
    }
    /** leftover of s2, all smaller than merged elements
     *  Example: [7,8,9,0,0,0] and [2,5,6]
     *		s1ptr<0: [7,8,9,7,8,9] and [2,5,6];
     *		fill with nums2: [2,5,6,7,8,9]
     */
    if (s2ptr >= 0)
    {
        for (; s2ptr >= 0; --curptr)
        {
            nums1[curptr] = nums2[s2ptr--];
        }
    }
}
