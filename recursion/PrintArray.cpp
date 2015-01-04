#include <iostream>
using namespace std;

//// divide-and-conquer paradigm
void printArray(int a[], int low, int high)
{
    if (low > high) {
        return;
    } else if (low == high) {
        cout << a[low] << endl;
    } else {
        int mid = (high-low)/2 + low;
        printArray(a, low, mid);
        printArray(a, mid+1, high);
    }
}

/// tail recursive
void printArray2(int a[], int low, int high)
{
    while (low < high) {
        int mid = (high-low)/2 + low;
        printArray2(a, low, mid);
        low = mid+1;
    }

    cout << a[high] << endl;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(a) / sizeof(a[0]);
    //printArray2(a, 0, length-1);
    printArray2(a, 0, length-1);

    return 0;
}
