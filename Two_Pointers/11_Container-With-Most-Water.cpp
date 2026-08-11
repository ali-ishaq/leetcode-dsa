class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxWater=0;
        int l=0,r=n-1;
        
        while(l<r){
            // int area=min(height[l],height[r])*(r-l);
            maxWater=max(maxWater,min(height[l],height[r])*(r-l));
            if(height[l]>height[r]){
                r--;
            }else{
                l++;
            }
        }
        return maxWater;

    }
};