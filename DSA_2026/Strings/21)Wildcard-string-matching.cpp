class Solution {
  public:

    bool solve(string &wild, string &pattern, int i, int j) {

        // agar dono strings khatam
        if (i >= wild.length() && j >= pattern.length())
            return true;

        // agar wild khatam ho gayi but pattern baaki
        if (i >= wild.length())
            return false;

        // agar pattern khatam ho gayi but wild baaki
        if (j >= pattern.length()) {
            // sirf '*' bacha hona chahiye
            while (i < wild.length()) {
                if (wild[i] != '*')
                    return false;
                i++;
            }
            return true;
        }

        // same character ya '?'
        if (wild[i] == pattern[j] || wild[i] == '?')
            return solve(wild, pattern, i + 1, j + 1);

        // '*'
        if (wild[i] == '*') {
            // pehle i move karo ( '*' empty )
            if (solve(wild, pattern, i + 1, j))
                return true;

            // agar fail ho gaya, to j move karo ( '*' ek char )
            return solve(wild, pattern, i, j + 1);
        }

        return false;
    }

    bool match(string wild, string pattern) {
        return solve(wild, pattern, 0, 0);
    }
};


We use two indices i for the wild string and j for the pattern string. If the current characters are the same or the wild character is ?, we move both indices forward. When we encounter *, we try two possibilities: first we move i forward assuming * matches an empty string, and if that does not work, we move j forward assuming * matches one character from the pattern. If any of these choices leads to both strings ending together, the match is successful. If the pattern ends but the wild string still has characters left, then all remaining characters in the wild string must be * for the match to be valid. This brute force approach checks all possible ways to use *.

Time Complexity:
Worst case is exponential, around O(2^(n+m)), because each * can create two recursive paths.

Space Complexity:
O(n + m) due to the recursion stack.