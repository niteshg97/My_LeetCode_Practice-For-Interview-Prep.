#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // Find the maximum value in the array
        unsigned int maxVal = *max_element(nums.begin(), nums.end());

        // Number of bits required to represent maxVal
        int bitWidth = std::bit_width(maxVal);

        // Mask with bitWidth number of 1's
        unsigned int mask = (1u << bitWidth) - 1;

        // Pack the new values into the higher bits
        for (int i = 0, j = 0; i < n; i++, j += 2) {
            nums[j]     |= (nums[i] & mask) << bitWidth;
            nums[j + 1] |= (nums[i + n] & mask) << bitWidth;
        }

        // Extract the new values
        for (int i = 0; i < 2 * n; i++) {
            nums[i] >>= bitWidth;
        }

        return nums;
    }
};