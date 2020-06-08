class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](auto& a, auto& b) -> bool {return a[0]-a[1] < b[0]-b[1];});
        
        for (auto i : costs) {
            cout<< i[0] <<" "<<i[1];
            cout<<endl;
        }
        int res = 0;
        for(int i = 0, j = costs.size()-1; i < j; ++i, --j)
            res += costs[i].front() + costs[j].back();
        return res;
    }
};
