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
  3 2 5 8 1 9 4
    ^     ^   ^
    j     i   |high
*/
 
// return the index of pivot
int partition(int a[], int low, int high)
{
    // index for the last element in the smaller array
    int j = low-1;
 
    for (int i=low; i<=high-1; ++i) {
        if (a[i] < a[high]) { // a[high] is the pivot
            std::swap(a[i], a[++j]);
        }
        printArray(a, high-low+1);
    }
 
    std::swap(a[++j], a[high]);
 
    cout << "after partition: ";
    printArray(a, high-low+1);
    return j;
}
 
 
void quickSort(int a[], int low, int high)
{
    if (low >= high) {
        return;
    }
 
    int index = partition(a, low, high);
    quickSort(a, low, index-1);
    quickSort(a, index+1, high);
}
 
int main()
{
    int a[] = {5, 3, 2, 8, 1, 9, 4};
    //int a[] = {2, 3, 4, 5, 6, 2};
    int length = sizeof(a) / sizeof(a[0]);
 
    printArray(a, length);
    quickSort(a, 0, length-1);
    printArray(a, length);
}
