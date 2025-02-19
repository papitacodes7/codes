#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        /*
        Intuition:
        ----------
        Humara goal hai ek "peak" element dhundhna jahan element apne neighbors se bada ho.
        Is approach mein hum matrix ke columns par binary search karte hain.
        
        1. Har iteration mein, hum middle column 'mid' select karte hain.
        2. Us column ke sabhi rows mein maximum element dhundhte hain. (findMaxIndex function)
        3. Ab hum us maximum element ke left aur right neighbors se compare karte hain:
           - Agar yeh element dono neighbors se bada hai, to yeh peak hai, return kar do iska index.
           - Agar left neighbor bada hai, matlab peak left half mein ho sakta hai, to binary search ka range left update karo.
           - Agar right neighbor bada hai, matlab peak right half mein ho sakta hai, to binary search ka range right update karo.
        
        Yeh approach efficient hai (O(n*log(m))) kyunki har column ke liye hum O(n) mein maximum dhoondte hain 
        aur columns ke upar binary search lagate hain (log(m) iterations).
        */
        
        // Function to find the index of the maximum element in a given column 'col'
        int findMaxIndex(vector<vector<int>>& mat, int n, int m, int col) {
            int maxValue = -1, index = -1;
            // Har row mein check karo given column 'col' ka value
            for (int i = 0; i < n; i++) {
                // Agar current element maxValue se bada hai, to update karo
                if (mat[i][col] > maxValue) {
                    maxValue = mat[i][col];
                    index = i;
                }
            }
            // Return karo row index jisme maximum element tha
            return index;
        }     
    
        vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int n = mat.size();       // Number of rows
            int m = mat[0].size();    // Number of columns
            int low = 0, high = m - 1; // Binary search on columns
    
            // Jab tak binary search range valid hai (low <= high)
            while (low <= high) {
                int mid = (low + high) / 2;  // Middle column index
                // Is column mein maximum element ka row index dhoondo
                int maxRowIndex = findMaxIndex(mat, n, m, mid);
                
                // Left neighbor value: agar left column exist karta hai, to us element ka value, otherwise -1
                int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : -1;
                // Right neighbor value: agar right column exist karta hai, to us element ka value, otherwise -1
                int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : -1;
                
                // Check karo agar current element peak hai (apne dono neighbors se bada)
                if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right) {
                    return {maxRowIndex, mid};  // Peak element mil gaya
                }    
                // Agar left neighbor bada hai, to peak left side mein ho sakta hai
                else if (mat[maxRowIndex][mid] < left) {
                    high = mid - 1; // Binary search ko left half mein shift karo
                }
                // Agar right neighbor bada hai, to peak right side mein ho sakta hai
                else {
                    low = mid + 1; // Binary search ko right half mein shift karo
                }
            }
            // Agar peak element nahi mila (theoretically possible nahi hai agar input valid ho), to return karo {-1, -1}
            return {-1, -1};
        }
    };
    