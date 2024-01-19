#include <bits/stdc++.h>

using namespace std;

//amount of prime numbers: 5862593
int const PNUM_AMOUNT = 5862600;

//the MAX_PNUM prime number we want: 101865019
int const MAX_PNUM = 101865025;

int num[MAX_PNUM], pnum[PNUM_AMOUNT], bits[PNUM_AMOUNT], ones[PNUM_AMOUNT], answ_indx, t, tmp, nmb, n, inputed;


int binarySearch(int a[], int target);

int main()
{
    int k = 1, j, i;

    //Eratosthenes
    for (i = 2; i <= MAX_PNUM; i++) {
        if (num[i] == 0) {
            num[i] = i;
            pnum[k++] = i;

            bits[k] = bits[k - 1] + 32 - __builtin_clz(i);
            ones[k] = ones[k - 1] + __builtin_popcount(i);
        }

        for (j = 0;; j++) {
            if ((j == k) || ((i * pnum[j]) > MAX_PNUM) || (pnum[j] > num[i])) break;
            num[i * pnum[j]] = pnum[j];
        }
    }

    cin >> t;
    for (int m = 1; m <= t; m++) {
        scanf("%d", &inputed); // same as cin>>inputed but faster

        //searches inputed number and if not found returns left index
        answ_indx = binarySearch(bits, inputed);
        if (answ_indx > 0)
            printf("%d\n", ones[answ_indx]);  // cout << ones[answ_indx];
        else {
            //it needs to be positive
            answ_indx = -answ_indx;

            //preserves amount of ones of last prime number that we want
            tmp = ones[answ_indx];

            //calculated how many bits should be in the number
            inputed = inputed - bits[answ_indx];

            //determines by how many figures the number should be shifted
            n = bits[answ_indx + 1] - bits[answ_indx] - inputed;

            //shifts the number and leaves exact number in which we want to calculate amount of ones
            nmb = (pnum[answ_indx] >> n);

            n = tmp + __builtin_popcount(nmb);
            printf("%d\n", n);
        }
    }


    return 0;
}

//finds exact answer or left one
int binarySearch(int a[], int target)
{
    int low = 0;
    int high = PNUM_AMOUNT - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] < target) {
            low = mid + 1;
        } else if (a[mid] > target) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -high;
}
