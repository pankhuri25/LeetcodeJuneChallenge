class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        
        //approach 1
        
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        //approach 2
        /*
        int low=0;
        int high=nums.size()-1;  //or nums.back();
        
        while(low<=high)
        {
            int mid= low + (high-low)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
            
        }
        return low;
*/

    }
};
