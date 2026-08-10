class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int hold = -prices[0];
        int not_hold = 0;

        for(int i=1;i<n;i++){
            int next_hold = max(hold, not_hold-prices[i]);
            int next_not_hold = max(not_hold,hold+prices[i]);

            hold = next_hold;
            not_hold = next_not_hold;
        }
        return not_hold;
    }
};