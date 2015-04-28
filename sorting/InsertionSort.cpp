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
 * Insert the one to the sorted array.
 *
 * Proposition: To sort a randomly-sorted array with distinct keys, insertion
 * sor uses ~ N^2/4 compares and ~ N^2/4 exchanges on average.
 *
 * Pf. Expect each entry to move halfway back.
 *
 * Best case: if the array is in assending order, insertion sort makes N-1 compares
 * and 0 exchanges.
 *
 * Worst case: if the array in descending order(and no duplicates), insertion sort
 * makes ~ N^2/2 compares and ~N^2/2 exchanges.
 */
void insertionSort(int a[], int n)
{
    // 1. Move the pointer to the right
    for (int i=1; i<n; ++i) {
        // 2. Moving from right to left, exchange a[i] with each larger entry to its left
        for (int j=i; j>0; --j) {
            if (a[j] < a[j-1])
                std::swap(a[j], a[j-1]);
            else
                break;
        }
    }
}

int main()
{
    int a[] = {5, 3, 2, 8, 1, 9, 4};
    //int a[] = {2, 3, 4, 5, 6, 2};
    int length = sizeof(a) / sizeof(a[0]);

    printArray(a, length);
    insertionSort(a, length);
    printArray(a, length);
}

