class Solution {
  public:
    int findSubString(string& str) {
        unordered_set<char> s;
        for(char ch : str) s.insert(ch);
        int len = s.size();

        unordered_map<char, int> mp;
        int i = 0, ans = INT_MAX;

        for (int j = 0; j < str.size(); j++) {
            mp[str[j]]++;

            if (mp.size() == len) {
                while (mp[str[i]] > 1) {
                    mp[str[i]]--;
                    i++;
                }
                ans = min(ans, j - i + 1);
            }
        }

        return ans;
    }
};


// We are given a string and our goal is to find the length of the smallest substring that contains all the unique characters present in the entire string. First, we store all unique characters of the string in a set to know how many distinct characters are required. This count represents the condition that a valid substring must satisfy. Then, we use a sliding window technique with two pointers and a map to track the frequency of characters inside the current window. As we expand the window by moving the right pointer, we add characters to the map. Once the number of distinct characters in the window becomes equal to the total unique character count, the window becomes valid. At this point, we try to shrink the window from the left by removing extra characters while still keeping all unique characters present. During this process, we update the answer by taking the minimum length of such valid windows using j - i + 1. This ensures that the final result is the length of the smallest possible substring containing all unique characters.

// Time Complexity (TC):
// The algorithm runs in O(n) time, where n is the length of the string. Each character is visited at most twice—once when the right pointer expands the window and once when the left pointer shrinks it—so the total operations are linear.

// Space Complexity (SC):
// The space complexity is O(1) (or O(k) in general), where k is the number of distinct characters. Since the character set is bounded (e.g., lowercase English letters), the set and map use constant extra space.