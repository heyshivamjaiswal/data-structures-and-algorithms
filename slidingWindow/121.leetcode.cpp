//METHOD 1 Brute force
//Check every possible possible profit

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        for(int i = 0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int profit = prices[j]-prices[i];
                maxProfit = max(maxProfit , profit);
            }
        }
        return maxProfit;
    }
};


//METHOD 2 Optimal
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int i = 0; i< n; i++){
            minPrice = min(minPrice , prices[i]);

            int currentPrice = prices[i] - minPrice;

            maxProfit = max(maxProfit , currentPrice);
        }
        return maxProfit;
    }
};