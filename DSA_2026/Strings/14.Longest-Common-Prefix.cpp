class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Step 1: empty check
        if (strs.empty()) return "";

        // Step 2: take first string as prefix
        string pref = strs[0];

        // Step 3: compare with remaining strings
        for (int i = 1; i < strs.size(); i++) {
            string s = strs[i];

            // Step 4: shrink prefix until it matches
            while (pref.length() > s.length() ||
                   pref != s.substr(0, pref.length())) {

                pref = pref.substr(0, pref.length() - 1);

                if (pref.length() == 0)
                    return "";
            }
        }

        return pref;
    }
};


// first example me dekh..
// flower and flow ko compare krte hein..  and like if they ain't equal toh flower ka r ht jaata he.. and flowe bachta he.. now do this until they equal and like flow == flow mil jayga.. fir hum dusre pe jynge.. flow and flight.. flow and flig check hoga.. not equal toh flo and fli.. ese krte krte krte fl bachega.. woh return kkarna he..

// We take the first string as the initial prefix.
// For each remaining string, we check whether the current prefix
// matches the beginning of that string.
// If it does not match, we keep removing one character from the
// end of the prefix until it matches.
// This process continues for all strings.
// The remaining prefix at the end is the longest common prefix.
// tc = m*n
// sc = 1