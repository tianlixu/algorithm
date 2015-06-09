#include <iostream>
using namespace std;

void printArray(int a[], int length)
{
	for (int i=0; i<length; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

/*
 * http://tlxu.blogspot.ca/2014/12/bubble-sort.html
 * 
 * Time: O(n^2)
 */
void bubbleSort(int a[], int n)
{
    int comparisons = 0;
    
    // round n-1 to 1
	for (int i=n-1; i>=1; --i) {
		for (int j=0; j<=i-1; ++j) {
            ++comparisons;
			if (a[j] > a[j+1]) {
                std::swap(a[j], a[j+1]);
			}
		}
	}

    cout << "Comparisons=" << comparisons << endl;
}

void bubbleSort2(int a[], int n)
{
    int comparisons = 0;
    bool swaped = true;
    int i = n-1; // round counter

    while (swaped) {
        swaped = false;

        for (int j=0; j<=i-1; ++j) {
            ++comparisons;
            if (a[j] > a[j+1]) {
                std::swap(a[j], a[j+1]);
                swaped = true;
            }
        }

        --i;
    }
    cout << "Comparisons=" << comparisons << endl;
}

void bubbleSort3(int a[], int n)
{
    int comparisons = 0;
    int i; // round counter
    int pos = n-1;
    
    while (pos > 0) {
        i = pos; 
        pos = 0;

        for (int j=0; j<=i-1; ++j) {
            ++comparisons;
            if (a[j] > a[j+1]) {
                std::swap(a[j], a[j+1]);
                pos = j;
            }
        }
    }
    cout << "Comparisons=" << comparisons << endl;    
}


int main()
{
	int a[] = {5, 3, 2, 8, 9, 4, 10, 11, 12};
	//int a[] = {5, 3, 2, 8, 9, 4, 10, 11, 12};    
    //int a[] = {5, 1, 2, 3, 4};
	int length = sizeof(a)/sizeof(a[0]);

	printArray(a, length);

	bubbleSort3(a, length);
	printArray(a, length);	
}

