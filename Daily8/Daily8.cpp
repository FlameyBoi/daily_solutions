using namespace std;

#include <string>

class Solution {
public:
    string sortVowels(string s) {
        int arr[10] = { 0 };
        char chr[10] = { 'A', 'E', 'I', 'O','U', 'a', 'e', 'i', 'o', 'u' };
        for (auto ch : s)
        {
            switch (ch)
            {
            case 'A':
                arr[0]++;
                break;
            case 'E':
                arr[1]++;
                break;
            case 'I':
                arr[2]++;
                break;
            case 'O':
                arr[3]++;
                break;
            case 'U':
                arr[4]++;
                break;
            case 'a':
                arr[5]++;
                break;
            case 'e':
                arr[6]++;
                break;
            case 'i':
                arr[7]++;
                break;
            case 'o':
                arr[8]++;
                break;
            case 'u':
                arr[9]++;
                break;
            }

        }
        int depleted = 0;
        for (int i = 0; i < s.length(); i++)
        {
            while (depleted < 10 && !arr[depleted]) depleted++;
            if (depleted == 10) break;
            char cur = tolower(s[i]);
            if (cur == 'a' || cur == 'e' || cur == 'i' || cur == 'o' || cur == 'u')
            {
                s[i] = chr[depleted];
                arr[depleted]--;
            }
        }
        return s;
    }
};