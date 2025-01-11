int mincostTickets(int* days, int daysSize, int* costs, int costsSize)
{
    int dp[366] = {0};
    int travelDays[366] = {0}; 
    
    for (int i = 0; i < daysSize; i++)
    {
        travelDays[days[i]] = 1;
    }
    
    for (int i = 1; i <= 365; i++)
    {
        if (!travelDays[i]) 
        {
            dp[i] = dp[i - 1];
        }
        else 
        {
            int cost1 = dp[i - 1] + costs[0]; 
            int cost7 = dp[i >= 7 ? i - 7 : 0] + costs[1]; 
            int cost30 = dp[i >= 30 ? i - 30 : 0] + costs[2]; 
            dp[i] = fmin(fmin(cost1, cost7), cost30); 
        }
    }
    
    return dp[365];
}