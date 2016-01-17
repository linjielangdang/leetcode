class Solution
{
	public:
		vector<int> twoSum(vector<int> &num, int target)
		{
			unordered_map<int, int> hash;
			vector<int> result;
			for (int i = 0; i < num.size(); ++i)
			{
				hash[num[i]] = i;
			}
			for (int i = 0; i < num.size(); ++i)
			{
				const int gap = target - num[i];
				if (hash.find(gap) != hash.end() && hash[gap] > i)
				{
					result.push_back(i + 1);
					result.push_back(hash[gap] + 1);
					break;
				}
			}
			return result;
		}
};