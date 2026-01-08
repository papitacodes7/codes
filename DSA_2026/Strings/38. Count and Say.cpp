class Solution {
public:
    string say(string s){
        string ans = "";
        for(int i = 0; i<s.size(); i++){
            int cnt = 1;
            while(i < s.size() && s[i] == s[i+1]){
                i++;
                cnt++;
            }
            ans += to_string(cnt);
            ans += s[i];
        }
        return ans;
    }
    
string countAndSay(int n) {
    string ans = "1";
    for(int i = 1; i < n; i++){
        ans = say(ans);
    }
    return ans;
}
};

// leetcode ka ques. he..
//so basically we want ki let's say koi bhi n dede like 4 so we want to return 4th thing after counting how many times that number occur in a certain way like for example starting value toh 1 he so one times one which is 11 this is the first iteration second would be 21 because do baar one aaya... third time it'll be 1211.. which will be our answer but the thing is while loop fir --n tk chalana pdega yaa toh 1 se start krna pdega for loop..




// The idea is to generate the nth term of the count-and-say sequence.
// The sequence always starts with "1".
//
// Each iteration reads the previous string and describes it
// by counting consecutive identical digits.
//
// Example (n = 4):
// "1"   → one '1'        → "11"
// "11"  → two '1's       → "21"
// "21"  → one '2', one '1' → "1211"
//
// Since "1" is already the first term, we apply the say() operation
// exactly (n - 1) times.
// That is why we either use while(--n) or a for loop from i = 1 to i < n.
// The idea is to generate the nth term of the count-and-say sequence.
// The sequence always starts with "1".
//
// Each iteration reads the previous string and describes it
// by counting consecutive identical digits.
//
// Example (n = 4):
// "1"   → one '1'        → "11"
// "11"  → two '1's       → "21"
// "21"  → one '2', one '1' → "1211"
//
// Since "1" is already the first term, we apply the say() operation
// exactly (n - 1) times.
// That is why we either use while(--n) or a for loop from i = 1 to i < n.


// Time Complexity: O(n * L), where L is the length of the generated string.
// Space Complexity: O(L), since only the current string is stored.
