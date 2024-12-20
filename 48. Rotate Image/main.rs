impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        matrix.reverse();

        for row in 0..matrix.len() {
            for col in row..matrix[row].len() {
                let temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }
    }
}

impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        for row in 0..matrix.len() {
            for col in row..matrix[row].len() {
                let temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }

        for row in 0..matrix.len() {
            let len = matrix[row].len();
            for col in 0..((len + 1) / 2) {
                let temp = matrix[row][col];
                matrix[row][col] = matrix[row][len - 1 - col];
                matrix[row][len - 1 - col] = temp;
            }
        }
    }
}
