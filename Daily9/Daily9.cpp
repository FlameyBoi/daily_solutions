using namespace std;

#include <string>

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int total = 0;
        int size = s.length();
        int first[26] = { 0 };
        int last[26] = { 0 };
        for (int i = 0; i < 26; i++)
        {
            first[i] = -1;
            last[i] = -1;
        }
        for (int i = 0; i < size; i++)
        {
            char index = s[i] - 'a';
            last[index] = i;
            if (first[index] == -1) first[index] = i;
        }
        for (int i = 0; i < 26; i++)
        {
            bool used[26] = { false };
            bool active = false;
            char unique = 0;
            if (first[i] == -1) continue;
            for (int j = first[i]; j < last[i] + 1; j++)
            {
                if (!active && s[j] == i + 'a')
                {
                    active = true;
                    continue;
                }
                if (active && s[j] == i + 'a')
                {
                    total += unique;
                    unique = 0;
                }
                if (active && !used[s[j] - 'a'])
                {
                    unique++;
                    used[s[j] - 'a'] = true;
                }
            }
        }
        return total;
    }
};