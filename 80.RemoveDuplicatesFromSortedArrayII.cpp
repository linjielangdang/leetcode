#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::size_type len = nums.size();
        int index = 0;
        int count = 0;
        // 第二次提交时，忽略了对空vector的判断，导致Error
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
            // 第一次提交时，由于把 判断条件 (i == len - 1) 写成 (i = len - 1)导致Error，以后碰到判断语句，左侧条件能不是左值就尽量不是左值，应格外注意
            if ((len - 1 == i) && count)
            {
                nums[++index] = nums[i];
            }
        } 
        return index + 1;
    }
};

int main(int argc, char const *argv[])
{
	int len;
	Solution s;
	vector<int> vec;
	int array[7] = {1, 1, 2, 2, 3, 3, 3};
	for (int i = 0; i < 7; ++i)
	{
		vec.push_back(array[i]);
	} 
	len = s.removeDuplicates(vec);
	cout << "len :" << len << endl;
	for (int i = 0; i < len; ++i)
	{
		cout << vec[i] << " " ;
	}
	cout << endl;
	return 0;
}
