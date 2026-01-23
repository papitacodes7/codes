#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Merge two sorted halves and count inversions
    long long merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;
        long long invCnt = 0;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
                invCnt += (mid - left + 1); // bulk inversion count
            }
        }

        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return invCnt;
    }

    long long mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return 0;

        int mid = (low + high) / 2;
        long long invCnt = 0;

        invCnt += mergeSort(arr, low, mid);       // left inversions
        invCnt += mergeSort(arr, mid + 1, high);  // right inversions
        invCnt += merge(arr, low, mid, high);     // cross inversions

        return invCnt;
    }

    long long inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main() {
    vector<int> arr = {5, 3, 2, 4, 1};

    Solution obj;
    cout << "Inversion Count = " << obj.inversionCount(arr) << endl;

    return 0;
}


//isme we are doing invCount += (mid - i + 1 ) kyuki in that time jb ye hoga tb.. i > j he and arr[i] > arr[j] bhi he.. jo inversions ki condition hoti he.. i left me hoga left subpart ke start me.. and j hoga right part ke start me i.e j = mid + 1; now.. that's it jo ab merge function he na usme last me return krwa denge invCount.. and mergeSort me left rec me leftInvCount and right me RightinvCount.. and mergeSort me return krwa rahe honge.. leftinv + rightInv + inv. that's it..

//Merge step ke time dono subarrays already sorted hote hain — left `[low..mid]` aur right `[mid+1..high]`. Jab kisi point par `arr[left] > arr[right]` hota hai, tab sirf ek inversion nahi banta, balki left subarray ke `left` index se lekar `mid` tak ke **saare elements** `arr[right]` se bade hote hain, kyunki left half sorted hai. Iska matlab ye hua ki us ek comparison par hi multiple inversions form ho jaate hain, aur unki count hoti hai `(mid - left + 1)`. Isliye hum bulk me `invCnt += (mid - left + 1)` add kar dete hain. Merge function ye cross inversions count karke `invCnt` return karta hai, aur `mergeSort` me total inversions `leftInv + rightInv + mergeInv` ke form me accumulate hote rehte hain — left recursion se, right recursion se, aur merge ke time ke inversions milke final inversion count banate hain.

//Time Complexity:
//O(n log n)    