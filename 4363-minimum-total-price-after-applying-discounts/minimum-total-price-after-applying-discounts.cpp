#include <vector>
#include <algorithm>

class Solution {
public:
    double minPrice(std::vector<int>& prices, std::vector<int>& discounts) {
        std::sort(prices.rbegin(), prices.rend());
        std::sort(discounts.rbegin(), discounts.rend());
        
        double total_sum = 0.0;
        int n_pairs = std::min(prices.size(), discounts.size());
        
        // Calculate discounted prices
        for (int i = 0; i < n_pairs; ++i) {
            total_sum += prices[i] * (100.0 - discounts[i]) / 100.0;
        }
        
        // Add undiscounted prices
        for (size_t i = n_pairs; i < prices.size(); ++i) {
            total_sum += prices[i];
        }
        
        return total_sum;
    }
};