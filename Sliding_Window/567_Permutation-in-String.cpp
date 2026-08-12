class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        vector<int> freq(26, 0), rfreq(26, 0);

        for (char& c : s1)
            freq[c - 'a']++;
        for (int i = 0; i < s1.size(); i++) {
            rfreq[s2[i] - 'a']++;
        }
       

        int l = 1;
        for (int r = s1.size(); r < s2.size(); r++) {
            rfreq[s2[l - 1] - 'a']--;
            rfreq[s2[r] - 'a']++;
            if (freq == rfreq) {
                return true;
            }
            l++;
        }
        return false;
    }
};