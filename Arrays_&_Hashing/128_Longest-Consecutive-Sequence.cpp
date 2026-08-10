class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> s;
        for (int& num : nums) {
            s.insert(num);
        }
        int maxLen = 1;
        for (int num : s) { 
            if (s.find(num - 1) == s.end()) {
                int j = 1;
                while (s.find(num + j) != s.end()) {
                    j++;
                }
                maxLen = max(maxLen, j);
            }
        }
        return maxLen;
    }
};