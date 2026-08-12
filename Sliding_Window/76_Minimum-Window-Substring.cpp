class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        for (char& c : t)
            need[c]++;

        int l = 0;
        int start = 0;
        int len = INT_MAX;
        int valid = 0;

        for (int r = 0; r < s.size(); r++) {
            if (need.count(s[r])) {
                need[s[r]]--;
                if (need[s[r]]==0)
                    valid++;
            }

            while (valid == need.size()) {
                if (r - l + 1 < len) { 
                    len = r - l + 1;
                    start = l;
                }
                if (need.count(s[l])) {
                    need[s[l]]++;
                    if (need[s[l]]>0) {
                        valid--;
                    }
                }
                l++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};