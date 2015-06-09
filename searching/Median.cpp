/*
  Author : Alex Xu
  Date   : Jun 09, 2015
  Problem: Find the median of an unsorted array
 */

#include <iostream>
#include <queue>

using namespace std;


struct comparatorMin {
    bool operator() (int a, int b) {
        return a > b; // min heap, top is the smallest
    }
};

struct comparatorMax {
    bool operator() (int a, int b) {
        return a < b; // max heap, top is the largest
    }
};


class Solution {
public:
    int findMedian(int A[], int n) {
        int mid = n/2 + n%2;
        return findKthNumberMinHeap(A, n, mid);
    }

    /* 
     * Max heap solution
     *
     * Time: O((n+k)lgn)
     * Space: O(n)
     */
    int findKthNumberMaxHeap(int A[], int n, int k) {
        std::priority_queue<int, std::vector<int>, comparatorMax> maxHeap;

        for (int i=0; i<n; i++)
            maxHeap.push(A[i]);

        while (k > 1) { // pop k-1 times
            maxHeap.pop();
            k--;
        }

        return maxHeap.top();
    }

    /* with min heap
     *
     * Time: O(nlgn)
     * Space: O(k)
     */
    int findKthNumberMinHeap(int A[], int n, int k) {
        cout << "k=" << k << endl;
        
        std::priority_queue<int, std::vector<int>, comparatorMin> minHeap;
        
        int i;
        for (i=0; i<k; i++) {
            minHeap.push(A[i]);
        }

        for (i=k; i<n; i++) {
            if (A[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(A[i]);
            }
        }

        return minHeap.top();
    }
};

int main()
{
    int array[] = { 3, 9, 2, 6, 8, 1, 4, 7, 5};
    //int array[] = { 3, 2, 6, 8, 1, 4, 7, 5};    
    int length = sizeof(array)/sizeof(int);
    
    std::priority_queue<int, std::vector<int>, comparatorMin> minHeap;

    for (int i=0; i<length; i++)
        minHeap.push(array[i]);

    while (!minHeap.empty()) {
        int value = minHeap.top();
        cout << value << " ";
        minHeap.pop();
    }
    cout << endl;


    Solution s;
    int median = s.findMedian(array, length);
    cout << "Median=" << median <<endl;
    
    return 0;
}
