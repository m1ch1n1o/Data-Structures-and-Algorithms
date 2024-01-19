#include <bits/stdc++.h>

using namespace std;

const int N = 200001;
const int md = 998244353;

int n;
long long answer = 1;
long long arr[N], C[N], factorials[N], inv_factorials[N], inv_nums[N];

long long combinations(int a, int b);

int main()
{
    cin >> n;

    factorials[0] = factorials[1] = 1;
    inv_nums[0] = inv_nums[1] = 1;
    inv_factorials[0] = inv_factorials[1] = 1;

    for (int i = 2; i <= n; i++) {
        cin >> arr[i - 1];
        factorials[i] = (factorials[i - 1] * i) % md;
        inv_nums[i] = inv_nums[md % i] * (md - md / i) % md;
        inv_factorials[i] = (inv_nums[i] * inv_factorials[i - 1] % md);
    }

    factorials[n] = (factorials[n - 1] * n) % md;
    inv_nums[n] = inv_nums[md % n] * (md - md / n) % md;
    inv_factorials[n] = (inv_nums[n] * inv_factorials[n - 1] % md);

    for (int i = n - 2; i > 0; i--) {
        answer *= combinations(arr[i], arr[i + 1] + 1);
        answer %= md;
    }

    cout << answer << endl;

    return 0;
}

long long combinations(int a, int b)
{
    return factorials[b] * inv_factorials[a] % md * inv_factorials[b - a] % md;
}