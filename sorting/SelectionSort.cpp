#include <iostream>
using namespace std;

void printArray(int a[], unsigned int len)
{
    for (int i=0; i<len; i++) {
        cout << a[i] <<" ";
    }
    cout << endl;
}

/**
 * Select the smallest(largest) element and exchange its position.
 *
 * Proposition: Selection sort uses (N-1) + (N-2) + ... + 1 + 0 ~ N^2/2 compares
 * and N exchanges
 *
 * Running time insensitive to input: Quadratic time, even if input is sorted.
 *
 * Data movements is minimal: Linear number of exchanges.
 */
void selectionSort(int a[], int n)
{
    for (int i=0; i<n; ++i) {
        int min = i;
        
        for (int j=i+1; j<n; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }

        if (min != i) {
            std::swap(a[i], a[min]);
        }
    }
}

/// Select min and max at the same time.
void selectionSort2(int a[], int n)
{
    for (int i=0; i<=n/2; ++i) {
        int min = i;
        int max = n-1-i;
        
        for (int j=i+1; j<=n-1-i; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
            if (a[j] > a[max]) {
                max =j;
            }
        }

        if (min != i) {
            std::swap(a[i], a[min]);
        }
        if (max != n-1-i) {
            std::swap(a[n-1-i], a[max]);
        }
    }
}

int main()
{
    int a[] = {5, 3, 2, 8, 1, 9, 4};
    //int a[] = {2, 3, 4, 5, 6, 2};
    int length = sizeof(a) / sizeof(a[0]);

    printArray(a, length);
    //selectionSort2(a, length);
    selectionSort(a, length);
    printArray(a, length);
}

