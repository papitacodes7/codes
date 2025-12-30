class Solution {
  public:
  
    void solve(int i, int n, string &s,string &permu, unordered_set <string> &st ){
        
        if(permu.size() == n){
            st.insert(permu);
            return;
        }
        
        for(int j = i; j<n; j++){
            swap(s[i], s[j]);
            permu.push_back(s[i]);
            solve(i+1,n,s,permu,st);
            permu.pop_back();
            swap(s[i],s[j]);
        }
    }
  
  
    vector<string> findPermutation(string &s) {
        // Code here there
        
        
        // set isliye bna reh hein cz duplicate hat jaaye..
        unordered_set <string> st;
        // set me permu daalna he toh permu banani pdegi pehle..
        string permu;
        // string ka size leleiya.. jo bhi di he uska..
        int n = s.size();
        solve(0,n,s,permu,st);
        vector <string> result(st.begin(),st.end());
        return result;
        
        
    }
};

// https://youtu.be/bEOmP9IBbo0?si=F6lMLlRTRjactAV2 isme last ka suun le so that smhj jyga but let me try to explain..
// sabse pehle saare permutations nikaalne he..
// swap kr kr ke..
// saare permutationns matlb har ek char har ek jaghe hona chahiye..
// that's why we will use backtracking..
// let assume ki abc string he..
// soo ab ko swap krke ba milega.. usse store krenge.. fir backtrack fir same for other..
// that's it..
// hard question he backtracking acche se smhj ke hi krna pdega..