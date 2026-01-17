#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        vector<pair<int,int>> ans;

        // Store value and original index
        for (int p = 0; p < arr.size(); p++) {
            ans.push_back({arr[p], p});
        }

        // Sort by value
        sort(ans.begin(), ans.end());

        int count = 0;

        // Fix elements one by one
        for (int i = 0; i < arr.size(); i++) {
            if (ans[i].second != i) {
                count++;
                swap(ans[i], ans[ans[i].second]);
                i--; // recheck same index
            }
        }

        return count;
    }
};

int main() {
    vector<int> arr = {10, 5, 6, 3};

    Solution obj;
    int result = obj.minSwaps(arr);

    cout << "Minimum swaps required: " << result << endl;

    return 0;
}


//arr ki indexing ka scene he.. 


//To find the minimum number of swaps required to sort the array, we first observe that if we know the correct position of every element in the sorted array, we can count how many swaps are needed to place each element at its correct index. For this, we store each element along with its original index in a vector of pairs and then sort this vector based on the element values. After sorting, if an element is not at the index it should be, it means it is part of a cycle. We repeatedly swap the current element with the element present at its correct position until the correct element reaches the current index, counting each swap. This process ensures that each cycle of length k contributes exactly k − 1 swaps, which gives the minimum number of swaps required. The sorting step takes O(n log n) time, and the traversal of the array with swaps takes O(n) time, so the overall time complexity is O(n log n). The extra space used for storing the element-index pairs is O(n), hence the space complexity is O(n).

