class Solution {
  public:
    bool isPalindrome(string& s) {
        int st = 0;
        int ed = s.size() - 1;

        while (st < ed) {
            if (s[st] != s[ed]) return false;
            st++;
            ed--;
        }
        return true;
    }
};


// like last wala is equal to the first one or not.. that's so easy in the string..just simple two pointer approach...
