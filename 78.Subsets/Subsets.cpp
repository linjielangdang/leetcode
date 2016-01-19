#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode, Subsets
// 增量构造法,深搜,时间复杂度 O(2^n),空间复杂度 O(n)
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) 
    {
    	sort(S.begin(), S.end()); // 输出要求有序
    	vector<vector<int> > result;
    	vector<int> path;
   		subsets(S, path, 0, result);
    	return result;
	}
private:
    static void subsets(const vector<int> S, vector<int> path, int step, vector<vector<int> > &result) 
    {
		if (step == S.size()) 
		{
			result.push_back(path); 
			return;
		}
		// 不选 S[step]
		subsets(S, path, step + 1, result);
		// 选 S[step]
		path.push_back(S[step]);
		subsets(S, path, step + 1, result);
		path.pop_back();
	}
};

int main()
{
	Solution test;
	vector<int> s, temp;
	vector < vector<int> > ret;
	vector < vector<int> >::const_iterator m;
	vector <int> ::const_iterator n;
	for (int i = 0; i < 3; ++i)
	{
		s.push_back(i+1);
	}
	ret = test.subsets(s);
	for (m = ret.begin(); m != ret.end(); ++m)
	{
		temp = *m;
		for (n = temp.begin(); n != temp.end(); ++n)
		{
			cout << *n << " ";
		}
		cout << endl;
	}
	return 0;
}
