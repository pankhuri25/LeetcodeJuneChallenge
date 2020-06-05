static int _ = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> nums;
    int sum = 0;
    Solution(vector<int>& w) 
    {
        for(int x : w) 
        {
            sum += x;
            nums.push_back(sum);
        }
    }
    
    int pickIndex() {
        auto upper = upper_bound(nums.begin(),nums.end(),rand()%sum);
        return upper-nums.begin();
    }
};
