#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            
            // Ensure nums1 is the smaller array taaki binary search efficiently chale
            if(nums1.size() > nums2.size()){
                return findMedianSortedArrays(nums2, nums1);
            }
            
            int m = nums1.size(); // nums1 ka size
            int n = nums2.size(); // nums2 ka size
    
            int low = 0;
            int high = m;
    
            // Binary search apply kar rahe hai nums1 pe
            while(low <= high){
                int mid = (low + high) / 2; // nums1 ka mid index nikal rahe hai
                int elinLeft = (m + n + 1) / 2 - mid; // nums2 ka corresponding partition calculate kar rahe hai
                
                // Left half ka last element find kar rahe hai, agar mid 0 hai toh INT_MIN lenge
                int x1 = (mid == 0) ? INT_MIN : nums1[mid - 1]; 
                int x2 = (elinLeft == 0) ? INT_MIN : nums2[elinLeft - 1];
    
                // Right half ka first element find kar rahe hai, agar mid last element hai toh INT_MAX lenge
                int x3 = (mid == m) ? INT_MAX : nums1[mid]; 
                int x4 = (elinLeft == n) ? INT_MAX : nums2[elinLeft];
    
                // Agar partition sahi bana hai (left half ke sabhi elements right half se chhote hai)
                if(x1 <= x4 && x2 <= x3){
                    // Agar total elements odd hai, toh left half ka max element hi median hoga
                    if((m + n) % 2 == 1){
                        return max(x1, x2); 
                    }
                    // Agar even elements hai, toh left max aur right min ka average hoga median
                    return (max(x1, x2) + min(x3, x4)) / 2.0; 
                }
    
                // Agar left half ka max (x1) right half ke min (x4) se bada hai, toh left half ko chhota karna padega
                if(x1 > x4){
                    high = mid - 1; // Left half shift kar rahe hai
                }
                // Nahi toh right half ko thoda bada karenge
                else {
                    low = mid + 1; // Right half shift kar rahe hai
                }
            }
            return -1; // Ye case kabhi aayega hi nahi agar inputs sahi hai
        }
    };
    
    int main() {
        Solution solution;
        
        // Example 1
        vector<int> nums1 = {1, 3}; 
        vector<int> nums2 = {2};
        cout << "Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl;
        
        // Example 2
        vector<int> nums3 = {1, 2}; 
        vector<int> nums4 = {3, 4};
        cout << "Median: " << solution.findMedianSortedArrays(nums3, nums4) << endl;
    }