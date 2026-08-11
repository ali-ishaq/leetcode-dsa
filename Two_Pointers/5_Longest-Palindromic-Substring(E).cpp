class Solution {
public:
    string longestPalindrome(string s) {
              
    string longStr;
    int i = 0;
    while (i < s.size()) {
        int l = i - 1, r = i + 1;

        while (r < (int)s.size() && s[i] == s[r]) r++;

        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }

        int newLen = r - l - 1;
        if (newLen > longStr.size()) {
            longStr = s.substr(l + 1, newLen);
        }
        i++;
    }
    return longStr;
}
    
};