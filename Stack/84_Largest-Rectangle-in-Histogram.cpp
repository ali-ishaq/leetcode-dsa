class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int area = 0;
        for (int i = 0; i < heights.size(); i++) {
            int lastPopIdx = i;
            while (!st.empty() && st.top().first > heights[i]) {
                area = max(area, (i - st.top().second) * st.top().first);
                lastPopIdx = st.top().second;
                st.pop();
            }
            if (st.empty()) {
                st.push({heights[i], 0});
            } else if (st.top().first != heights[i]) {
                st.push({heights[i], lastPopIdx});
            }
        }
        while (!st.empty()) {
            area = max(area, (int)((heights.size() - st.top().second) * st.top().first));
            st.pop();
        }
        return area;
    }
};