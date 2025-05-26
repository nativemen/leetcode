struct Solution;

impl Solution {
    pub fn snakes_and_ladders(board: Vec<Vec<i32>>) -> i32 {
        fn convert(row_size: usize, col_size: usize, value: usize) -> (usize, usize) {
            let r = (value - 1) as usize / col_size;
            let c = (value - 1) as usize % col_size;
            let x = row_size - 1 - r;
            let y = if r % 2 == 0 { c } else { col_size - 1 - c };

            (x, y)
        }

        let mut q = vec![(1, 0)];
        let row_size = board.len();
        let col_size = board[0].len();
        let size = row_size * col_size;
        let mut visited = vec![false; size + 1];
        visited[1] = true;

        while !q.is_empty() {
            let node = q.remove(0);
            let value = node.0;
            let moves = node.1;

            for i in 1..=6 {
                let mut next = value + i;

                if next > size {
                    continue;
                }

                let (x, y) = convert(row_size, col_size, next);

                if board[x][y] != -1 {
                    next = board[x][y] as usize;
                }

                if next == size {
                    return moves + 1;
                }

                if !visited[next] {
                    visited[next] = true;
                    q.push((next, moves + 1));
                }
            }
        }

        -1
    }
}
