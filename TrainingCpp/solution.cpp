#include <string>
#include <vector>
#include <set>

using namespace std;

int getSize(int x, int y, vector<vector<int>>& land, set<int>& linked)
{
    if (!land[y][x])
        return 0;

    land[y][x] = 0;
    int sum = 1;
    if (x > 0)
        sum += getSize(x - 1, y, land, linked);
    if (x < land[0].size() - 1)
        sum += getSize(x + 1, y, land, linked);
    if (y > 0)
        sum += getSize(x, y - 1, land, linked);
    if (y < land.size() - 1)
        sum += getSize(x, y + 1, land, linked);
    linked.insert(x);

    return sum;
}

int solution(vector<vector<int>> land) {
    vector<int> sum(land[0].size());

    for (int i = 0; i < land.size(); ++i)
        for (int j = 0; j < land[0].size(); ++j)
        {
            set<int> linked;
            int size = getSize(j, i, land, linked);
            for (auto v : linked)
                sum[v] += size;
        }

    int max = 0;
    for (auto v : sum)
        if (v > max)
            max = v;
    return max;
}

int main()
{
    return 0;
}