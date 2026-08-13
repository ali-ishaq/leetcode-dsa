class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // Maximum possible speed Koko would ever need.
        int mx = INT_MIN;
        for (int num : piles)
            mx = max(mx, num);

        // Binary search for the minimum valid eating speed.
        int l = 1, r = mx;
        int minSpeed = INT_MAX;

        while (l <= r) {
            int mid = (l + r) / 2;
            int currTime = 0;

            for (int num : piles) {
                currTime += ceil(double(num) / mid);

                // No need to calculate further once we exceed h.
                if (currTime > h)
                    break;
            }

            // mid is too slow, so search the right half.
            if (currTime > h)
                l = mid + 1;
            else {
                // mid works but try to find a smaller valid speed.
                r = mid - 1;
                minSpeed = min(minSpeed, mid);
            }
        }

        return minSpeed;
    }
};
