#include <iostream>
#include <vector>
using namespace std;
class Solution
{
	public:
		vector<vector<int> > threeSum(vector<int>& num)
		{
			vector<vector<int> > result;
			if (num.size() < 3)
				return result;
		}
};

int main()
{
	int a[2] = {1 , 3};
	vector<int> vec(a, a+2);
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

