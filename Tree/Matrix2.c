//Problem F:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define STACK_SIZE 100


char board[MAX_ROWS][MAX_COLS];
int visited[MAX_ROWS][MAX_COLS]; 


char blade_stack[STACK_SIZE];
int top = -1; 


int rows, cols;


void push(char blade) {
    if (top < STACK_SIZE - 1) {
        blade_stack[++top] = blade;
        printf("Blade found: %c\n", blade);
    }
}


char pop() {
    if (top >= 0) {
        return blade_stack[top--];
    }
    return '\0'; 
}

int can_kill_vampire(char vampire) {
    if (top == -1) return 0; 

    char required_blade;
    if (vampire == 'M') required_blade = 'A';
    else if (vampire == 'N') required_blade = 'B';
    else if (vampire == 'O') required_blade = 'C';

    if (blade_stack[top] == required_blade) {
        pop(); 
        printf("Enemy %c is killed\n", vampire);
        return 1; 
    } else {
        printf("You are killed by enemy %c\n", vampire);
        return 0; 
    }
}


int dfs(int x, int y) {
    if (x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y] || board[x][y] == 'X' || board[x][y] == '-') {
        return 0;
    }

    visited[x][y] = 1; 

    
    if (board[x][y] == 'E') {
        return 1;
    }

    
    if (board[x][y] == 'A' || board[x][y] == 'B' || board[x][y] == 'C') {
        push(board[x][y]);
    }

    
    if (board[x][y] == 'M' || board[x][y] == 'N' || board[x][y] == 'O') {
        if (!can_kill_vampire(board[x][y])) {
            return 0; 
        }
    }

    if (dfs(x + 1, y) || dfs(x - 1, y) || dfs(x, y + 1) || dfs(x, y - 1)) {
        return 1;
    }

    return 0;
}

void find_start(int* start_x, int* start_y) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'S') {
                *start_x = i;
                *start_y = j;
                return;
            }
        }
    }
}

int main() {

    scanf("%d %d", &rows, &cols);
    getchar();
    for (int i = 0; i < rows; i++) {
        fgets(board[i], MAX_COLS, stdin);
    }

    
    memset(visited, 0, sizeof(visited));

    
    int start_x, start_y;
    find_start(&start_x, &start_y);

    if (!dfs(start_x, start_y)) {
        printf("You cannot reach the end.\n");
    }

    return 0;
}

