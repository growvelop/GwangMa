#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, del;
int root = -1;
vector<int> parent;
vector<int> child_count;

void input() {
    cin >> N;
    parent.resize(N);
    child_count.assign(N, 0);

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        parent[i] = p;
        if (p == -1) {
            root = i;
        }
        else {
            child_count[p]++;
        }
    }
    cin >> del;
}

void solve() {
    if (del == root) {
        cout << 0 << "\n";
        return;
    }
    int parent_of_D = parent[del];
    if (parent_of_D != -1) {
        child_count[parent_of_D]--;
    }

    int leaf_count = 0;
    for (int i = 0; i < N; i++) {
        if (i != del) {
            bool isdel = false;
            int curr = i;
            while (parent[curr] != -1) {
                if (parent[curr] == del) {
                    isdel = true;
                    break;
                }
                curr = parent[curr];
            }

            if (!isdel && child_count[i] == 0) {
                leaf_count++;
            }
        }
    }
    cout << leaf_count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();

    return 0;
}