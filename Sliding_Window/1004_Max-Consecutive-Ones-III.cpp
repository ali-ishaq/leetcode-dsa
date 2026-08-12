class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = 0, zeros = 0, l = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) zeros++;

            if (zeros > k) {
                if (nums[l] == 0) zeros--;
                l++;
            }

            len = max(len, r - l + 1);
        }
        return len;
    }
};