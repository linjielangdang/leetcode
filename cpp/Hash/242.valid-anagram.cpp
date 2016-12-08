class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int s_size = s.size();
        int t_size = t.size();
        if(s_size != t_size)
        {
            return false;
        }
        
        //记录字符串s与t中每个小写字母出现的次数
        int s_letter[26] = {0};
        int t_letter[26] = {0};
        for(int i = 0; i < s.size(); ++i)
        {
             s_letter[s.at(i)-'a']++;
             t_letter[t.at(i)-'a']++;
        }
        
        for(int i = 0; i < 26; ++i)
        {
            if(s_letter[i] != t_letter[i])
            {
                return false;
            }
        }
        return true;
    }
};
