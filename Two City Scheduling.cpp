class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        vector<int> arr;
        int minCost=0;
        for(int i=0; i<costs.size(); i++)
        {
            minCost+=costs[i][0];
            arr.push_back(costs[i][1]-costs[i][0]);
        }
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<costs.size()/2; i++)
        {
            minCost+=arr[i];
        }
        return minCost;
    }
};
