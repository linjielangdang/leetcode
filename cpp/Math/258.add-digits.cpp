class Solution {
public:
    int addDigits(int num) 
    {
        int m = num, count = 0;
        while ((0 != m) || (0 != count/10))
        {
            if (0 == m)
            {
                m = count;
                count = 0;
            }
            count += m%10;
            m /= 10;
        }
    
        return count;
    }
};
