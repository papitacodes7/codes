//// Anagram -> ["eat", "tea", "tan", "ate", "nat", "bat"]
//
// Words like "eat", "tea", and "ate" contain the same letters.
// If we sort them, they all become "aet".
//
// So, the sorted word can be the KEY in our map.
// The original words become VALUES stored in a vector.
//
// "aet" -> ["eat", "tea", "ate"]
// "ant" -> ["tan", "nat"]
// "abt" -> ["bat"]
//
// Repeat this for every word in the input.
//
// Finally, create a vector<vector<string>> and push
// every map entry's value (ans.second) into it.
//
// Return the result.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Ye ek map ka question hai, isliye hum key-value pair use karenge.
        // Key string hogi aur value vector<string> hogi.
        unordered_map<string, vector<string>> groups;

        for (string word : strs) {

            // Har word ka ek copy banaya, jisko sort karke key banayenge.
            string key = word;

            sort(key.begin(), key.end());

            // Har word ka sorted form uski key ban jayega.
            // Us key ke saamne original words vector mein store honge.
            // Jo words anagrams hain, unka sorted form same hoga,
            // isliye woh same key ke andar group ho jayenge.
            groups[key].push_back(word);
        }

        // Final answer ke liye vector of vectors banayenge.
        vector<vector<string>> result;

        // Map ke har key-value pair ko traverse karenge.
        for (auto& ans : groups) {

            // ans.first mein sorted key hai.
            // ans.second mein us key se related original words hain.
            // Humein sirf groups chahiye, keys nahi.
            // Isliye second value ko result mein append kar denge.
            result.push_back(ans.second);
        }

        // Finally, saare anagram groups return kar denge.
        return result;
    }
};

int main() {
    Solution sol;

    vector<string> strs = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };

    vector<vector<string>> result = sol.groupAnagrams(strs);

    // Har anagram group ko print karenge.
    for (const auto& group : result) {
        cout << "[ ";

        for (const string& word : group) {
            cout << word << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}


// anagram -> ["eat","tea","tan","ate","nat","bat"] -> common things from tea,eat is "aet" after SORTING -> can be a key in a map..then values would be eat, tea..... do this for all -> make a vec of vec and push the values of the map in it.





