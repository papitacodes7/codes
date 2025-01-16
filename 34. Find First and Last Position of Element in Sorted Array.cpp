class Solution {
public:

int lowerBound(vector<int> arr, int x) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    
    return ans;
}
int upperBound(vector<int> &arr, int x) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int x) {
        
        int low = lowerBound(nums,x);
        int high = upperBound(nums,x);
        if(low == nums.size() || nums[low] != x) return {-1,-1};
        return {low,high-1};
    }
};