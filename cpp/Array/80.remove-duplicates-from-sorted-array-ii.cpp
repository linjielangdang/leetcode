class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::size_type len = nums.size();
        int index = 0;
        int count = 0;
        if (0 == len)
        {
            return 0;
        }
        for (int i = 1; i < len; ++i)
        {
        	if (nums[i] == nums[index])
        	{
        		++count; 
        	}
        	else
        	{
        		if (count > 0)
        		{
        			nums[++index] = nums[i-1];
        			nums[++index] = nums[i];
        		}        		
        		else
        		{
        			nums[++index] = nums[i];
        		}
        		
        		count = 0;
        	}
        	if ((len - 1 == i) && count)
        	{
        		nums[++index] = nums[i];
        	}
        } 
        return index + 1;
    }
};
