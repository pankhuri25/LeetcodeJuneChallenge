class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()<=1) return;
        int i=0,nz=0,nt=nums.size()-1;
        int temp,temp2;
        while(i<=nt)
        {
            if(nums[i]==0)
            {
                temp=nums[nz];
                nums[nz]=nums[i];
                nums[i]=temp;
                i++;
                nz++;
            }
             else if (nums[i]==1)
             {
                 i++;
             }

           else if(nums[i]==2)
            {
                temp2=nums[i];
                nums[i]=nums[nt];
                nums[nt]=temp2;
                nt--;
            }
        }
    }
};
