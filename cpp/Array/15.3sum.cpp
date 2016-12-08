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
				sum = num[i] + num[i - 1] + num[last];
				if(sum < target)
				{
					++i;
				}
				else if (sum > target)
				{
					--last;
				}
				else if (target == sum)
				{
					vector<int> tempVec;
					tempVec.push_back(num[i - 1]);
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
