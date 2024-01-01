#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int a = 0, b = 0;
    for (auto n : num_list)
        ((n % 2 ? a : b) *= 10) += n;
    return a + b;
}

int main()
{
    return 0;
}