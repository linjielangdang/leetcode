#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode, Subsets
// �������취,����,ʱ�临�Ӷ� O(2^n),�ռ临�Ӷ� O(n)
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) 
    {
    	sort(S.begin(), S.end()); // ���Ҫ������
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
		// ��ѡ S[step]
		subsets(S, path, step + 1, result);
		// ѡ S[step]
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
