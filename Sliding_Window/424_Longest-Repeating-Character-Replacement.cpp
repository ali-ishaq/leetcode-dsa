
// Not the most optimal Approach (More Intuitive)
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l = 0, maxf = 0, maxl = 0;
        
        for (int r = 0; r < (int)s.size(); r++) {
            freq[s[r]]++;
            maxf=max(maxf,freq[s[r]]);

            while((r-l+1)-maxf>k){
                freq[s[l]]--;
                l++;
                for(auto& [key,val]:freq){
                    maxf=max(maxf,val);
                }
            }
            maxl = max(maxl, r - l + 1);
        }
        return maxl;
    }
};

// Optimal Approach Using hashmap (Less Intuitive) 
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l = 0, maxf = 0, maxl = 0;
        
        for (int r = 0; r < (int)s.size(); r++) {
            freq[s[r]]++;
            maxf=max(maxf,freq[s[r]]);

            if((r-l+1)-maxf>k){
                freq[s[l]]--;
                l++;
                // for(auto& [key,val]:freq){
                //     maxf=max(maxf,val);
                // }
            }
            if((r-l+1)-maxf<=k){
            maxl = max(maxl, r - l + 1);
            }
        } 
        return maxl;
    }
};

// use fixed (26) size array/vector to acheive best time complexity

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int l = 0, maxf = 0, maxl = 0;
        
        for (int r = 0; r < (int)s.size(); r++) {
            freq[s[r]-'A']++;
            maxf=max(maxf,freq[s[r]-'A']);

            if((r-l+1)-maxf>k){
                freq[s[l]-'A']--;
                l++;
            }
            maxl = max(maxl, r - l + 1);        
        } 
        return maxl;
    }
};