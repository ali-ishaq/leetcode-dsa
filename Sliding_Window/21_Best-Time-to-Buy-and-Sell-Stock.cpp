class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=1;
        int maxProf=0;

        while(r<prices.size()){
            if(prices[l]<prices[r]){
                int prof=prices[r]-prices[l];
                maxProf=max(maxProf,prof);
            }else{
                l=r;
            }            
            r++;
        }
        return maxProf;
    }
};