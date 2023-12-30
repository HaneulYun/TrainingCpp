#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    map<string, vector<int>> info{ {"diamond", {0, 100}}, {"iron", {1, 10}}, {"stone", {2, 1}} };
    vector<int> area_stress((minerals.size() + 4) / 5);
    for (int i = 0, s = min(accumulate(picks.begin(), picks.end(), 0) * 5, (int)minerals.size()); i < s; ++i)
        area_stress[i / 5] += info[minerals[i]][1];
    sort(area_stress.begin(), area_stress.end(), greater<>());
    auto iter = area_stress.begin();
    for (const auto k : { "diamond", "iron", "stone" })
        for (int i = 0; i < picks[info[k][0]] && iter != area_stress.end(); ++i, ++iter)
            for (int j = 0; j < 3; ++j, *iter /= info["iron"][1])
                answer += *iter % info["iron"][1] * pow(5, max(j - 2 + info[k][0], 0));
    return answer;
}

int main()
{
    return 0;
}