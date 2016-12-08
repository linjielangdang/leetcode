class Solution {
public:
    int mySqrt(int x) 
    { 
        if (0 == x || 1 == x)
        {
            return x;
        }
        long int root = 1;
        root = (root*root + x)/(2*root);
        while(root*root > x)
        {
            root = (root*root + x)/(2*root);
        }
        return root;
    }
};
