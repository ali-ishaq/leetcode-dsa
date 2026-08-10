class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> count;
        for (int n : nums) {
            count[n]++;
        }

        vector<vector<int>> freq(nums.size() + 1);
        for (auto& [num, c] : count) {
            freq[c].push_back(num);
        }

        vector<int> result;
        for (int i = freq.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : freq[i]) {
                if (result.size() == k)
                    break;
                result.push_back(num);
            }
        }
        return result;
    }
};