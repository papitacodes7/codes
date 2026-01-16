#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        unordered_map<int,int> freq;

        int prefixSum = 0;
        int count = 0;

        // prefix sum 0 exists before starting
        freq[0] = 1;

        for(int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            count += freq[prefixSum];

            freq[prefixSum]++;
        }

        return count;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {6, -1, -3, 4, -2, 2};
    
    cout << obj.findSubarray(arr);

    return 0;
}



// Hume ek running sum (prefix sum) maintain karna hota hai. Har index par hum is running sum ko map me check karte hain ki yeh sum pehle kitni baar aa chuka hai. Agar yeh pehle aa chuka hai, toh utni zero-sum subarrays current index par end hoti hain, isliye hum count me uski frequency add kar dete hain. Phir current running sum ki frequency map me increase kar dete hain. End me total count return kar dete hain.






//Since we need to count zero-sum subarrays, we traverse the array using a single loop while maintaining a running sum (prefix sum). At every index, the prefix sum represents the sum of elements from the start of the array up to the current index. The key observation is that if the same prefix sum appears multiple times, then the elements between those occurrences must sum to zero. Hence, we store the frequency of each prefix sum using a hashmap. While iterating, if the current prefix sum has appeared before, it means that many zero-sum subarrays end at the current index, so we add its frequency to the answer. If the prefix sum is appearing for the first time, its frequency is zero, so nothing is added. Initializing the frequency of prefix sum 0 as 1 handles subarrays that start from index 0. This way, all zero-sum subarrays are counted efficiently in a single pass.

// Time Complexity

// O(n) — one traversal of the array with constant-time hashmap operations.

// Space Complexity

// O(n) — hashmap stores prefix sums in the worst case.