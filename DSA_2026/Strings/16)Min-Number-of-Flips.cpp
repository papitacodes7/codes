class Solution {
  public:
    int minFlips(string& s) {
        // code 
        int flips0 = 0;  // for pattern 010101...
    int flips1 = 0;  // for pattern 101010...

    for (int i = 0; i < s.size(); i++) {

        // expected char if pattern starts with 0
        if (i % 2 == 0) {
            if (s[i] != '0') flips0++;
            if (s[i] != '1') flips1++;
        }
        // expected char if pattern starts with 1
        else {
            if (s[i] != '1') flips0++;
            if (s[i] != '0') flips1++;
        }
    }

    return min(flips0, flips1);
        
    }
};


// jo bhi string he woh check krenge 01010... waali he yaa 10101 waali dono se compare krke jo bhi mismatches honge unhe flip zero and flip one me set krke minimum lelenge.. that;s it>

// We are given a binary string and we want to make it alternating, which means no two adjacent characters can be the same. For any length, an alternating binary string can only be of two forms: it either starts with 0 and looks like 010101..., or it starts with 1 and looks like 101010...; there is no third possibility because once the first character is fixed, the rest are forced to alternate. So, we compare the given string with both of these patterns index by index. At each index, if the character in the string does not match the expected character of the pattern, it means we must flip that bit, so we count it as one flip. We keep two counters: flips0 for mismatches with the 010101... pattern and flips1 for mismatches with the 101010... pattern. After checking all characters, the minimum of these two counts gives the smallest number of flips required to convert the string into an alternating one, because we simply choose the pattern that is closer to the original string.