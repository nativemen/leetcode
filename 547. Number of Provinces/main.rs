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
        fn find(parent: &mut Vec<usize>, x: usize) -> usize {
            if parent[x] != x {
                parent[x] = find(parent, parent[x]);
            }

            parent[x]
        }

        fn union_set(parent: &mut Vec<usize>, x: usize, y: usize) {
            let root_x = find(parent, x);
            let root_y = find(parent, y);

            if root_x != root_y {
                parent[root_x] = root_y;
            }
        }

        let mut parent = vec![0; is_connected.len()];

        parent.iter_mut().enumerate().for_each(|(i, val)| {
            *val = i;
        });

        for i in 0..is_connected.len() {
            for j in 0..is_connected[i].len() {
                if is_connected[i][j] == 1 {
                    union_set(&mut parent, i, j);
                }
            }
        }

        parent
            .iter()
            .enumerate()
            .filter(|&(i, &val)| val == i)
            .count() as i32
    }
}
