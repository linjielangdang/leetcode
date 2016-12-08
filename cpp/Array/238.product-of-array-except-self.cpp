class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zero_count = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            if (0 != nums[i])
            {
                product *= nums[i];
            }
            else
            {
                zero_count += 1; 
            }
        }
        for (int i = 0; i < len; ++i)
        {
            // if there are more than one zero element in the given array, the result will be an array with all zero elements
            if (zero_count > 1)
            {
                nums[i] = 0;
                continue;
            }
            // if there is only one zero element 
            if (1 == zero_count)
            {
                if (0 == nums[i])
                {
                    nums[i] = product;
                }
                else
                {
                    nums[i] = 0;
                }
                continue;
            }
            // if there is no any zero element
            nums[i] = product / nums[i];
        }
        return nums;
    }
};
