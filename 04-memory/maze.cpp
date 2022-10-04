#include <iostream>
#include <string>

using namespace std;

enum Material {WALL, SPACE, PLAYER};

struct tile {
    int x;         // x-coordinate of the tile in the playfield
    int y;         // y-coordinate of the tile in the playfield
    bool isWall;   // Is this tile a wall?
    bool isPlayer;
    Material type; // The material of this tile
};

char symbol(Material m) {
    // Switch is a sort of if-then-else, useful when there many cases.
    // Remember to always break each branch!
    switch (m) {
    case SPACE:
        return ' ';
    case WALL:
        return '*';
    case PLAYER:
        return 'O';
    default:
        return '?';
    }
}

void buildPlayground(tile **playground, int rows, int cols, int player_x, int player_y){

        // Building the playground (stone perimeter, wood inside)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Note how we access an element of an array with playground[i][j]
            // and how we access the fields of a struct with .x, .y, etc.
            playground[i][j].x = i;
            playground[i][j].y = j;
            playground[i][j].isWall = (i==0 || i==(rows-1) || j==0 || j==(cols-1));
            playground[0][3].isWall = false;
            playground[i][j].isPlayer = (i == player_x && j == player_y);
            if (playground[i][j].isWall) {
                playground[i][j].type = WALL;
            } else if(playground[i][j].isPlayer){
                playground[i][j].type = PLAYER;
            }else {
                playground[i][j].type = SPACE;
            }

        }
    }
}

void printPlayground(tile **playground, int rows,int cols){
    // Printing the playground
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << symbol(playground[i][j].type);
        }
        cout << endl;
    }
}

void stepFunction(char action, int *player_x, int *player_y, tile **playground){
    if(action=='u'){
        *player_x = *player_x - 1;
        if (playground[*player_x][*player_y].isWall){
            *player_x = *player_x + 1;
        }
    }else if (action == 'd')
    {
        *player_x = *player_x + 1;
        if (playground[*player_x][*player_y].isWall){
            *player_x = *player_x - 1;
        }
    }else if (action == 'l')
    {
        *player_y = *player_y - 1;
        if (playground[*player_x][*player_y].isWall){
            *player_y = *player_y + 1;
        }
    }else if (action == 'r')
    {
        *player_y = *player_y + 1;
        if (playground[*player_x][*player_y].isWall){
            *player_y = *player_y - 1;
        }
    }
}

int main() {
    int rows = 0;
    int cols = 0;

    cin>>rows;
    cin>>cols;

    int player_x = rows/2, player_y = cols/2;

    char action;

    tile **playground = new tile*[rows];
    for (int i = 0; i < rows; i++) {
        playground[i] = new tile[cols];
    }

    while (true)
    {
        buildPlayground(playground, rows, cols, player_x, player_y);
        printPlayground(playground, rows, cols);
        cin>>action;
        stepFunction(action, &player_x, &player_y, playground);
        if (action == 'q'){
            for (int i = 0; i < rows; i++) {
                delete[] playground[i];
            }
            delete[] playground;
            return 0;
        }
    }
    

    return 0;
}