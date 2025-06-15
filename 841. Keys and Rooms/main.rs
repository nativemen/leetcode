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
