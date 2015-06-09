/*
  Author : Alex Xu
  Date   : Jun 09, 2015
  Problem: Find the median of an unsorted array
 */

#include <iostream>
#include <queue>

using namespace std;


struct comparator {
    bool operator() (int a, int b) {
        return a > b; // min heap, top is the smallest
        // return a < b; // max heap, top is the largest
    }
};


class Solution {
public:
    int findMedian(int A[], int m) {
        int mid = m/2 + m%2;
        return findKthNumber(A, m, mid);
    }

    int findKthNumber(int A[], int m, int k) {
        std::priority_queue<int, std::vector<int>, comparator> minHeap;

        for (int i=0; i<m; i++)
            minHeap.push(A[i]);

        while (k > 1) { // pop k-1 times
            minHeap.pop();
            k--;
        }

        return minHeap.top();
    }

};

int main()
{
    //int array[] = { 3, 9, 2, 6, 8, 1, 4, 7, 5};
    int array[] = { 3, 2, 6, 8, 1, 4, 7, 5};    
    int length = sizeof(array)/sizeof(int);
    
    std::priority_queue<int, std::vector<int>, comparator> minHeap;

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
