#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
	public:
		vector<vector<int> > threeSum(vector<int>& num)
		{
			vector<vector<int> > result;
			if (num.size() < 3)
				return result;
				
			sort(num.begin(), num.end());
			const int target = 0;
			int i = 1; 
			int last = num.size() - 1;
			int sum = 0;
			while (i < last)
			{
				sum = num[i] + num[i-1] + num[last];
				if(sum < target)
				{
					// 1.从最左边开始夹逼,如果三个数之和小于0则最小的2个数往右移
					++i;
				}
				else if (sum > target)
				{
					// 2.如果三个数之和大于0则最大的1个数往左移
					--last;
				}
				else if (target == sum)
				{
					// 3.三个数之和相等的时候把这三个数放到vector中
					vector<int> tempVec;
					tempVec.push_back(num[i-1]);
					tempVec.push_back(num[i]);
					tempVec.push_back(num[last]);
					result.push_back(tempVec);
					++i;
					while (num[i] == num[i-1])
					{
						++i;
					}
				}
			}
			return result;
		}
};

int main()
{
	int a[6] = {-1, 0, 1, 2, -1, -4};
	vector<int> vec(a, a+6);
	vector<vector<int> > ret;
	vector<vector<int> >::iterator iter;
	vector<int> innerRet;
	vector<int>::iterator innerIter;
	Solution s;
	ret = s.threeSum(vec);
	for (iter = ret.begin(); iter != ret.end(); ++iter)
	{
		innerRet = *iter;
		for (innerIter = innerRet.begin(); innerIter != innerRet.end(); ++innerIter)
		{
			cout << *innerIter << ' ';
		}
		cout << endl;
	}
	
	return 0;
}
