#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;

    vector<int> S (n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    ll best = 0;
    vector<int> best_output;
    for (int i = 0; i < n; i++) {
        ll current = S[i];
        vector<int> cur_output (n);
        cur_output[i] = S[i];

        if (i < n - 1) {
            int rol_min = S[i];
            for (int j = i + 1; j < n; j++) {
                rol_min = min(S[j], rol_min);
                current += rol_min;
                cur_output[j] = rol_min;
            }
        }

        if (i > 0) {
            int rol_min = S[i];
            for (int j = i - 1; j >= 0; j--) {
                rol_min = min(S[j], rol_min);
                current += rol_min;
                cur_output[j] = rol_min;
            }
        }

        if (current > best) {
            best = current;
            best_output = cur_output;
        }
    }

    for (auto n : best_output) {
        cout << n << " ";
    }

    return 0;
}