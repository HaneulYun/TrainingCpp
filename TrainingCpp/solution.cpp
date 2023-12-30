#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<string> exts{ "code", "date", "maximum", "remain" };
    int ext_idx = find(exts.begin(), exts.end(), ext) - exts.begin();
    data.erase(remove_if(data.begin(), data.end(), [&](const vector<int>& v) {
        return v[ext_idx] > val_ext;
        }), data.end());
    int sort_by_idx = find(exts.begin(), exts.end(), sort_by) - exts.begin();
    sort(data.begin(), data.end(), [&](const auto& l, const auto& r) {
        return l[sort_by_idx] < r[sort_by_idx];
        });
    return data;
}

int main()
{
    return 0;
}