class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0 || n == 1)    return nums;
        
        sort(nums.begin(),nums.end());
        
        vector<int> dp(n,1);
        int maxEle = INT_MIN;
        
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j] == 0){
                    int t = 1 + dp[j];
                    if(t > dp[i])   dp[i] = t;
                }
            }
            if(dp[i] > maxEle)  maxEle = dp[i];
        }
        
        vector<int> v;
        
        for(int i=n-1;i>=0;i--){
            if(dp[i] == maxEle){
                v.push_back(nums[i]);
                maxEle--;
            }
        }
        
        
        
        return v;
        
        /*
        //Approach 2
        if(nums.size()<=1)
            return nums;
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> ans;
        vector<int> parent(nums.size());
        parent[0] = 0;
        int countMax=1;
        int ansIndex = 0;
        for(int i=1; i<nums.size(); i++)
        {
            int val=0;
            int num = nums[i];
            parent[i] = i;
            for(int j=0; j<i; j++)
            {
                if(num%nums[j]==0)
                {
                    if(val<dp[j])
                    {
                        val = dp[j];
                        parent[i] = j;
                        if(countMax < val+1)
                        {
                            countMax = val+1;
                            ansIndex = i;
                        }
                    }
                }
            }
            dp[i] = val+1;
        }
        for(auto i:dp){
            cout<<i<<endl;
        }
        for(int i=0; i< countMax; i++)
        {
            ans.push_back(nums[ansIndex]);
            ansIndex = parent[ansIndex];
        }
        return ans;
        */
    }
};
