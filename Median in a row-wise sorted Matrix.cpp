#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
  
    // Intuition: Yeh function ek upper bound find karta hai, jo ki array mein x se bada element ka pehla index hota hai.
    // Isse hum matrix ke har row mein chote elements ka count nikaalte hain.
    int upperBound(vector<int> &arr, int x, int n) {
      int low = 0, high = n - 1;
      int ans = n; // Initialize answer as n, agar koi bhi element x se bada na mile toh.
  
      // Binary search ka use karke upper bound find kar rahe hain.
      while (low <= high) {
          int mid = (low + high) / 2;
          // Agar mid element x se bada hai, toh yeh answer ho sakta hai.
          if (arr[mid] > x) {
              ans = mid; // Update answer
              // Chote index par bhi dekho kahi chota element na ho.
              high = mid - 1;
          }
          else {
              low = mid + 1; // Daeen taraf dekho, kyunki mid element x se chota hai.
          }
      }
      return ans; // Upper bound return kar rahe hain.
  }
  
    // Intuition: Yeh function matrix mein x se chote ya barabar elements ka count return karta hai.
    // Iske liye hum har row mein upper bound nikaalte hain aur unka sum karte hain.
    int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
      int cnt = 0;
      // Har row mein upper bound find karke count update kar rahe hain.
      for (int i = 0; i < m; i++) {
          cnt += upperBound(matrix[i], x, n);
      }
      return cnt; // Total count return kar rahe hain.
  }
  
      // Intuition: Yeh function matrix ka median find karti hai, jaise ki yeh ek sorted array hota.
      // Binary search ka use karke hum efficiently median nikaal rahe hain.
      int median(vector<vector<int>> &matrix) {
          int low = INT_MAX, high = INT_MIN;
          int n = matrix.size(); // Number of rows
          int m = matrix[0].size(); // Number of columns
  
          // Initialize low aur high ko matrix ke elements ke according.
          for(int i = 0; i < n; i++){
              low = min(low, matrix[i][0]); // Sabse chota element
              high = max(high, matrix[i][m-1]); // Sabse bada element
          }
  
          int req = (n * m) / 2; // Median ka index
  
          // Binary search ka use karke median find kar rahe hain.
          while(low <= high){
              int mid = (low + high) / 2;
              int smallEqual = countSmallEqual(matrix, n, m, mid);
              // Agar mid element se chote ya barabar elements ka count req se kam hai,
              // toh median mid se bada hoga.
              if(smallEqual <= req) low = mid + 1;
              else high = mid - 1; // Warna chota hoga.
          }
  
         return low; // Median return kar rahe hain.
      }
  };