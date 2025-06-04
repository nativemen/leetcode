struct Solution;

use std::collections::HashMap;
use std::collections::HashSet;

impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool {
        let mut maps = HashMap::new();

        for num in arr.into_iter() {
            maps.entry(num).and_modify(|count| *count += 1).or_insert(1);
        }

        let mut sets = HashSet::new();

        for val in maps.values() {
            if sets.contains(val) {
                return false;
            }

            sets.insert(*val);
        }

        true
    }
}
