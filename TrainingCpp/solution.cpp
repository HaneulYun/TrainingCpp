#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    map<int, int> m;
    for (const auto n : array)
        ++m[n];
    auto pred = [](const auto& l, const auto& r) { return l.second < r.second; };
    auto gm = max_element(m.begin(), m.end(), pred);
    auto rm = max_element(m.rbegin(), m.rend(), pred);
    return gm->first == rm->first ? gm->first : -1;
}

int main()
{
    return 0;
}