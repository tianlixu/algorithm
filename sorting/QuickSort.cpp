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
    i     j   |high
*/

// return the index of pivot
int partition(int a[], int low, int high)
{
    // a[high] is the pivot
    int pivot = a[high];
    // index for the last element in the smaller subarray
    int i = low-1;

    for (int j=low; j<=high-1; ++j) {
        if (a[j] <= pivot) { 
            std::swap(a[++i], a[j]);
        }
        printArray(a, high-low+1);
    }
 
    std::swap(a[++i], a[high]);
 
    cout << "after partitioning: ";
    printArray(a, high-low+1);
    return i;
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

/// Radomized quicksort
int random(int min, int max)
{
    return (std::rand() % (max - min + 1) + min);
}

int randomizedPartition(int a[], int low, int high)
{
    std::srand(time(0));
    int i = random(low, high);
    printf("random pivot a[%d]=%d\n", i, a[i]);
           
    std::swap(a[i], a[high]);

    return partition(a, low, high);
}

void randomizedQuickSort(int a[], int low, int high)
{
    if (low >= high) {
        return;
    }

    int index = randomizedPartition(a, low, high);
    randomizedQuickSort(a, low, index-1);
    randomizedQuickSort(a, index+1, high);
}


/// Tail recursive quicksort
void tailRecursiveQuicksort(int a[], int low, int high)
{
    while (low < high) {
        // partition and sort left subarray
        int index = partition(a, low, high);
        tailRecursiveQuicksort(a, low, index-1);
        low = index+1;
    }
}
    
 
int main()
{
    int a[] = {5, 3, 2, 8, 1, 9, 4};
    //int a[] = {2, 3, 4, 5, 6, 2};
    int length = sizeof(a) / sizeof(a[0]);

    printf("The original arry is:\n");
    printArray(a, length);

    printf("Now, quick sort array:\n");
    //quickSort(a, 0, length-1);
    //randomizedQuickSort(a, 0, length-1);
    tailRecursiveQuicksort(a, 0, length-1);

    printf("The array after sorting:\n");
    printArray(a, length);
}
