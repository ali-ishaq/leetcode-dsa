class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target)   
                return mid;
            
            // Check which side is sorted
            if(nums[mid]>=nums[l]){ 
                // true, if left side is sorted                
                if(target>=nums[l]&&target<nums[mid]){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }else{
                // right side is sorted
                 if(target>nums[mid]&&target<=nums[r]){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }   
                
        }
        return -1; 
    }
};