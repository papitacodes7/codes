class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Use a stack to store opening brackets

        // Go through each character in the string
        for(auto it : s) {
            // If it's an opening bracket, push it to the stack
            if(it == '(' || it == '{' || it == '[') {
                st.push(it);
            } else {
                // If it's a closing bracket and there's nothing in the stack, it's wrong
                if(st.size() == 0) return false;

                // Take the last opening bracket from the stack
                char ch = st.top();
                st.pop();

                // Check if it matches the current closing bracket
                if((it == ')' && ch == '(') || 
                   (it == ']' && ch == '[') || 
                   (it == '}' && ch == '{')) {
                    continue; // It's a match, move to next character
                } else {
                    return false; // It's not a match, return false
                }
            }
        }

        // If stack is empty, all brackets were matched correctly
        return st.empty();
    }
};

// #include<bits/stdc++.h>
// using namespace std;
// bool isValid(string s) {
//         stack<char>st; 
//         for(auto it: s) {
//             if(it=='(' || it=='{' || it == '[') st.push(it); 
//             else {
//                 if(st.size() == 0) return false; 
//                 char ch = st.top(); 
//                 st.pop(); 
//                 if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
//                 else return false;
//             }
//         }
//         return st.empty(); 
//     }
// int main()
// {
//     string s="()[{}()]";
//     if(isValid(s))
//     cout<<"True"<<endl;
//     else
//     cout<<"False"<<endl;
// }
