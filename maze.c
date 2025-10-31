#include <stdio.h>

#define MAX 30
int maze[MAX][MAX];       // Maze matrix (1 = open, 0 = wall)
int visited[MAX][MAX];    // Tracks visited cells
int n;                    // Maze size (30x30)

// Function to check if cell is safe to move
int isSafe(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n &&
            maze[x][y] == 1 && visited[x][y] == 0);
}

// Recursive function to solve maze (Backtracking)
int solve(int x, int y) {
    // Base condition: reached the destination
    if (x == n - 1 && y == n - 1 && maze[x][y] == 1) {
        visited[x][y] = 1;
        return 1;
    }

    if (isSafe(x, y)) {
        visited[x][y] = 1;  // mark current cell as visited

        // move in all 4 directions
        if (solve(x + 1, y)) return 1;  // Down
        if (solve(x, y + 1)) return 1;  // Right
        if (solve(x - 1, y)) return 1;  // Up
        if (solve(x, y - 1)) return 1;  // Left

        visited[x][y] = 0;  // Backtrack
    }

    return 0;
}

int main() {
    FILE *fptr = fopen("input.txt", "r");

    if (fptr == NULL) {
        printf("Error: input.txt not found!\n");
        return 1;
    }

    fscanf(fptr, "%d", &n);  // read maze size
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fptr, "%d", &maze[i][j]);

    fclose(fptr);

    if (solve(0, 0))
        printf("Path Found!\n");
    else
        printf("No Path Found!\n");

    printf("\nVisited Cells (1 = visited):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", visited[i][j]);
        printf("\n");
    }

    return 0;
}
