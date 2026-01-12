#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find elements in the array that are equal to their index.
    vector<int> valueEqualToIndex(vector<int>& arr) {
        vector<int> res;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == i + 1)
                res.push_back(i + 1);
        }
        return res;
    }
};

int main() {
    vector<int> arr = {15, 2, 45, 4, 7};

    Solution obj;
    vector<int> result = obj.valueEqualToIndex(arr);

    for (int idx : result) {
        cout << idx << " ";
    }

    return 0;
}


// Basically array zero-based indexing follow karta hai, yaani arr[0] pe first element hota hai. Par problem 1-based indexing ke hisaab se puch rahi hai ki agar kisi index i pe value i ke equal ho, toh us index ko return karo. Isliye hum simple for loop laga ke array traverse karte hain. Ab kyunki actual index i + 1 hota hai, isliye condition arr[i] == i nahi balki arr[i] == i + 1 check karni padti hai. Agar ye condition true hoti hai, toh hum i + 1 ko answer me store kar dete hain. Basically hum zero-based indexing ko 1-based indexing me convert karke check kar rahe hain.

// Time Complexity:
// O(n) — kyunki hum array ko ek baar linearly traverse karte hain.

// Space Complexity:
// O(1) auxiliary space — output vector ke alawa koi extra space use nahi hota.