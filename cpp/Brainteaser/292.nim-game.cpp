class Solution {
public:
    bool canWinNim(int n)
    {
        return  (0 == n % 4) ? false: true;
    }
};
