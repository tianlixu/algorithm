#include <stdio.h>
#include <iostream>

using namespace std;

/*Ver1: print with a loop*/
void print2nVersion1(int n)
{
    int i;
    for (i=1; i<=n; ++i) {
        printf("%d ", i);
    }
}

void printN(int n)
{
    printf("%d ", n);
}

/*Ver2: print with recursion*/
void print2nVersion2(int n)
{
    // print n...3,2,1
    //printN(n);
    if (n > 1) {
        print2nVersion2(n-1);
    }

    // print 1,2,3...n
    printN(n);
}

/*Ver3: print with reference counting*/
class Counter {
public:
    Counter(){
        cout << count++ << " " ;
    }
private:		
    static int count;
};
int Counter::count = 1;

int main()
{
    print2nVersion2(5);
    cout <<endl;
    
    print2nVersion2(10);
    cout <<endl;
    
    //Version3
    Counter c[15];
    cout <<endl;
  
    return 0;
}

