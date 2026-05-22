// approach .. stand at the current and then count the back and the n add to the dynamic array and then return the array


class StockSpanner {
    vector<int> v;

public:
    StockSpanner() {
    }

    int next(int price) {
        v.push_back(price);

        int count = 1;
        int n = v.size();

        for (int i = n - 2; i >= 0; i--) {
            if (v[i] <= price) {
                count++;
            } else {
                break;
            }
        }

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */