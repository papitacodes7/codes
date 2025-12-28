class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};



class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0, len = s.size() - 1;
        while(st<len){
            swap(s[st++], s[len--]);
        }
    }
};


// string reverse krni toh aate hi he.. isme kya explain krna fr..