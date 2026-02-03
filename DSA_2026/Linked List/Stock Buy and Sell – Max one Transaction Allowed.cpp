#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int l = 0;        // buy day
        int r = 1;        // sell day
        int maxProfit = 0;

        while (r < prices.size()) {
            if (prices[r] > prices[l]) {
                maxProfit = max(maxProfit, prices[r] - prices[l]);
            } else {
                l = r; // better buying day
            }
            r++;
        }

        return maxProfit;
    }
};

int main() {
    Solution obj;

    vector<int> prices1 = {7, 10, 1, 3, 6, 9, 2};
    vector<int> prices2 = {7, 6, 4, 3, 1};
    vector<int> prices3 = {1, 3, 6, 9, 11};

    cout << obj.maxProfit(prices1) << endl; // 8
    cout << obj.maxProfit(prices2) << endl; // 0
    cout << obj.maxProfit(prices3) << endl; // 10

    return 0;
}


//We want the maximum profit using only one buy and one sell, where buying must happen before selling.
// So, we keep two pointers:

// Left pointer (l) → day we buy the stock

// Right pointer (r) → day we sell the stock

// We move the right pointer forward day by day and calculate the profit as
// prices[r] - prices[l].

// If this profit is greater than current maxProfit, we update maxProfit.

// If the profit is negative or zero, it means we found a cheaper buying day, so we move the left pointer to r.

// Throughout the process, maxProfit is never negative.
// If no profitable transaction is possible, it remains 0.


// there's a good chance ki ni ho paaye teen din tk koi code so aaj 3 se 7 tk there's a good chance just potd hoga.. or kuch nhi..
// that's why trees after examm hi shuru krte hein.. today's date 3/2/26