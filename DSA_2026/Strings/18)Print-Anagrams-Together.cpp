// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> mp;

        // group words by their sorted form
        for (string s : arr) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        // collect result
        vector<vector<string>> res;
        for (auto &it : mp) {
            res.push_back(it.second);
        }

        return res;
    }
};


// we need a map jisme apan store kr ske ki konse word se konsa anagram ban rha he..
// so we created a map jisme ek side sorted string e.g arr ke words directly..
// and dusri taraf uske anagrams...
// now we need to push into map jo upar bataya woh.. so ..
// what we do is..traverse the whole array now..
// string key can be called temp var like jo bhi aarha he pehle usme rakh rahe hein..
// fir like temp ko sort krdenge.. and fir map me jaha pe bhi woh sorted temp/key variable aaya..
// waha pe usse daal denge.. like sort krne ke baad woh jo bhi bana usse map me uske aage daal do jo array me aaya he..
// for example cat bnega.. act. so..
// basically on line 12 map me jo bhi sort krke bana he uske samne jo arr me aaya he woh..

// now map ke second part me vec of vec str me grps he..
// usko vector waale ans me daal ke return krdo.. like just return the group using vecvec of str res.. that's it..

// We solve this problem by using an unordered map to group strings that are anagrams of each other. The key idea is that all anagrams, when their characters are sorted, produce the same string. We traverse the input array and for each word, create a temporary copy and sort it; this sorted string is used as the key in the map, while the original word is pushed into the corresponding vector of values. In this way, all words that are anagrams end up grouped under the same key. After processing all strings, the map contains groups of anagrams as its values, which we collect into a vector<vector<string>> and return as the final result.

// Time Complexity: O(n * k log k), where n is the number of strings and k is the average length of a string. Each string is sorted individually, which takes O(k log k), and this is done for all n strings.

// Space Complexity: O(n * k), since the unordered map stores all the input strings grouped together and extra space is used to store the sorted keys.


