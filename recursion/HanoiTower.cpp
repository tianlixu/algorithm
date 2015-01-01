#include <stdio.h>

void moveFromA2C(int n, char A, char C)
{
    printf("Disk %d: %c->%c\n", n, A, C);
}

/*
 * Move n disks from peg A to peg C with the help of peg B.
 *
 *       -    1
 *      ---   ...
 *     -----  n-1
 *    ------- n
 *    =======      =======  =======
 *       A            B        C
 *    Source        Helper   Target
 */
void hanoi(int n, char A, char B, char C) {
    if(n == 1) {
        moveFromA2C(n, A, C);
    } else {
        // 1. Move n-1 disks from A to B by using C
        hanoi(n-1, A, C, B);
        // 2. Move the n disk from A to C directly
        moveFromA2C(n, A, C);
        // 3. Move n-1 disks from B to C by using A (Switch A and B then do recursion)
        hanoi(n-1, B, A, C);
    }
}

int main() {
    int n;
    printf("Please input the number of Disks:\n");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');

    return 0;
}
