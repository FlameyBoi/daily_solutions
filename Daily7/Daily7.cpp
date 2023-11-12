
using namespace std;

#include <vector>
#include <unordered_map>

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, int> count;
        count[target] = -1;
        for (auto route : routes)
            for (auto station : route)
                count[station] = -1;
        count[source] = 0;
        while (true)
        {
            bool used = false;
            for (auto route = routes.begin(); route != routes.end(); route++)
            {
                int min = INT_MAX;
                bool usedLast = false;
                for (int station : *route)
                {
                    if (count[station] > -1 && count[station] < min)
                    {
                        min = count[station];
                        used = true;
                    }
                }
                if (used)
                {
                    for (int station : *route)
                    {
                        if (count[station] == -1 || min < count[station])
                        {
                            count[station] = min + 1;
                        }
                    }
                    routes.erase(route);
                    break;
                }

            }
            if (!used)
                break;
        }
        return count[target];
    }
};