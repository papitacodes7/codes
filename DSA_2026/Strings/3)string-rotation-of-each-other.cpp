class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        if(s1.size() != s2.size()) return false;
        string concatinated_string = s1 + s1; 
        int idx = concatinated_string.find(s2);
        if(idx == -1 ) return false;
        else return true;
    }
};


// like first string + second string + krdo and usse third string me rkh do.. fir check if the third string which is the added version of first and sec string has it in or not.. by using find() function.. ye index return krta jaha se woh element mila.. when we made that third string .. that's it. easy.