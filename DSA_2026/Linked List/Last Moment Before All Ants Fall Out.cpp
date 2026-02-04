#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;

        // ants moving to the left
        for (int pos : left) {
            ans = max(ans, pos);
        }

        // ants moving to the right
        for (int pos : right) {
            ans = max(ans, n - pos);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n = 10;
    vector<int> left  = {2, 4};
    vector<int> right = {6, 7};

    cout << "Last moment when an ant falls: "
         << obj.getLastMoment(n, left, right) << endl;

    return 0;
}


// doing this on 4/2/26 instead of ll ke ques cz time nhi he.. also ye question mujhe nhi smhj aaya just itna smhja ki right se left aane me right jitna hi time lagega.. like right se zero aane pe right jitna... did you get it? jb bhi padh rha he.. anyways.. wrote all this just yaha tk on 7:54 pm.. abhi internal ka bhi pdhna he.. by.. ho skta he do din or just potd hi kru.. 


//Plank ki length n hai aur har ant 1 unit per second ki speed se chalti hai, isliye kisi ant ko girne me lagne wala time bas utna hi hota hai jitna distance use plank ke end tak chalna pade. Jo ants left ki taraf ja rahi hoti hain, unke liye time directly unki current position ke barabar hota hai, kyunki unhe 0 end tak pahunchna hota hai. Jo ants right ki taraf ja rahi hoti hain, unke liye time n - position hota hai, kyunki unhe right end tak jaana hota hai. Ants ke beech collisions ka final answer par koi effect nahi padta, kyunki collision ko identity swap jaisa treat kiya ja sakta hai. Isliye last moment jab sab ants gir jaati hain, wahi hota hai jo in sab times me se maximum hota hai.

//Time Complexity (TC):
// Hum left vector ko ek baar traverse karte hain aur right vector ko ek baar traverse karte hain. Agar L left ants hain aur R right ants hain, to total operations O(L + R) hoti hain, jo overall linear time hai.

// Space Complexity (SC):
// Hum sirf ek variable ans use kar rahe hain, extra koi data structure nahi. Isliye auxiliary space O(1) hai (input vectors ke alawa).