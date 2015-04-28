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
 * Also known as h-sorting
 * 
 * Proposition. The worst-case number of compares used by shellsort with the 
 * 3x+1 increments is O(N^ 3/2 )
 */
void shellSort(int a[], int n)
{
    int h = 1;
    // 3x+1 increment sequence: 1, 4, 13, 40, 121, 364    
    while (h < n/3) h = 3*h + 1; 

    while (h >= 1) {
        // h-sort the array. insertion sort
        for (int i=h; i<n; ++i) {
            for (int j=i; j>=h; j-=h) {
                if (a[j] < a[j-h])
                    std::swap(a[j], a[j-h]);
            }
        }

        // move to next increment
        h /= 3;
    }
}

int main()
{
    int a[] = {5, 3, 2, 8, 1, 9, 4};
    //int a[] = {2, 3, 4, 5, 6, 2};
    int length = sizeof(a) / sizeof(a[0]);

    printArray(a, length);
    shellSort(a, length);
    printArray(a, length);
}

