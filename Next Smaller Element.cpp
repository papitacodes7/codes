vector<int> prevSmallerElement(vector<int> arr) {
    vector<int> ans(arr.size(), 0);  // Output array to store results
    stack<int> s;                    // Stack to keep potential "previous smaller" elements

    for(int i = 0; i < arr.size(); i++) {
        // Remove all elements from the stack that are >= current element
        // Because they can't be "smaller"
        while(s.size() > 0 && s.top() >= arr[i]) {
            s.pop();
        }

        // If stack is empty, no smaller element to the left
        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();  // Top of stack is the previous smaller
        }

        // Push current element to stack to be used for next elements
        s.push(arr[i]);
    }

    return ans;  // Return the final array of previous smaller elements
}
