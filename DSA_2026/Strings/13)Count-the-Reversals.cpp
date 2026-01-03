class Solution {
public:
    int countMinReversals(string s) {
        int n = s.length();

        // If length is odd, it's impossible
        if (n % 2 != 0) return -1;

        int open = 0, close = 0;

        for (char ch : s) {
            if (ch == '{') {
                open++;
            } else { // ch == '}'
                if (open > 0) {
                    open--;   // matched with an opening brace
                } else {
                    close++;  // extra closing brace
                }
            }
        }

        // Minimum reversals needed
        return (open + 1) / 2 + (close + 1) / 2;
    }
};


//Pehle saare valid {} pairs cancel karo, phir jo unmatched { aur } bache unko minimum reversals se pair karke string balance karo.
