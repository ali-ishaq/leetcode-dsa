class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, vector<vector<int>>> map;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!isdigit(board[i][j])) {
                    continue;
                }
                if (map.find(board[i][j]) == map.end()) {
                    map[board[i][j]].push_back({i, j});
                } else {
                    for (int k = 0; k < map[board[i][j]].size(); k++) {
                        if ((map[board[i][j]][k][0] == i ||
                             map[board[i][j]][k][1] == j) ||

                            (floor(map[board[i][j]][k][0] / 3) ==
                                 floor(i / 3) &&
                             floor(map[board[i][j]][k][1] / 3) ==
                                 floor(j / 3))) {

                            return false;
                        }
                    }
                    map[board[i][j]].push_back({i, j});
                }
            }
        }
        return true;
    }
};