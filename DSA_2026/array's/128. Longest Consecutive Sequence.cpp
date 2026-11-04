#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;

        int longest = 1;
        unordered_set<int> st;

        // Store all numbers in the unordered_set.
        for (int i = 0; i < n; i++) {
            st.insert(a[i]);
        }

        // Start counting only from the beginning of a sequence.
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;

                // Keep checking whether the next consecutive number exists.
                while (st.find(x + 1) != st.end()) {
                    x++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << "Longest consecutive sequence length: "
         << sol.longestConsecutive(nums) << endl;

    return 0;
}

//what we do here is use set and we assume 2 edge cases where first one is like nothing in array so return 0.. and only one no. in array so return 1.. now what we do is assume the answer is longest i.e 1 .. and we insert the array's no. in set and then we take variable cnt.. and then we check for consecutive no.s that is firstly we check if the no. is the starting no. for the sequence or not... by st.find(it - 1) just ek no. minus krke check krenge as consecutive sequence chahiye like 1-> 2 -> 3 .. so 2 can't be the starting as 2 - 1 exists in the set.. now after finding the starting seq. what we do is maintain a vairable named cnt and what we do is check whether the next no. exists of it.. i.e 1+ 2.. in st? yes so cnt++ and also like jo while loop hoga usme apan it ko thodi + ya miinus kr skte hein so what we will do is ek or variable lenge named x = it and iss x pe while loop chalayenge.. i.e 
//     while(st.find(x+1) != st.end()){
//     x++;
//     cnt++;
// ... and yeah obv.. longest = max(longest, cnt) and return krdenge longest ko..