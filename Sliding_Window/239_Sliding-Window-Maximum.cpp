class Solution {
public:
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
        // removing the largest value if its outside the window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        // remove all values from queue that are smaller than current value 
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}
};