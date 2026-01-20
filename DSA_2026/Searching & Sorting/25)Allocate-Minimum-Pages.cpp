#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isValid(vector<int> &arr, int n, int k, int maxAllowedPages) {
        int students = 1;
        int pages = 0;
        
        for (int i = 0; i < n; i++) {
            
            // single book can't exceed maxAllowedPages
            if (arr[i] > maxAllowedPages) {
                return false;
            }
            
            // assign book to current student
            if (pages + arr[i] <= maxAllowedPages) {
                pages += arr[i];
            } 
            // assign to new student
            else {
                students++;
                pages = arr[i];
            }
        }
        
        return students <= k;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;

        int sum = 0;
        for (int x : arr) sum += x;

        int st = 0, end = sum;
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (isValid(arr, n, k, mid)) {
                ans = mid;        // possible answer
                end = mid - 1;    // try to minimize
            } else {
                st = mid + 1;     // need more pages
            }
        }

        return ans;
    }
};

// Driver code
int main() {
    Solution obj;
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;

    cout << obj.findPages(arr, k) << endl;
    return 0;
}


//so basically yaha pe sabse pehle toh range find krni he jo hogi like saare pages ka sum krke.. 0 se sum of arr tk.. now mid nikaalna he and check krna he woh answer he ya nahi.. agar woh answer he toh left me jaana he (cz we have to find minimum.. toh there's a chance ki jo aaya usse kam mil jaaye..).. warna right me.. (answer toh mile ek baar fir usse kam krna shuru kr skte hein that's why.. ) now isValid function btyga ki jo mid aaya he jisse hum maxAllowedPages bol skte hein (because binary search se wohi answer nikala because range me he..) usko like arr[i] se compare krna he sabse pehle.. so arr[i] > maxAllowedPages agar hua toh return false krdena he kyuki we know binary search lagane se jo mid aka maxAllowedPages aaya he usse zyda toh arr[i] me nhi hona chahiye kyuki max ka min chahiye max se zyda not allowed.. according to the question.. now we have to check if arr[i] + pages <= maxAllowedPages.. matlb abhi hum or add kr skte hein like same student ko or de skte hein books jabtk less than he maxAllowedPages.. so pages += arr[i].. and esa nhi he.. toh mid se zyda hi hogya he ab new student ko allot krni pdegi books.. so students++ and pages = arr[i] because jo mila usse dediya new student ko.. and last me we will just check if students > k ? false : true... like jitne k no. of students given he usse kam hi toh allot krne the..  



//So basically yaha pe sabse pehle hume **answer ki range** find karni hoti hai jo `0` se leke **saare pages ke sum** tak jaati hai, kyunki worst case me ek student ko saari books mil sakti hain. Phir hum is range par **binary search** lagate hain, jahan har `mid` ko hum **maxAllowedPages** maan ke check karte hain. Ab `isValid` function batata hai ki kya is `maxAllowedPages` ke andar hum saari books ko **k students me contiguous manner me** allocate kar sakte hain ya nahi. Sabse pehle ye check hota hai ki agar koi single book `arr[i] > maxAllowedPages` ho, toh allocation possible hi nahi hai, isliye false return kar dete hain. Phir books ko order me assign karte hain—jab tak `pages + arr[i] <= maxAllowedPages`, same student ko books dete rehte hain, aur jaise hi limit cross hoti hai, ek **naya student** lete hain (`students++`) aur `pages = arr[i]` kar dete hain. End me agar required students `k` se zyada ho jaate hain toh allocation invalid hai, warna valid. Binary search me agar `mid` valid hota hai toh hum **left side** jaate hain kyunki hume answer ko aur minimize karna hota hai, aur agar invalid hota hai toh **right side** jaate hain. Is tarah se hume **minimum possible maximum pages** mil jaate hain.

//refer this for understanding later..
//https://youtu.be/JRAByolWqhw?si=AR3GbjEuQ0XA7VYP


