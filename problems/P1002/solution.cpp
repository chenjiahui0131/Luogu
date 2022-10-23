#include <iostream>
#include <vector>

using namespace std;

void input(int &n, int &m, int &x, int &y) { cin >> n >> m >> x >> y; };

bool is_valid(int cur_x, int cur_y) { return ((cur_x >= 0) && (cur_y >= 0)); }

void work(vector<vector<long long>> &f, int n, int m, int horse_x, int horse_y) {
    f[0][0] = 1;
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= m; y++) {
            int dt_x = abs(x - horse_x);
            int dt_y = abs(y - horse_y);
            if ((dt_x == 1 && dt_y == 2) || (dt_x == 2 && dt_y == 1) || (x == horse_x && y == horse_y)) {
                f[x][y] = 0;
            } else {
                if (is_valid(x - 1, y)) {
                    f[x][y] += f[x - 1][y];
                }
                if (is_valid(x, y - 1)) {
                    f[x][y] += f[x][y - 1];
                }
            }
        }
    }
};

void output(long long ans) { cout << ans << endl; };

int main() {
    int n, m, horse_x, horse_y;
    input(n, m, horse_x, horse_y);
    vector<vector<long long>> f(n + 1, vector<long long>(m + 1, 0));
    work(f, n, m, horse_x, horse_y);
    output(f[n][m]);
    return 0;
}