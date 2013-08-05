class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int acc = 0, ans = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            acc += (prices[i] - prices[i - 1]);
            acc = (acc >= 0)? acc: 0;
            ans = max(ans, acc);
        }
        
        return ans;
    }
};