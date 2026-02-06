#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int board[9][9];
bool row_check[9][10];
bool col_check[9][10];
bool square_check[9][10];
vector<pair<int, int>> zeros;


int get_square(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

void dfs(int cnt) {
    if (cnt == zeros.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    int r = zeros[cnt].first;
    int c = zeros[cnt].second;
    int sq = get_square(r, c);

    for (int num = 1; num <= 9; num++) {
        if (!row_check[r][num] && !col_check[c][num] && !square_check[sq][num]) {
            board[r][c] = num;
            row_check[r][num] = col_check[c][num] = square_check[sq][num] = true;
            
            dfs(cnt + 1);

            board[r][c] = 0;
            row_check[r][num] = col_check[c][num] = square_check[sq][num] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0) {
                int val = board[i][j];
                row_check[i][val] = true;
                col_check[j][val] = true;
                square_check[get_square(i, j)][val] = true;
            } else {
                zeros.push_back({i, j});
            }
        }
    }

    dfs(0);
}
