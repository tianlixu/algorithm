
#include <iostream>
#include <stack>
using namespace std;

/*
 * Roll the dice and get the value (of bottom)
 */
class Dice {
public:
    Dice(int top = 1, int front = 2, int right = 3) {
        this->top = top;
        this->front = front;
        this->right = right;
    }
    ~Dice() {
        
    }

    int getBottom() {
        return SEVEN - top;
    }

    int rollRight() {
        int bottom = right;
        right = top;
        top = SEVEN - bottom;

        return bottom;
    }

    int rollLeft() {
        int bottom = SEVEN - right;
        right = SEVEN - top;        
        top = SEVEN - bottom;

        return bottom;
    }

    int rollUp() {
        int bottom = SEVEN - front; // back -> bottom
        front = SEVEN - top; // bottom -> front
        top = SEVEN - bottom;

        return bottom;
    }

    int rollDown() {
        int bottom = front; // front -> bottom
        front = top;
        top = SEVEN - bottom;

        return bottom;
    }

    void testRolling() {
        cout << "Test rolling..." <<endl;
        cout << "Rolling right: ";
        for (int i=0; i<12; i++) {
            cout << rollRight() <<" ";
        }
        cout <<endl;

        cout << "Rolling left: ";
        for (int i=0; i<12; i++) {
            cout << rollLeft() <<" ";
        }
        cout <<endl;


        cout << "Rolling up: ";
        for (int i=0; i<12; i++) {
            cout << rollUp() <<" ";
        }
        cout <<endl;

        cout << "Rolling down: ";
        for (int i=0; i<12; i++) {
            cout << rollDown() <<" ";
        }
        cout <<endl;        
    }
    
private:
    int top;
    int front;
    int right;

    static const int SEVEN = 7;
};


struct Point{
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int x;
    int y;
};

class Board {
public:
    Board() {
        // init cell as 0s
        memset(cell, 0, sizeof(cell);
    }

    void setCell(Point &p, int value) {
        cell[p.x][p.y] = value;
    }

    int getCell(Point &p) {
        return cell[p.x][p.y];
    }

    bool canRollRight(Point &p) {
        // for a given cell need to set 4 bool values to in
        // cell.fromRight is ture
        // cell.fromLeft
        // cell.fromUp
        // cell.fromDown
        return (p.x+1 < N && cell[p.x][p.y] != 0);
    }
    
private:
    static const int N = 20;
    
    int cell[N][N];
};


class Game {
public:
    Game() {

    }
    ~Game() {
        
    }
    void init() {
        Point origion(0, 0);
        board.setCell(origion, dice.getBottom());
    }
    
    void findRoute(int sum) {
        Point origion(0, 0);
    }

    bool canRoll() {

    }

    bool canRollRight() {
        return board.canRollRight(position);
    }

private:
    std::stack<Point> route;
    Board board;
    Dice dice;
    Point position; // current position of dice in board
};

int main()
{
    Dice dice;
    dice.testRolling();
    
    cout << "Dice demo ..." <<endl;
    return 0;
}

