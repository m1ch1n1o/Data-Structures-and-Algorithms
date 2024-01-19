#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int cases, n;
long long res;

string s[200000];

// vector<char> chars = {'A', 'B', 'C', 'D'};
string chars = "ABCD";
map<vector<int>, int> cnt;

void get_combinations1(string &combos, int sz, vector<int> &points2)
{
    for (int i = 0; i < 4; i++) {
        // combos.push_back(chars[i]);
        combos += chars[i];
        if (sz <= 1) {
            fill(points2.begin(), points2.end(), 0);
            for (int m = 0; m < n; m++) {
                for (int j = 0; j < 5; j++) {
                    if (s[m][j] == combos[j]) {
                        points2[m]++;
                    }
                }
            }

            combos = combos.substr(0, 4);
            // combos.erase(combos.end() - 1);
            cnt[points2]++;
        } else {
            get_combinations1(combos, sz - 1, points2);
            combos = combos.substr(0, combos.size() - 1);
            // combos.erase(combos.end() - 1);
        }
    }
}

void get_combinations2(string &combos, int sz, vector<int> &points, vector<int> &points2, bool &boo)
{
    for (int i = 0; i < 4; i++) {
        boo = true;
        // combos.push_back(chars[i]);
        combos += chars[i];
        if (sz <= 1) {
            points2 = points;
            for (int m = 0; m < n; m++) {
                for (int j = 5; j < 10; j++) {
                    if (s[m][j] == combos[j - 5]) {
                        if (points2[m] == 0) {
                            boo = false;
                            break;
                        }
                        boo = true;
                        points2[m]--;
                    }
                }
                if (!boo) break;
            }

            combos = combos.substr(0, 4);
            if (boo) {
                // cout << "NIKOO" << endl;
                // cout << cnt[points2] << endl;
                res += cnt[points2];
            }
            // combos.erase(combos.end() - 1);
        } else {
            boo = true;
            get_combinations2(combos, sz - 1, points, points2, boo);
            combos = combos.substr(0, combos.size() - 1);
            // combos.erase(combos.end() - 1);
        }
    }
}


int main()
{
    cin >> cases;
    for (int k = 0; k < cases; k++) {
        cin >> n;
        vector<int> points(n, 0);
        vector<int> points2(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            cin >> points[i];
            points[i] /= 10;
        }
        // vector<char> combos;
        string combos = "";
        get_combinations1(combos, 5, points2);
        // cout << cnt[points] << endl;

        bool boo = true;
        get_combinations2(combos, 5, points, points2, boo);
        // cout  << "NIKO"<< endl;
        cout << res << endl;
        // cout << "NIKOEND" << endl;
        cnt.clear();
        res = 0;
        // cout << cnt [points2];
    }

    return 0;
}

