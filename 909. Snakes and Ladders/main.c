#include <limits.h>
#include <stdio.h>

#define ROLL_SIZE 6
#define QUEUE_SIZE 800

static void convert(int rowSize, int colSize, int value, int *x, int *y) {
    int r = (value - 1) / colSize;
    *x = rowSize - 1 - r;
    *y = (value - 1) % colSize;
    if (r % 2 == 1) {
        *y = colSize - 1 - *y;
    }
}

int snakesAndLadders(int **board, int boardSize, int *boardColSize) {
    int q[QUEUE_SIZE][3];
    q[0][0] = boardSize - 1;
    q[0][1] = 0;
    q[0][2] = 1;
    int head = 0;
    int tail = 1;

    int count = 0;
    int size = boardSize * boardColSize[0];
    int visited[size + 1];
    memset(visited, 0, (size + 1) * sizeof(int));
    visited[1] = 1;

    while (head != tail) {
        int next = tail;
        for (int i = head; i < next; i++) {
            int i = q[head][0];
            int j = q[head][1];
            int val = q[head][2];

            head = (head + 1) % QUEUE_SIZE;

            if (val == size) {
                return count;
            }

            for (int k = 1; k <= ROLL_SIZE; k++) {
                if (val + k > size) {
                    continue;
                }

                int x = 0;
                int y = 0;
                int value = val + k;
                convert(boardSize, boardColSize[0], value, &x, &y);

                if (board[x][y] != -1) {
                    value = board[x][y];
                    convert(boardSize, boardColSize[0], value, &x, &y);
                }

                if (visited[value] == 1) {
                    continue;
                }

                visited[value] = 1;

                q[tail][0] = x;
                q[tail][1] = y;
                q[tail][2] = value;
                tail = (tail + 1) % QUEUE_SIZE;
            }
        }
        count++;
    }

    return -1;
}

#define ROLL_SIZE 6
#define QUEUE_SIZE 400

static void convert(int rowSize, int colSize, int value, int *x, int *y) {
    int r = (value - 1) / colSize;
    *x = rowSize - 1 - r;
    *y = (value - 1) % colSize;
    if (r % 2 == 1) {
        *y = colSize - 1 - *y;
    }
}

int snakesAndLadders(int **board, int boardSize, int *boardColSize) {
    int q[QUEUE_SIZE][2] = {{0}};
    q[0][0] = 1;
    q[0][1] = 0;
    int head = 0;
    int tail = 1;
    int size = boardSize * boardColSize[0];
    int visited[QUEUE_SIZE + 1] = {0};
    visited[1] = 1;

    while (head < tail) {
        int value = q[head][0];
        int moves = q[head][1];
        head++;

        for (int i = 1; i <= ROLL_SIZE; i++) {
            int next = value + i;
            if (next > size) {
                continue;
            }

            int x = 0;
            int y = 0;
            convert(boardSize, boardColSize[0], next, &x, &y);

            if (board[x][y] != -1) {
                next = board[x][y];
            }

            if (next == size) {
                return moves + 1;
            }

            if (visited[next] == 0) {
                visited[next] = 1;

                q[tail][0] = next;
                q[tail][1] = moves + 1;
                tail++;
            }
        }
    }

    return -1;
}