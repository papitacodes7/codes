class Solution {
  public:
    vector<int> search(string &pat, string &txt) {

        vector<int> ans;

        int m = pat.size();
        int n = txt.size();

        if (m > n) return ans;

        int base = 256;
        int mod = 1000000007;

        long long patHash = 0, txtHash = 0, h = 1;

        // compute h = base^(m-1)
        for (int i = 0; i < m - 1; i++) {
            h = (h * base) % mod;
        }

        // initial hash
        for (int i = 0; i < m; i++) {
            patHash = (patHash * base + pat[i]) % mod;
            txtHash = (txtHash * base + txt[i]) % mod;
        }

        // slide window
        for (int i = 0; i <= n - m; i++) {

            // check hash match
            if (patHash == txtHash) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (txt[i + j] != pat[j]) {
                        match = false;
                        break;
                    }
                }
                if (match)
                    ans.push_back(i);
            }

            // roll hash
            if (i < n - m) {
                txtHash = (txtHash - txt[i] * h) % mod;
                if (txtHash < 0) txtHash += mod;
                txtHash = (txtHash * base + txt[i + m]) % mod;
            }
        }

        return ans;
    }
};


// Rabin–Karp works by converting strings into hash values so that instead of comparing the pattern with every substring character by character, we first compare numbers. We compute the hash of the pattern and the hash of the first window of the text having the same length as the pattern. If the pattern length is greater than the text length, we directly return an empty answer because a larger string cannot fit inside a smaller one. We then slide a fixed-size window over the text and update the window’s hash using a rolling hash technique, which removes the contribution of the leftmost character and adds the new rightmost character in constant time using a precomputed weight. Whenever the hash of the current window matches the pattern hash, we perform a character-by-character check to avoid false matches caused by hash collisions, and if it matches, we store the starting index. This way, we efficiently find all occurrences of the pattern while avoiding repeated full comparisons.



// IMMPORTANT
// IMMPORTANT
// isme tle maar jyga rabin karp due to worse cases.. isiliye kmp lagana he iss question me..
// IMMPORTANT
// IMMPORTANT

// Time Complexity:
// Average Case: O(n + m)
// Worst Case: O(n * m)
//
// Space Complexity: O(1)


// yaha se KMP krna he..




