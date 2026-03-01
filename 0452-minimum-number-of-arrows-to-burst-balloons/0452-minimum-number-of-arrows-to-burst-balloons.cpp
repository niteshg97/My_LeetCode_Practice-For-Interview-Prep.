bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1]; // sort by end coordinate
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), cmp);
        int arrows = 1;
        int lastEnd = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > lastEnd) {
                // need a new arrow
                arrows++;
                lastEnd = points[i][1];
            }
            // else, current balloon is already burst by the same arrow
        }

        return arrows;
    }
};
