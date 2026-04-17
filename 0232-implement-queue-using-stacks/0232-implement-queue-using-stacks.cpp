class MyQueue {
public:
    stack<int> st;
    stack<int> helper;

    MyQueue() {
    }

    void push(int x) {
        // Push at bottom
        if (st.size() == 0) {
            st.push(x);
            return;
        } else {
            while (st.size() > 0) {
                helper.push(st.top());
                st.pop();
            }
            st.push(x);
            while (helper.size() > 0) {
                st.push(helper.top());
                helper.pop();
            }
        }
    }

    int pop() {
        int x = st.top();
        st.pop();
        return x;
    }

    int peek() {
        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};
