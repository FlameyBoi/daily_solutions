using namespace std;

#include <unordered_map>


class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        std::unordered_map<int, int> mp;
        unsigned long total = 0;
        for (int num : nums)
        {
            long sum = num - rev(num);
            total = (total + mp[sum]) % 1000000007UL;
            mp[sum]++;
        }
        return total;
    }

    inline int rev(int n)
    {
        int out = 0;
        while (n)
        {
            out *= 10;
            out += n % 10;
            n /= 10;
        }
        return out;
    }
};