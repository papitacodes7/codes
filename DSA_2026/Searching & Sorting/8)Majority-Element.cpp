#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int majorityElement(vector<int>& arr) {

        int count = 0, candidate = 0;

        // Phase 1: Moore's Voting
        for (int x : arr) {
            if (count == 0) {
                candidate = x;
                count = 1;
            }
            else if (x == candidate) {
                count++;
            }
            else {
                count--;
            }
        }

        // Phase 2: Verification
        count = 0;
        for (int x : arr) {
            if (x == candidate)
                count++;
        }

        if (count > arr.size() / 2)
            return candidate;

        return -1;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.majorityElement(arr);

    return 0;
}

//so basically isme moore's voting algo lagani he.. for every el in the arr.. we just have to count how many times woh aarha he.. agar startiing me uska count zero he toh fir we are just going to add count = 1 because woh uska khukda freq ki value hogii.. like khudki value as an element as one.. now we going to check if jo next element he woh kya uske equal he jiska hum freq nikaal reh hein aka candidate.. if yes than we are gonna increase the coount of it... else decrease kr denege.. in the end.. jo candidate hoga.. woh apan assume kr skte hein filhaal ki woh MJ he.. but the thing usko verify krna hoga.. so count ko firse zero se initialize krke.. we gonna run a for loop again and check krlenge. jo candidate he na woh kitni baar aarha he by for(int x : arr) me x se compare krke.. now in the end we gonna check if that count > n/2 or not.. if yes toh return candidate else return -1 .. that's it..

//Is problem me hum Moore’s Voting Algorithm use karte hain. Hum array ke har element par traverse karte hain aur ek candidate aur ek count maintain karte hain. Agar starting me count zero ho, toh hum current element ko candidate bana dete hain aur count = 1 kar dete hain, kyunki woh element khud apni ek frequency represent karta hai. Uske baad har next element ke liye check karte hain ki kya woh current candidate ke equal hai; agar haan, toh count increase kar dete hain, warna count decrease kar dete hain, jo basically different elements ko cancel karne ka kaam karta hai. Is process ke end me jo candidate bachta hai, hum temporarily assume kar sakte hain ki wahi majority element ho sakta hai. Lekin kyunki majority element ka exist karna guaranteed nahi hota, isliye hume verification karna padta hai. Verification ke liye hum count ko dubara zero se initialize karte hain aur array par ek aur loop chala kar check karte hain ki candidate actual me kitni baar aa raha hai. Agar uski frequency n/2 se zyada hoti hai, toh hum candidate return kar dete hain, warna -1 return karte hain. Time Complexity O(n) hoti hai kyunki array par do baar traverse karte hain, aur Space Complexity O(1) hoti hai kyunki sirf constant extra variables use kiye gaye hain.

