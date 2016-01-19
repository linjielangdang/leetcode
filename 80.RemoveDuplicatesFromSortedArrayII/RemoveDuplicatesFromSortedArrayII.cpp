#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::size_type len = nums.size();
        int index = 0;
        int count = 0;
        // �ڶ����ύʱ�������˶Կ�vector���жϣ�����Error
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
            // ��һ���ύʱ�����ڰ� �ж����� (i == len - 1) д�� (i = len - 1)����Error���Ժ������ж���䣬��������ܲ�����ֵ�;���������ֵ��Ӧ����ע��
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
