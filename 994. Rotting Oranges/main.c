#include <stdbool.h>
#include <stdio.h>

#define QUEUE_SIZE 100

int orangesRotting(int **grid, int gridSize, int *gridColSize) {
    int q[QUEUE_SIZE][2] = {{0}};
    int front = 0;
    int rear = 0;
    int fresh = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 2) {
                q[rear][0] = i;
                q[rear][1] = j;
                rear++;
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) {
        return 0;
    }

    int minutes = -1;

    while (front < rear) {
        int next = rear;

        for (int i = front; i < next; i++) {
            int x = q[i][0];
            int y = q[i][1];

            if (x > 0 && grid[x - 1][y] == 1) {
                grid[x - 1][y] = 2;
                q[rear][0] = x - 1;
                q[rear][1] = y;
                rear++;
                fresh--;
            }

            if (x < gridSize - 1 && grid[x + 1][y] == 1) {
                grid[x + 1][y] = 2;
                q[rear][0] = x + 1;
                q[rear][1] = y;
                rear++;
                fresh--;
            }

            if (y > 0 && grid[x][y - 1] == 1) {
                grid[x][y - 1] = 2;
                q[rear][0] = x;
                q[rear][1] = y - 1;
                rear++;
                fresh--;
            }

            if (y < gridColSize[x] - 1 && grid[x][y + 1] == 1) {
                grid[x][y + 1] = 2;
                q[rear][0] = x;
                q[rear][1] = y + 1;
                rear++;
                fresh--;
            }
        }

        minutes++;
        front = next;
    }

    if (fresh > 0) {
        return -1;
    }

    return minutes;
}