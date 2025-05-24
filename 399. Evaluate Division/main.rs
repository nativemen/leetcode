struct Solution;

use std::collections::HashMap;
use std::collections::HashSet;

impl Solution {
    pub fn calc_equation(
        equations: Vec<Vec<String>>,
        values: Vec<f64>,
        queries: Vec<Vec<String>>,
    ) -> Vec<f64> {
        let mut maps: HashMap<String, Vec<(String, f64)>> = HashMap::new();

        for i in 0..equations.len() {
            maps.entry(equations[i][0].clone())
                .and_modify(|v| v.push((equations[i][1].clone(), values[i])))
                .or_insert(vec![(equations[i][1].clone(), values[i])]);
            maps.entry(equations[i][1].clone())
                .and_modify(|v| v.push((equations[i][0].clone(), 1.0 / values[i])))
                .or_insert(vec![(equations[i][0].clone(), 1.0 / values[i])]);
        }

        let mut result = Vec::new();

        for query in queries.into_iter() {
            if !maps.contains_key(&query[0]) || !maps.contains_key(&query[1]) {
                result.push(-1.0);
                continue;
            }

            let mut visited = HashSet::new();
            let mut answer = -1.0;

            Self::dfs(
                &mut maps,
                &mut visited,
                &query[0],
                &query[1],
                1.0,
                &mut answer,
            );

            result.push(answer);
        }

        result
    }

    fn dfs(
        maps: &mut HashMap<String, Vec<(String, f64)>>,
        visited: &mut HashSet<String>,
        src: &str,
        dest: &str,
        value: f64,
        answer: &mut f64,
    ) {
        visited.insert(src.to_string());

        if src.eq(dest) {
            *answer = value;
            return;
        }

        for (s, val) in maps[src].clone().iter() {
            if !visited.contains(s) {
                Self::dfs(maps, visited, s, dest, value * val, answer);
            }
        }

        visited.remove(src);
    }
}
