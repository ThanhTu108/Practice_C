#include <stdio.h>

int maxProfit(int* prices, int pricesSize) 
{
    if(pricesSize <= 0)
    {
        return -1;
    }
    int min = prices[0];
    int max_profit = 0;
    for(int i = 0; i<pricesSize; i++)
    {
        if(prices[i] < min)
        {
            min = prices[i];
        }
        else if(prices[i] - min > max_profit)
        {
            max_profit = prices[i] - min;
        }
        // printf("min = %d  ,max =  %d \n", min, max_profit);
    }
    return max_profit;
}


int main()
{
    int arr[] = {7,6,4,3,1};
    int max = maxProfit(arr, sizeof(arr) / sizeof(int));
    printf("%d ", max);
    
    return 0;
}