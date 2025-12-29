class Solution {
  public:
    string longestPalindrome(string &s) {
        int n = s.size();
        string ans = "";
        
        for(int i = 0; i < n; i++){
            
            // odd length palindrome
            int prev = i - 1;
            int next = i + 1;
            
            while(prev >= 0 && next < n && s[prev] == s[next]){
                prev--;
                next++;
            }
            
            if(next - prev - 1 > ans.size())
                ans = s.substr(prev + 1, next - prev - 1);
            
            // even length palindrome
            prev = i;
            next = i + 1;
            
            while(prev >= 0 && next < n && s[prev] == s[next]){
                prev--;
                next++;
            }
            
            if(next - prev - 1 > ans.size())
                ans = s.substr(prev + 1, next - prev - 1);
        }
        
        return ans;
    }
};

// so like what's gonna happen is that ek string denge and we wanna return the max substring.. that's it..... we can do this by checking for each char ki woh jaha pe bhi he like waha se left and right me char jo he woh match krte hein ya nahi..? pehle char ke left and right leke check krenge cz woh most probably odd leng ka hoga and uske baar char khudko leke fir uske aage waale ko cz woh even wala hoga that's it..ans me store krte rahenge jo bhi max milti rahe substr. that's it..


// Idea: Given a string, we want to return its longest palindromic substring.
// A palindrome expands from its center, so for each index we try to expand
// in both directions (left and right) and check if characters match.
//
// For every character i:
// 1) We first treat it as the center of an odd-length palindrome
//    (check characters at i-1 and i+1).
// 2) Then we treat the gap between i and i+1 as the center of an even-length
//    palindrome (check characters at i and i+1).
//
// In both cases, we expand while characters match and extract the palindrome.
// We keep updating 'ans' whenever we find a longer palindromic substring.


// Time Complexity: O(n^2), checking palindrome expansion at each index.
// Space Complexity: O(1), only constant extra space is used.
