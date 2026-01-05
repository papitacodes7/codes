class Solution {
  public:
    int romanToDecimal(string &s) {
        
        
        unordered_map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        
        int ans = 0;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            int curr = mpp[s[i]];
            
            if (i < n - 1 && curr < mpp[s[i + 1]]) {
                ans -= curr;
            } else {
                ans += curr;
            }
        }
        
        
        
        return ans;
    }
};

// if agar chotti val pehle aaye toh minus krna he warna + krna he..
// map banakae usme saare vals daal de and ek for loop me compare kr..
// if block me i < n - 1 condition lagani he kyuki last value will always be added.
// ans me +- krte reh and return ans in the end.. 