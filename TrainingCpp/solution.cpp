#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    brown = (brown - 4) / 2;
    for (int i = 0; i < brown; ++i)
        if (i * (brown - i) == yellow)
            return vector<int>{brown - i + 2, i + 2};
    return {};
}

int main()
{
    return 0;
}