class Solution {
public:
    int sumDigitsSq(int n)
    {
        int sum = 0;
        while(n>0)
        {
            int rem = n % 10;
            sum += rem*rem;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1)
        {
            if(s.contains(n))
                return false;

            s.insert(n);
            n = sumDigitsSq(n);
        }
        return n == 1;
    }
};
