#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> pos;
    for (int i = 0; i < players.size(); ++i)
        pos[players[i]] = i;

    for (const auto& calling : callings)
    {
        int p = pos[calling];
        swap(players.at(p - 1), players.at(p));
        swap(pos[players.at(p - 1)], pos[players.at(p)]);
    }

    return players;
}

int main()
{
    return 0;
}