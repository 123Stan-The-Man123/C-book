#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void) {
    int numbers[] = {1, 3, 4, 7, 10};

    printf("%d\n", binsearch(3, numbers, 5));

    return 0;
}
int binsearch(int x, int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (x > v[mid]) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    if (v[low] == x) {
        return low;
    }

    return -1;
}