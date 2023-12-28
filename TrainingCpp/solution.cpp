#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0, p = 0;
    sort(targets.begin(), targets.end());
    for (auto iter = targets.begin(); iter != targets.end(); ++iter)
        if (p <= (*iter)[0])
        {
            p = (*iter)[1];
            for (auto t = iter; t != targets.end() && (*t)[0] < p; ++t)
                if ((*t)[1] < p)
                    p = (*t)[1];
            ++answer;
        }
    return answer;
}

int main()
{
    return 0;
}