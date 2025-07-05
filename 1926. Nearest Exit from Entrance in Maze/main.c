#include <stdbool.h>
#include <stdio.h>

#define QUEUE_SIZE 10000

int nearestExit(char **maze, int mazeSize, int *mazeColSize, int *entrance, int entranceSize) {
    int q[QUEUE_SIZE][3] = {{0}};
    q[0][0] = entrance[0];
    q[0][1] = entrance[1];
    maze[entrance[0]][entrance[1]] = '*';

    int front = 0;
    int rear = 1;
    int count = 0;

    while (front < rear) {
        int next = rear;

        for (int i = front; i < next; i++) {
            int x = q[i][0];
            int y = q[i][1];

            if (count > 0 && (x == 0 || x == mazeSize - 1 || y == 0 || y == mazeColSize[x] - 1)) {
                return count;
            }

            if (x > 0 && maze[x - 1][y] == '.') {
                q[rear][0] = x - 1;
                q[rear][1] = y;
                rear++;
                maze[x - 1][y] = '*';
            }

            if (x < mazeSize - 1 && maze[x + 1][y] == '.') {
                q[rear][0] = x + 1;
                q[rear][1] = y;
                rear++;
                maze[x + 1][y] = '*';
            }

            if (y > 0 && maze[x][y - 1] == '.') {
                q[rear][0] = x;
                q[rear][1] = y - 1;
                rear++;
                maze[x][y - 1] = '*';
            }

            if (y < mazeColSize[x] - 1 && maze[x][y + 1] == '.') {
                q[rear][0] = x;
                q[rear][1] = y + 1;
                rear++;
                maze[x][y + 1] = '*';
            }
        }

        count++;
        front = next;
    }

    return -1;
}