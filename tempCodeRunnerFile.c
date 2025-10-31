#include <stdio.h>

#define MAX 10
int maze[MAX][MAX], visited[MAX][MAX], n;
int found = 0;

int solve(int x, int y) {
    if (x == n - 1 && y == n - 1 && maze[x][y] == 0) {
        visited[x][y] = 1;
        found = 1;
        return 1;
    }

    if (x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 1 || visited[x][y] == 1)
        return 0;

    visited[x][y] = 1;

    if (solve(x + 1, y)) return 1;  // down
    if (solve(x, y + 1)) return 1;  // right
    if (solve(x - 1, y)) return 1;  // up
    if (solve(x, y - 1)) return 1;  // left

    visited[x][y] = 0;
    return 0;
}

int main() {
    FILE *fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        printf("Error: input.txt not found!\n");
        return 1;
    }

    fscanf(fptr, "%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fptr, "%d", &maze[i][j]);
    fclose(fptr);

    if (solve(0, 0))
        printf("Path Found!\n");
    else
        printf("No Path Found.\n");

    printf("Visited Cells (1 = visited):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", visited[i][j]);
        printf("\n");
    }

    return 0;
}
