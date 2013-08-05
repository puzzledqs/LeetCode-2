class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (prices.size() == 0) {
            return 0;
        }
        
        int ans = 0;
        int low = prices[0], high = low;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < high)   {
                ans += high - low;
                high = low = prices[i];
            }
            else    {
                high = prices[i];
            }
        }
        
        return ans + max(0, high - low);
    }
};