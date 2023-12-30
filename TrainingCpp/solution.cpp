#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for (long long i = 0; i < r2; ++i)
        answer += sqrtl((long long)r2 * r2 - i * i);
    for (long long i = 0; i < r1; ++i)
        answer -= ceil(sqrtl((long long)r1 * r1 - i * i)) - 1;
    answer *= 4;
    return answer;
}

int main()
{
    return 0;
}