//
//  DiceDemo: Find a route for a given sum. To Be Finished...
//
//  Created by FOS on 2015-06-07.
//  Copyright (c) 2015 FOS. All rights reserved.
//

#include <iostream>



#include <iostream>
#include <stack>
using namespace std;

enum Direction {
    ROLL_RIGHT,
    ROLL_LEFT,
    ROLL_UP,
    ROLL_DOWN,
    ROLL_NONE
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
        
        this->direction = ROLL_NONE;
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
        direction = ROLL_RIGHT;
        
        return bottom;
    }
    
    int rollLeft() {
        int bottom = SEVEN - right;
        right = SEVEN - top;
        top = SEVEN - bottom;
        direction = ROLL_LEFT;
        
        return bottom;
    }
    
    int rollUp() {
        int bottom = SEVEN - front; // back -> bottom
        front = SEVEN - top; // bottom -> front
        top = SEVEN - bottom;
        direction = ROLL_UP;
        
        return bottom;
    }
    
    int rollDown() {
        int bottom = front; // front -> bottom
        front = top;
        top = SEVEN - bottom;
        direction = ROLL_DOWN;
        
        return bottom;
    }
    
    // undo last rolling
    void rollBack() {
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
                break;
            default:
                break;
        }
        
        direction = ROLL_NONE;
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
    
    Direction direction;
    static const int SEVEN = 7;
};


struct Point{
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

class Board {
public:
    Board() {
        // init cell as 0s
        memset(cell, 0, sizeof(cell));
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
        return (p.x+1 < N && cell[p.x+1][p.y] == 0);
    }
    
    bool canRollLeft(Point &p) {
        return (p.x-1 >= 0 && cell[p.x-1][p.y] == 0);
    }
    
    bool canRollUp(Point &p) {
        return (p.y+1 < N && cell[p.x][p.y+1] == 0);
    }
    
    bool canRollDown(Point &p) {
        return (p.y-1 >=0 && cell[p.x][p.y-1] ==0);
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
                // recover sum, pop stack
                sum += board.getCell(p);
                dice.rollBack();
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
