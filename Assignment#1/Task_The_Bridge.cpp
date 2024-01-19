#include <bits/stdc++.h>

using namespace std;

int arr[100010], sz, answ;
int first = 1;

int main()
{
    scanf("%d", &sz);
    for (int i = 1; i <= sz; i++) {
        scanf("%d", &arr[i]);
    }

    while (true) {
        if (sz > 3) {
            answ += min(arr[sz] + arr[sz - 1] + 2 * arr[first], 2 * arr[first + 1] + arr[first] + arr[sz]);
            sz -= 2;
        } else if (sz == 3) {
            answ += (arr[first] + arr[first + 1] + arr[first + 2]);
            break;
        } else if (sz == 2) {
            answ += arr[first + 1];
            break;
        } else if (sz == 1) {
            answ += arr[first];
            break;
        }
    }
    printf("%d\n", answ);

    return 0;
}
