#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

std::unordered_map<char, int> dict_rmp;
std::unordered_map<char, int> dict_sorted_rmp;

int main() {
    int T, N;
    {
        using namespace std;

        freopen("input.txt", "r", stdin);

        cin >> T;
        for (int t = 0; t < T; ++t) {
            string S;
            long ans;

            dict_rmp.clear();

            struct {
                bool operator()(char lhs, char rhs) {
                    if (dict_rmp[lhs] < dict_rmp[rhs])
                        return true;
                    return false;
                }
            } CompRmp;

            cin >> N;
            cin >> S;

            for (int n = 0; n < N; ++n) {
                dict_rmp[S[n]] = n;
            }

            sort(S.begin(), S.end(), CompRmp);
            for (int n = 0; n < N; ++n) {
                dict_sorted_rmp[S[n]] = n;
            }

            ans = 0;
            for (int n = 0; n < N; ++n) {
                ans += abs(dict_rmp[S[n]] - dict_sorted_rmp[S[n]]);
            }
            cout << ans * 5 << "\n";
        }
    }
    return 0;
}
