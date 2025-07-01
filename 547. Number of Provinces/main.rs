struct Solution;

impl Solution {
    pub fn find_circle_num(is_connected: Vec<Vec<i32>>) -> i32 {
        fn dfs(is_connected: &Vec<Vec<i32>>, visited: &mut Vec<i32>, current: usize) {
            visited[current] = 1;

            for j in 0..is_connected[current].len() {
                if is_connected[current][j] == 1 && visited[j] == 0 {
                    dfs(is_connected, visited, j);
                }
            }
        }

        let mut visited = vec![0; is_connected.len()];
        let mut count = 0;

        for i in 0..is_connected.len() {
            if visited[i] == 0 {
                dfs(&is_connected, &mut visited, i);
                count += 1;
            }
        }

        count
    }
}


impl Solution {
    pub fn find_circle_num(is_connected: Vec<Vec<i32>>) -> i32 {

    }
}
