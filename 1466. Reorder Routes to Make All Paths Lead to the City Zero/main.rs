struct Solution;

use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn min_reorder(n: i32, connections: Vec<Vec<i32>>) -> i32 {
        fn dfs(
            maps: &HashMap<i32, Vec<i32>>,
            directions: &HashSet<(i32, i32)>,
            visited: &mut HashSet<i32>,
            current: i32,
            count: &mut i32,
        ) {
            visited.insert(current);

            for neighbor in maps[&current].iter() {
                if !visited.contains(neighbor) {
                    if directions.contains(&(current, *neighbor)) {
                        *count += 1;
                    }

                    dfs(maps, directions, visited, *neighbor, count);
                }
            }
        }

        let mut maps = HashMap::new();
        let mut directions = HashSet::new();

        connections.into_iter().for_each(|connection| {
            let src = connection[0];
            let dest = connection[1];

            maps.entry(src)
                .and_modify(|v: &mut Vec<i32>| v.push(dest))
                .or_insert(vec![dest]);
            maps.entry(dest)
                .and_modify(|v: &mut Vec<i32>| v.push(src))
                .or_insert(vec![src]);
            directions.insert((src, dest));
        });

        let mut count = 0;
        let mut visited = HashSet::new();

        dfs(&maps, &directions, &mut visited, 0, &mut count);

        count
    }
}
