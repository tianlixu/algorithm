/* Algorithm for the mean value of a big array
 * 
 * Suppose x is the mean value for the previous n numbers and y is the value
 * for the n+1th number, then the mean value for the whole n+1 numbers would be:
 * (n*x + y)/(n+1)
 * = (n*x + x - x + y)/(n+1)
 * = ((n+1)*x + (y-x))/(n+1)
 * = x + (y-x)/(n+1)
 */

#include <iostream>

using namespace std;

double getMeanValue(double a[], int  n) {
    double mean = 0;

    for (int i=0; i<n; ++i) {
        mean += (a[i] - mean)/(i + 1);
    }
    
    return mean;
}


int main()
{
    double a[5] = {1.0, 2.0, 7.90, 4.0, 5.0};
    int length = sizeof(a) / sizeof(a[0]);

    double mean = getMeanValue(a, length);

    cout << "the mean value is: " << mean << endl;

    return 0;
}
