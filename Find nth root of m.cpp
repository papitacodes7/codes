#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  //return 1 agar ans == m ho
  //return 0 agar ans < m ho
  //return 2 agar ans > m ho
    int val(int mid,int n,int m){
        long long ans = 1;
        for(int i = 1 ; i <= n; i++){
            ans = ans * mid;
            if(ans > m) return 2; // agar ans m se bada ho gaya toh 2 return karo
        }
        if(ans == m) return 1; // agar ans m ke barabar ho toh 1 return karo
        return 0; // agar ans m se chhota ho toh 0 return karo
    }
  
    int nthRoot(int n, int m) {
        // Yaha code likhna hai.
        int low = 1, high = m;
        while(low<=high){
            int mid = (low + high) / 2;
            int midn = val(mid, n, m);
            if(midn == 1) return mid; // agar mid nth root ho toh mid return karo
            else if(midn == 0) low = mid + 1; // agar mid nth root se chhota ho toh low ko badhao
            else high = mid - 1; // agar mid nth root se bada ho toh high ko ghatao
        }
    return -1; // agar nth root na milay toh -1 return karo    
    }
};
