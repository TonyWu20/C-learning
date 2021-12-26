
int maxProfit(int *prices, int pricesSize)
{
    if (pricesSize < 2)
        return 0;
    int minima = prices[0];
    int profit = (prices[1] - prices[0] > 0) ? prices[1] - prices[0] : 0;
    for (int i = 1; i < pricesSize; ++i)
    {
        if (prices[i] - minima > profit)
        {
            profit = prices[i] - minima;
        }
        else if (prices[i] < minima)
        {
            minima = prices[i];
        }
    }
    return profit;
}
