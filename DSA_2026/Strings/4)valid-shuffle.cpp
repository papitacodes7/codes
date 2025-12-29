bool validShuffle(string str1, string str2, string shuffle) {

    int n1 = str1.length();
    int n2 = str2.length();
    int n  = shuffle.length();

    // Step 1: Length must match
    if (n != n1 + n2) 
        return false;

    // Step 2: Store frequency of characters from str1 and str2
    unordered_map<char, int> mpp;

    for (char ch : str1)
        mpp[ch]++;

    for (char ch : str2)
        mpp[ch]++;

    // Step 3: Traverse shuffle string
    for (char ch : shuffle) {

        // If character not expected
        if (mpp.find(ch) == mpp.end())
            return false;

        // Use one occurrence
        mpp[ch]--;

        // More occurrences than expected
        if (mpp[ch] < 0)
            return false;
    }

    // Step 4: Check if all characters are used exactly
    for (auto it : mpp) {
        if (it.second != 0)
            return false;
    }

    return true;
}


// Hum pehle str1 aur str2 ke saare characters map me daal dete hain.
// Phir shuffle string ko traverse karte hain:
// Agar character map me nahi mila → invalid shuffle
// Agar mila → uski frequency decrease kar dete hain
// Agar frequency negative ho gayi → extra character aa gaya
// End me agar map ki saari values 0 hain, matlab shuffle perfectly match karta hai.

// TC: O(n) where n is the total length of both strings
// SC: O(1) for fixed character set, otherwise O(Σ)