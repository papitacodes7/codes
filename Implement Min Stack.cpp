class MinStack {
  stack<long long> st;  // Stack to store elements (can store modified values)
  long long mini;       // Variable to store the current minimum

public:
  /** initialize your data structure here. */
  MinStack() {
    while (!st.empty()) st.pop();  // Ensure stack is empty at initialization //optional line
    mini = INT_MAX;                // Set initial minimum to maximum possible
  }

  void push(int value) {
    long long val = value;  // Promote value to long long to prevent overflow

    if (st.empty()) {
      mini = val;           // First element becomes the minimum
      st.push(val);         // Push as is
    } else {
      if (val < mini) {
        // Push a modified value to encode the previous minimum
        st.push(2 * val - mini);
        mini = val;         // Update current minimum
      } else {
        st.push(val);       // Normal push if value >= current minimum
      }
    }
  }

  void pop() {
    if (st.empty()) return;

    long long el = st.top();
    st.pop();

    if (el < mini) {
      // The popped value is a modified one; retrieve the previous minimum
      mini = 2 * mini - el;
    }
  }

  int top() {
    if (st.empty()) return -1;

    long long el = st.top();
    if (el < mini) return mini;  //
