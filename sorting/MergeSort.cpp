#include <limits.h>
#include <string.h>
#include <iostream>

using namespace std;

void printArray(int a[], unsigned int len)
{
    for (int i=0; i<len; i++) {
        cout << a[i] <<" ";
    }
    cout << endl;
}

/*
It's O(n * log(n)), not O(log(n)). As you've accurately surmised, the entire input must be iterated through, and this must occur O(log(n)) times (the input can only be halved O(log(n)) times). n items iterated log(n) times gives O(n log(n)).
*/          
void merge(int a[], int low, int mid, int high)
{
    int lenL = mid - low + 1; // length of left array a[low....mid]
    int lenR = high - mid; // length of right array a[mid+1....high]

    int *L = new int[lenL + 1];
    int *R = new int[lenR + 1];
    memcpy(L, a+low, lenL * sizeof(int));
    L[lenL] = INT_MAX;
    memcpy(R, a + mid + 1 , lenR * sizeof(int));
    R[lenR] = INT_MAX;

    for (int i=0, j=0, k=low; k <= high; k++) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            ++ i;
        } else {
            a[k] = R[j];
            ++ j;
        }
    }

    delete [] L;
    delete [] R;
}

/*
 * 3 steps: sort left, sort right, then merge
 * should be called sortMerge?!
 */
void mergeSort(int a[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high)/2;
    // sort left
    mergeSort(a, low, mid);
    // sort right
    mergeSort(a, mid+1, high);
    // merge left and right
    merge(a, low, mid, high);
}


int main()
{
    int a[] = {5, 3, 2, 8, 1, 9, 4};
    //int a[] = {2, 3, 4, 5, 6, 2};
    int length = sizeof(a) / sizeof(a[0]);

    printArray(a, length);
    mergeSort(a, 0, length-1);
    printArray(a, length);
}
