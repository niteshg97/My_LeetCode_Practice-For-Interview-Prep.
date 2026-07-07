#include <bit>
#include <vector>

class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        constexpr unsigned int max_value = 1000;
        const int bit_width = std::bit_width(max_value);
        const int mask = (1 << bit_width) - 1;

        for (int i = 0, j = 0; i < n; ++i, j += 2) {
            nums[j] |= (nums[i] & mask) << bit_width;
            nums[j + 1] |= (nums[i + n] & mask) << bit_width;
        }

        for (int i = 0; i < n * 2; ++i) {
            nums[i] >>= bit_width;
        }

        return nums;
    }
};