#include <iostream>
using namespace std;

/*
 * Recursive solution
 *
 * a[] = {1, 3, 5, 7, 9};
 */
int binarySearch(int a[], int low, int high, int target)
{
    if (high < low)
        return -1;
    
    int mid = (low + high) / 2;

    if (a[mid] > target)
        return binarySearch(a, low, mid-1, target);
    else if (a[mid] < target)
        return binarySearch(a, mid+1, high, target);
    else
        return mid;
}

/*
 * Iterative solution
 */
int binarySearch2(int a[], int low, int high, int target)
{
    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] > target)
            high = mid - 1;
        else if (a[mid] < target)
            low = mid + 1;
        else 
            return mid;
    }

    return -1;
}

int main()
{
    int a[] = {1, 2, 3, 5, 6, 7, 8, 9};
    int len = sizeof(a) / sizeof(a[0]);

    int target = 4;
    int index = binarySearch2(a, 0, len-1, target);

    cout << "index = " << index << endl;

    return 0;
}
