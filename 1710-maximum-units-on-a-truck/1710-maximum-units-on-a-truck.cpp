class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[1] > b[1];  // Sort by units per box in descending order
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);

        int profit = 0;
        for (int i = 0; i < boxTypes.size(); i++) {
            if (boxTypes[i][0] <= truckSize) {
                profit += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } else {
                profit += truckSize * boxTypes[i][1];
                break; // Truck is full
            }
        }
        return profit;
    }
};
