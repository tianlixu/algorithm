/*
 Source : NA
 Author : Alex Xu
 Date   : June 03, 2015
 Problem:
Given: two arrays as input, and find a number that is present in first array A[] but is missing in second array B[].
*/

#include <iostream>
#include <unordered_set>

using namespace std;



class Solution {
public:
    /*
     * Time: O(n)
     */
    int findMissing(int A[], int m, int B[], int n) {
        // suppose m = n+1
        int i;
        int val = 0;
        for (i=0; i<n; i++) {
            val += A[i] - B[i];
        }

        val += A[i]; // i == m-1

        return val;
    }

    /*
     * Time: O(m+n)
     * with hash_set, the value in hash_set is unique
     */
    int findMissing2(int A[], int m, int B[], int n) {
        std::unordered_set<int> s;
        for (int j=0; j<n; j++)
            s.insert(B[j]);

        int i;
        for (i=0; i<m; i++) {
            if (s.find(A[i]) == s.end())
                break;
        }
        
        return A[i];
    }
    
    /*
     * Time: O(n^2)
     *
     * Using nested loops on arrays will give you a O(n^2) time complexity,
     * which is not desired.
     */
    int findMissing3(int A[], int m, int B[], int n) {
        int i;
        int j;
        
        for (i=0; i<m; i++) {
            for (j=0; j<n; j++) {
                if (A[i] == B[j])
                    break;
            }

            if (j >= n)
                break;
        }
        
        return A[i];
    }
};


int main()
{
    int A[] = {1,2,3,4,5,6,7,8,9,0};
    int m = sizeof(A) / sizeof(int);
    int B[] = {1,2,3,4,5,6,8,9,0};
    int n = sizeof(B) / sizeof(int);    

    Solution s;
    int missingNumber = s.findMissing2(A, m, B, n);
    cout << "missing number is: " << missingNumber << endl;

    return 0;
}
