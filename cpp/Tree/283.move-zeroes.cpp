class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
       int len = nums.size(), count = 0;
       for (int i = 0; i < len; ++i)
       {
           if (0 != nums[i])
           {
               nums[count++] = nums[i];
           }
       }
       while (count < len)
       {
           nums[count++] = 0;
       }
    }
};
