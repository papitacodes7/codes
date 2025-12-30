class Solution {
  public:
    
    vector <string> ans;
    
    void solve(int i, string s, string prev){
        
        if(i == s.size()){
            if(prev.size()){
                ans.push_back(prev);
            }
        return;
        }
        
        //choose
        solve(i+1, s, prev + s[i]);

        //reject
        solve(i+1, s, prev);
        
    }
    
    vector<string> AllPossibleStrings(string s) {
        // Code here
        ans.clear();
        solve(0,s,"");
        sort(ans.begin(), ans.end());
        return ans;
    }
};



//Is approach me hum ek recursive function use karte hain jisme teen cheezein pass hoti hain: current index i, original string s, aur ek string curr jo ab tak bani subsequence ko represent karti hai.

// Hum string ke first index se start karte hain. Har index pe do choices hoti hain — ya toh current character ko curr me add kar do, ya usse skip kar do.

// Agar hum character ko lete hain, toh curr + s[i] karke next index pe chale jaate hain.
// Agar nahi lete, toh curr ko same rakh ke next index pe chale jaate hain.

// Jab i == s.size() ho jaata hai, matlab saare characters process ho chuke hote hain. Is point pe agar curr empty nahi hai, toh wo ek valid subsequence hoti hai, jise answer vector me store kar dete hain.

// Finally, saari subsequences ko lexicographically sorted order me arrange kar dete hain.


// procedure AllPossibleStrings(s):
//     ans ← empty list

//     call solve(0, s, "")

//     sort(ans)
//     return ans
// 
// 
// procedure solve(i, s, curr):
//     if i == length(s):
//         if curr is not empty:
//             add curr to ans
//         return

//     // choose current character
//     solve(i + 1, s, curr + s[i])

//     // do not choose current character
//     solve(i + 1, s, curr)




