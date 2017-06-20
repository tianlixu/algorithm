//
//  Created by FOS on 2015-06-07.
//  Copyright (c) 2015 FOS. All rights reserved.
//
//  DiceDemo: Find a route for a given sum. To Be Finished...
//  one cell can not be enterned twice for a given route.

#include <iostream>
#include <stack>
#include <string.h>

using namespace std;


enum Direction {
    ROLL_NONE  = 0,    
    ROLL_RIGHT = 1,
    ROLL_LEFT  = -1,
    ROLL_UP    = 2,
    ROLL_DOWN  = -2,
};

enum DirectionAttr {
    TRIED,        // has been tried
    TO_BE_TRIED,  // to be tried
    FROM          // entered from this side
};


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

    int roll(Direction direction) {
        switch (direction) {
        case ROLL_RIGHT:
            rollRight();
            break;
        case ROLL_LEFT:
            rollLeft();
            break;
        case ROLL_UP:
            rollUp();
            break;
        case ROLL_DOWN:
            rollDown();
        default:
            break;
        }
    }

    int undo(Direction direction) {
        switch (direction) {
        case ROLL_RIGHT:
            rollLeft();
            break;
        case ROLL_LEFT:
            rollRight();
            break;
        case ROLL_UP:
            rollDown();
            break;
        case ROLL_DOWN:
            rollUp();
        default:
            break;
        }
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
    
private:
    int top;
    int front;
    int right;
    
    static const int SEVEN = 7;
};


struct Point {
    Point() {
        Point(0, 0);
    }
    
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    
    int x;
    int y;
};

struct Cell {
    Cell() {
        upAttr = TO_BE_TRIED;
        downAttr = TO_BE_TRIED;
        leftAttr = TO_BE_TRIED;
        rightAttr = TO_BE_TRIED;
    }

    int value;
    Point point;
    DirectionAttr upAttr;
    DirectionAttr downAttr;
    DirectionAttr leftAttr;
    DirectionAttr rightAttr;    
};

class Board {
public:
    Board() {
        // init cell as 0s
    }
    
    void setCell(Point &p, int value) {
        cells[p.x][p.y] = value;
    }
    
    int getCell(Point &p) {
        return cell[p.x][p.y];
    }

    bool isCellSet(Point &p) {
        return 0 != getCell(p);
    }
    
    bool canRollRight(Point &p) {
        return ( (!isCellSet(p)) &&
                 (p.x+1 < N && cell[p.x+1][p.y] == 0) );
    }
    
    bool canRollLeft(Point &p) {
        return ( (!isCellSet(p)) &&        
                 (p.x-1 >= 0 && cell[p.x-1][p.y] == 0) );
    }
    
    bool canRollUp(Point &p) {
        return ( (!isCellSet(p)) &&
                 (p.y+1 < N && cell[p.x][p.y+1] == 0) );
    }
    
    bool canRollDown(Point &p) {
        return ( (!isCellSet(p)) &&
                 (p.y-1 >=0 && cell[p.x][p.y-1] ==0) );
    }
    
private:
    static const int N = 20;
    
    Cell cells[N][N];
};


class Game {
public:
    Game() {
        
    }
    ~Game() {
        
    }
    void init() {
        position = Point(0, 0);
        board.setCell(position, dice.getBottom());
    }
    
    void findRoute(int M) {
        sum = M;
        
        // push stack
        route.push(position); // position now is origion(0, 0);
        while (true) {
            Point p = route.top();
            sum -= board.getCell(p);
            
            // !!! find the route
            if (sum == 0)
                break;
            
            if (sum > 0 && canRoll()) {
                roll();
            } else {
                // recover sum, pop stack, dice and cell
                sum += board.getCell(p);
                dice.undo();
                route.pop();
                position = route.top();
                
                if (route.empty())
                    break;
            }
        }
        
        if (route.empty())
            cout << "Failed to find one route!" << endl;
        else
            printRoute();
    }
    
    
    // print and clear the root
    void printRoute() {
        while (!route.empty()) {
            Point p = route.top();
            route.pop();
            
            printRoute();
            
            cout << "(" << p.x <<"," << p.y <<")" << " ";
        }
        cout << endl;
    }
    
    
    // roll one step
    void roll() {
        // roll right
        if (canRollRight()) {
            position = Point(position.x+1, position.y);
            int value = dice.rollRight();
            board.setCell(position, value);
            route.push(position);
            
            return;
        }
        
        // roll left
        if (canRollLeft()) {
            position = Point(position.x-1, position.y);
            int value = dice.rollLeft();
            board.setCell(position, value);
            route.push(position);
            
            return;
        }
        
        // roll up
        if (canRollUp()) {
            position = Point(position.x, position.y+1);
            int value = dice.rollUp();
            board.setCell(position, value);
            route.push(position);
            
            return;
        }
        
        // roll down
        if (canRollDown()) {
            position = Point(position.x, position.y-1);
            int value = dice.rollDown();
            board.setCell(position, value);
            route.push(position);
        }
    }
    
    bool canRoll() {
        return canRollRight() || canRollLeft() || canRollUp() || canRollDown();
    }
    
    bool canRollRight() {
        // right cell is not set and it is till in board
        return board.canRollRight(position);
    }
    
    bool canRollLeft() {
        return board.canRollLeft(position);
    }
    
    bool canRollUp() {
        return board.canRollUp(position);
    }
    
    bool canRollDown() {
        return board.canRollDown(position);
    }
    
private:
    std::stack<Point> route;
    Board board;
    Dice dice;
    Point position; // current position of dice in board
    int sum;
};


int main(int argc, const char * argv[]) {
    Dice dice;
    dice.testRolling();
    
    
    cout << "Dice demo ..." <<endl;
    
    Game game;
    game.init();
    game.findRoute(15);
    
    return 0;
}
