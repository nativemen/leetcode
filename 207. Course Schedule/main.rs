struct Solution;

impl Solution {
    pub fn can_finish(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> bool {
        if num_courses == 1 || prerequisites.len() <= 1 {
            return true;
        }

        let mut adj = vec![vec![]; num_courses as usize];

        for prerequisite in prerequisites {
            adj[prerequisite[0] as usize].push(prerequisite[1] as usize);
        }

        let mut visited = vec![0; num_courses as usize];

        for i in 0..num_courses as usize {
            if Self::has_cycle(&adj, &mut visited, i) {
                return false;
            }
        }

        true
    }

    fn has_cycle(adj: &Vec<Vec<usize>>, visited: &mut Vec<usize>, index: usize) -> bool {
        if visited[index] == 1 {
            return true;
        }

        if visited[index] == 2 {
            return false;
        }

        visited[index] = 1;

        for neighbor in adj[index].iter() {
            if Self::has_cycle(adj, visited, *neighbor) {
                return true;
            }
        }

        visited[index] = 2;

        return false;
    }
}
