class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!prices.size()) {
            return 0;
        }
        
        vector<int> front(prices.size()), back(prices.size());
        
        int acc = 0;
        front[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            acc += prices[i] - prices[i - 1];
            acc = max(0, acc);
            front[i] = max(front[i - 1], acc);
        }
        
        acc = 0;
        back[prices.size() - 1] = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            acc += prices[i + 1] - prices[i];
            acc = max(0, acc);
            back[i] = max(back[i + 1], acc);
        }
        
        int ans = 0;
        for (int i = 1; i < prices.size() - 1; i++) {
            ans = max(ans, front[i] + back[i + 1]);
        }
        ans = max(ans, back[0]);
        
        return ans;
    }
};