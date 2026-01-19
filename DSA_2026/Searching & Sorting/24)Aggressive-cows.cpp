#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool isPossible(vector<int> &stalls, int k, int n, int minAllowedDist) {
        int cows = 1;
        int lastStallPos = stalls[0];
        
        for (int i = 1; i < n; i++) {
            if (stalls[i] - lastStallPos >= minAllowedDist) {
                cows++;
                lastStallPos = stalls[i];
            }
            if (cows == k) {
                return true;
            }
        }
        return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        
        int n = stalls.size();
        int st = 1;
        int end = stalls[n - 1] - stalls[0];
        int ans = -1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            if (isPossible(stalls, k, n, mid)) {
                ans = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }
    
    Solution obj;
    cout << obj.aggressiveCows(stalls, k) << endl;
    
    return 0;
}


// //After fixing a minimum distance mid, we place the first cow at the first stall.
// For each subsequent stall, we check whether the distance between the current stall and the position of the last placed cow is at least mid.
// If yes, we place a cow there, increment the cow count, and update the last placed position.
// If we are able to place all k cows, then the distance mid is feasible.

// https://youtu.be/7wOzDqsfXy0?si=0ynMB1By8WmcmcQn
// ye dekh liyo and smhj liyo firse.. + skipped 23 and 22 on 19/1/26 