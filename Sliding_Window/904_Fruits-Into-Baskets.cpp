// Optimal Aproach
class Solution {
public:
    int totalFruit(vector<int> fruits) {
        unordered_map<int, int> map;
        int maxFruits = 0, l = 0;
       
        for (int r = 0; r < fruits.size(); r++) {           
            map[fruits[r]]++;
            if (map.size() > 2) {
                map[fruits[l]]--;
                if (map[fruits[l]] == 0) {
                    map.erase(fruits[l]);
                }
                l++;
            }
            maxFruits = max(maxFruits, r - l + 1);
        }
        return maxFruits;
    }
};
// Aproach 1
class Solution {
public:
  int totalFruit(vector<int>fruits) {
        unordered_set<int> s;
        int maxFruits = 0, l = 0;
        for (int r = 0; r < fruits.size(); r++) {
            if (!s.count(fruits[r])) {
                s.insert(fruits[r]);
            }
            if (s.size() > 2) {
                l = r - 1;
                while (fruits[l - 1] == fruits[l] || fruits[l - 1] == fruits[r]) {
                    l--;
                }
                s.erase(fruits[l-1]);
            }
            maxFruits=max(maxFruits,  r-l + 1);
        }
        return maxFruits;
    }
};