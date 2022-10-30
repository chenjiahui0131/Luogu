#include <iostream>
#include <vector>

using namespace std;

void input(vector<vector<int>> &list, int &size, int &x_target, int &y_target) {
    int x0, y0, w, h;
    cin >> size;
    for (size_t i = 0; i < size; i++) {
        cin >> x0 >> y0 >> w >> h;
        list.push_back({x0, y0, x0 + w, y0 + h});
    }
    cin >> x_target >> y_target;
}

bool is_occupied(int x_target, int y_target, int x0, int y0, int x1, int y1) {
    return (x_target >= x0 && x_target <= x1 && y_target >= y0 && y_target <= y1);
}

int work(vector<vector<int>> &list, int &x_target, int &y_target) {
    int res = -1;
    for (size_t i = 0; i < list.size(); i++) {
        auto item = list[i];
        if (is_occupied(x_target, y_target, item[0], item[1], item[2], item[3])) {
            res = i + 1;
        }
    }
    return res;
}

void output(int res) { cout << res << endl; }

int main() {
    vector<vector<int>> list;
    int                 size;
    int                 x_target, y_target;
    input(list, size, x_target, y_target);
    int res = work(list, x_target, y_target);
    output(res);
    return 0;
}
