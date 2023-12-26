#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    string c = board[h][w];
    int l = board.size();
    int s = 0;

    if (w > 0 && board[h][w - 1] == c) ++s;
    if (h > 0 && board[h - 1][w] == c) ++s;
    if (w < l - 1 && board[h][w + 1] == c) ++s;
    if (h < l - 1 && board[h + 1][w] == c) ++s;

    return s;
}

int main()
{
    return 0;
}