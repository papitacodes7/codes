class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int p = n - 2;

        // Step 1: find pivot
        while (p >= 0 && arr[p] >= arr[p + 1]) {
            p--;
        }

        // Step 2: if no pivot, reverse whole array
        if (p < 0) {
            reverse(arr.begin(), arr.end());
            return;
        }

        // Step 3: find next greater element
        int q = n - 1;
        while (arr[q] <= arr[p]) {
            q--;
        }

        // Step 4: swap and reverse suffix
        swap(arr[p], arr[q]);
        reverse(arr.begin() + p + 1, arr.end());
    }
};


// To find the next permutation, start scanning from the right to locate the first index p where arr[p] < arr[p+1], because the part after this index is already in descending order and cannot produce a larger permutation on its own. If no such index exists, the array represents the largest permutation, so reversing the entire array gives the smallest one. Otherwise, find the smallest element greater than arr[p] on its right, swap them, and then reverse the subarray after index p to make the suffix as small as possible. This guarantees the immediate next lexicographical permutation.



// basically pivot find krna he.. pivot is the first element jo right se left order ko break krta he.. fir uske baad pivot ke baad se esa pehla element find krna he jo pivot se bda ho.. 
// ye krne ke baad unhe swap krke reverse krdena he pivot ke baad se arr end tk.. and return krwa dena he.. easy..
