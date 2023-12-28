#include <string>

using namespace std;

bool solution(string s)
{
    int cnt = 0;
    for (auto c : s)
    {
        if (c == '\(')
            ++cnt;
        else
            --cnt;
        if (cnt < 0)
            return false;
    }
    if (cnt != 0)
        return false;
    return true;;
}

int main()
{
    return 0;
}