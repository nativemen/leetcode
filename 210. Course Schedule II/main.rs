struct Solution;

impl Solution {
    pub fn find_order(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> Vec<i32> {
        let mut adj = vec![vec![]; num_courses as usize];
        let mut indegree = vec![0; num_courses as usize];

        for prerequisite in prerequisites.into_iter() {
            adj[prerequisite[0] as usize].push(prerequisite[1]);
            indegree[prerequisite[1] as usize] += 1;
        }

        let mut q = Vec::new();

        for i in 0..num_courses {
            if indegree[i as usize] == 0 {
                q.push(i);
            }
        }

        let mut result = Vec::new();

        while !q.is_empty() {
            let course = q.remove(0);
            result.insert(0, course);

            for &neighbor in adj[course as usize].iter() {
                indegree[neighbor as usize] -= 1;
                if indegree[neighbor as usize] == 0 {
                    q.push(neighbor);
                }
            }
        }

        if result.len() != num_courses as usize {
            return vec![];
        }

        result
    }
}

impl Solution {
    pub fn find_order(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> Vec<i32> {
        fn has_cycle(
            adj: &Vec<Vec<i32>>,
            visited: &mut Vec<i32>,
            result: &mut Vec<i32>,
            index: i32,
        ) -> bool {
            if visited[index as usize] == 1 {
                return true;
            }

            if visited[index as usize] == 2 {
                return false;
            }

            visited[index as usize] = 1;

            for &neighbor in adj[index as usize].iter() {
                if has_cycle(adj, visited, result, neighbor) {
                    return true;
                }
            }

            visited[index as usize] = 2;
            result.push(index);

            return false;
        }

        let mut adj = vec![vec![]; num_courses as usize];

        for prerequisite in prerequisites.into_iter() {
            adj[prerequisite[0] as usize].push(prerequisite[1]);
        }

        let mut visited = vec![0; num_courses as usize];
        let mut result = Vec::new();

        for i in 0..num_courses {
            if has_cycle(&adj, &mut visited, &mut result, i) {
                return vec![];
            }
        }

        result
    }
}
