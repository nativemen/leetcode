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

use std::collections::HashMap;

impl Solution {
    pub fn calc_equation(
        equations: Vec<Vec<String>>,
        values: Vec<f64>,
        queries: Vec<Vec<String>>,
    ) -> Vec<f64> {
        let mut parent: HashMap<String, (String, f64)> = HashMap::new();

        fn find(parent: &mut HashMap<String, (String, f64)>, x: &str) -> (String, f64) {
            let entry = parent
                .entry(x.to_string())
                .or_insert_with(|| (x.to_string(), 1.0));
            let (y, val_y) = (entry.0.clone(), entry.1);

            if y != x {
                let (z, val_z) = find(parent, &y);
                parent.insert(x.to_string(), (z.clone(), val_y * val_z));
                return (z, val_y * val_z);
            }

            (y, val_y)
        }

        fn union(parent: &mut HashMap<String, (String, f64)>, u: &str, v: &str, value: f64) {
            let (root_u, val_u) = find(parent, u);
            let (root_v, val_v) = find(parent, v);

            if root_u != root_v {
                parent.insert(root_u, (root_v, value * val_v / val_u));
            }
        }

        for (i, equation) in equations.iter().enumerate() {
            let u = &equation[0];
            let v = &equation[1];
            union(&mut parent, u, v, values[i]);
        }

        let mut result = Vec::with_capacity(queries.len());

        for query in queries {
            let u = &query[0];
            let v = &query[1];

            if !parent.contains_key(u) || !parent.contains_key(v) {
                result.push(-1.0);
                continue;
            }

            let (root_u, val_u) = find(&mut parent, u);
            let (root_v, val_v) = find(&mut parent, v);

            if root_u != root_v {
                result.push(-1.0);
            } else {
                result.push(val_u / val_v);
            }
        }

        result
    }
}
