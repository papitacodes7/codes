class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char> st;

        for(char ch : s) {

            // opening bracket
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            // closing bracket
            else {
                if(st.empty()) return false;

                char top = st.top();
                st.pop();

                if((ch == ')' && top != '(') ||
                   (ch == '}' && top != '{') ||
                   (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        return st.empty();
    }
};


// stack me daal opening brackets and stack se nikaal closing brackets. in the end empty aana chahiye.. now just edge cases check krle ki opening bracket is = to closing bracket he ya nahi.. like for example stack me insert krna he opening bracket.. but let's say stack khaali he toh return false..now the thing is.. if let's say ending bracket arhaa he toh like top pe uske opening bracket se match krna chahiye warna return false.. thts it.. 
//

//We push opening brackets into the stack and pop them when a closing bracket comes.
// If the stack is empty while popping, we return false.
// The closing bracket must match the opening bracket at the top of the stack, otherwise return false.
// In the end, the stack should be empty.

// ⏱ Complexity-
// Time Complexity: O(n)
// Space Complexity: O(n)

