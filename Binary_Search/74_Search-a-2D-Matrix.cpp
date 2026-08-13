class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;

        while (l < r) {
            int mid = (l + r) / 2;
            int maxIdx = matrix[mid].size() - 1;
            if (matrix[mid][0] > target)
                r = mid - 1;
            else if (matrix[mid][maxIdx] < target )
                l = mid + 1;
            else
                break;
        }
        int row = (l + r) / 2;
        cout << row;
        l = 0;
        r = matrix[row].size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[row][mid] > target)
                r = mid - 1;
            else if (matrix[row][mid] < target)
                l = mid + 1;
            else
                return true;
        }

        return false;
    }
};