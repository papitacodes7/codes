class Solution {
  public:
    int maxSubStr(string str) {
        // Write your code here
        int cnt0 = 0, cnt1 = 0, ans = 0;
        for(char ch : str){
            if(ch == '0') cnt0++;
            else cnt1++;
            
            if(cnt0 == cnt1){
                ans++;
            }
        }
        if(cnt0 != cnt1) return -1;
        return ans;
    }
};


// jo bhi str he usme just 1 and zero's hi he.. what we can do is forloopcharwala on that str and then we can count if that char is equal to 0 if yes then cnt0++ warna cnt1++
// ye krne ke baad in the end agar like cnt0 cnt1 ke equal nhi hue toh like literlly it means str me 0 and 1 equal nhi he.. 
// now basically in the forloopcharwala we will be storing the ans as cnt0 == cnt1; and in the end wohi return krwa rhe honge..


// Given string me sirf '0' aur '1' hote hain.
// Hum ek single traversal me count0 aur count1 maintain karte hain.
//
// Har character ke liye:
// - agar '0' mila → count0++
// - warna '1' mila → count1++
//
// Jab bhi count0 == count1 hota hai,
// iska matlab abhi tak ka substring balanced hai,
// to hum ans++ kar dete hain (ek valid substring mil gaya).
//
// Loop ke end me:
// agar total count0 != count1 hai,
// to string ko completely equal substrings me split karna possible nahi hai,
// isliye -1 return karte hain.
//
// warna ans return kar dete hain, jo maximum possible substrings ka count hai.


// tc o(n) and sc o(1);