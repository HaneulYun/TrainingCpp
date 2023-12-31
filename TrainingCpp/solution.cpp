#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int x, y, n;
};

void search(vector<int>& preorder, vector<int>& postorder, vector<Node>::iterator begin, vector<Node>::iterator end)
{
    auto iter = max_element(begin, end, [](const auto& l, const auto& r) { return l.y < r.y; });

    preorder.push_back(iter->n);
    if (begin != iter)
        search(preorder, postorder, begin, iter);
    if (iter + 1 != end)
        search(preorder, postorder, iter + 1, end);
    postorder.push_back(iter->n);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node> nodes(nodeinfo.size());
    for (int i = 0; i < nodeinfo.size(); ++i)
        nodes[i] = { nodeinfo[i][0], nodeinfo[i][1], i + 1 };
    sort(nodes.begin(), nodes.end(), [](const auto& l, const auto& r) { return l.x < r.x; });

    vector<vector<int>> answer(2);
    search(answer[0], answer[1], nodes.begin(), nodes.end());
    return answer;
}

int main()
{
    return 0;
}