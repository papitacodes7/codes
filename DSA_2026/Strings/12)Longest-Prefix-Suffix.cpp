class Solution {
  public:
    int getLPSLength(string &str) {
        // code here
        int n = str.length();
        int p = 0, s = 1, pos = 1, count = 0;
        while(p<n && s<n){
            if(str[p] == str[s]){
                p++;
                s++;
                count++;
            }
            else{
                p = 0;
                pos++;
                s = pos;
                count = 0;
            }
        }
        return count;
    }
};


// basically ek string dedenge and like prefix means string ke start se shuru krna and suffix means
// string ke back se shuru krna..
// prefix shuru hota he.. 0 se n-1 tk..last wla nhi..
// suffix shuru hota he... 1 se n tk first wala nhi..
// basically according to question.. we need prefix = suffix.. 
// this means ki prefix and suffix same word se shuru hona chahiye.. 
// now basically match krte hue chalenge p and s ko agar match nhi mila toh s ko aage bdhynge..with pos.
// pos is used to track kaha tk ans aarha he..


// // /*
// We are given a string and we need to find the length of the
// longest proper prefix which is also a suffix.

// Prefix always starts from index 0.
// Suffix can start from index 1 up to n-1 (proper suffix).

// We use two pointers:
// p → points to prefix (starts from 0)
// s → points to suffix (starts from 1)

// We compare characters at p and s:
// - If they match, we move both pointers forward and increment count
// - If they do not match, we reset prefix pointer p to 0,
//   move suffix start to the next position using pos,
//   and reset count

// pos helps us try every possible suffix starting position.

// The maximum continuous match obtained at the end
// represents the length of the longest prefix
// which is also a suffix.
// */