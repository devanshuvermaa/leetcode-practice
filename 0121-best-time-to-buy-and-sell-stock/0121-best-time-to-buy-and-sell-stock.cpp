class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            int profit = prices[i] - buy_price;
            buy_price = min(buy_price, prices[i]);
            max_profit = max(profit, max_profit);
        }
        return max_profit;
    }
};