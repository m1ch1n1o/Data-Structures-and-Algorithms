#include <bits/stdc++.h>

using namespace std;

int t, n, arr[1000005], len;
int res = INT_MAX;

vector<int>::iterator idx;

int main(){
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n;
        vector<int> v;
        res = INT_MAX;

        for(int j = 1; j <= n; j++)
            cin >> arr[j];

        cin >> len;
        if(len > n || n == 0 || len == 0){
            cout << -1 << endl;
            continue;
        }

        v.push_back(arr[1]);
        if(v.size() == len) res = min(res, v[len-1]);
        for(int j = 2; j <= n; j++){
            if(v.back() < arr[j] && len > v.size()) v.push_back(arr[j]);
            else if(v.back() > arr[j]){
                idx = lower_bound(v.begin(),v.end(), arr[j]);
                int k = idx - v.begin();
                v[k] = arr[j];
            }
            if(v.size() == len) res = min(res, v[len-1]);
        }
        if(v.size() < len) res = -1;

        cout << res << endl;
    }

    return 0;
}

