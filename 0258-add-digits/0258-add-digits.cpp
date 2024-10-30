class Solution {
public:
    int solve(int n)
    {
        int temp=0;
        while(n>0)
        {
            temp+=n%10;
            n=n/10;
        }
        return temp;
    }
    int addDigits(int num) {
        while(num>=10)
        {
        num = solve(num);
        }
        return num;
    }
};