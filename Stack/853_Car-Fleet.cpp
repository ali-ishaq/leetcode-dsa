class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> posTime; // {position, time to reach target} 

        for (int i = 0; i < position.size(); i++) {
            double time = (target - position[i]) / double(speed[i]);
            posTime.push_back({position[i], time});
        }

        // sort(posTime.begin(), posTime.end(),
        //      [](const pair<int,double>& a, const pair<int,double>& b) {
        //          return a.first < b.first;
        //      });

        sort(posTime.begin(), posTime.end());

        double lastTime = 0;
        int fleets = 0;

        for (int i = posTime.size() - 1; i >= 0; i--) {
            if (posTime[i].second > lastTime) {
                fleets++;
                lastTime = posTime[i].second;
            }
        }

        return fleets;
    }
};