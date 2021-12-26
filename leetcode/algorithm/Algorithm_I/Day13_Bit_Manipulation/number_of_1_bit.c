#include <stdint.h>
/*
 * (n-1) flips all bit to the rightmost one including the rightmost one.
 * Therefore n & (n-1) will set n decrease one bit of one each time until
 * becomes 00000000 4 = {100}2 3 = {011}2 4 & 3 = {000}2 9 = {1001}2 8 = {1000}2
 * 9 & 8 = {1000} count++
 * 7 = {0111}2
 * 8 & 7 = {0000} count++ and loop exit
 */
int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n)
    {
        n = n & n - 1;
        count++;
    }
    return count;
}
