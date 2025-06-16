struct Solution;

impl Solution {
    pub fn can_visit_all_rooms(rooms: Vec<Vec<i32>>) -> bool {
        fn dfs(rooms: &Vec<Vec<i32>>, index: i32, visited: &mut Vec<bool>) {
            if index < 0 || index >= rooms.len() as i32 || visited[index as usize] {
                return;
            }

            visited[index as usize] = true;

            for &room in rooms[index as usize].iter() {
                dfs(rooms, room, visited);
            }
        }

        let mut visited = vec![false; rooms.len()];

        dfs(&rooms, 0, &mut visited);

        visited.iter().all(|&s| s == true)
    }
}

use std::collections::HashSet;

impl Solution {
    pub fn can_visit_all_rooms(rooms: Vec<Vec<i32>>) -> bool {
        fn dfs(rooms: &Vec<Vec<i32>>, current: usize, visited: &mut HashSet<usize>) {
            if visited.contains(&current) {
                return;
            }

            visited.insert(current);

            for &room in &rooms[current] {
                dfs(rooms, room as usize, visited);
            }
        }

        let mut visited = HashSet::new();

        dfs(&rooms, 0, &mut visited);

        visited.len() == rooms.len()
    }
}

use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn can_visit_all_rooms(rooms: Vec<Vec<i32>>) -> bool {
        let mut q = VecDeque::new();
        let mut visited = HashSet::new();

        q.push_back(0);

        while !q.is_empty() {
            if let Some(current) = q.pop_front() {
                visited.insert(current);

                for &room in &rooms[current as usize] {
                    if !visited.contains(&room) {
                        q.push_back(room);
                    }
                }
            }
        }

        visited.len() == rooms.len()
    }
}
