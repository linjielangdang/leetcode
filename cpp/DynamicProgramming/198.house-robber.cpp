class Solution {
public:
    int recurse(vector<int>& table, vector<int>& nums, int start, int end)
    {
        if (start > end)
        {
            return 0;
        }
        if (-1 != table[start])
        {
            return table[start];
        }
       
        int robed = nums[start] + recurse(table, nums, start + 2, end);
        int nonRobed = recurse(table, nums, start + 1, end);
      
        table[start] = (robed > nonRobed) ? robed: nonRobed;
        return table[start];
    }
    
    int rob(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int len = nums.size();
        if (1 == len)
        {
            return nums[0];
        }
        
       vector<int> table(len, -1);
       return recurse(table, nums, 0, len -1);
    }
};
