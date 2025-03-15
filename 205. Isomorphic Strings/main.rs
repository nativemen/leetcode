struct Solution;

use std::collections::HashMap;

impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut direct_mapping = HashMap::new();
        let mut reverse_mapping = HashMap::new();

        for (c1, c2) in s.chars().zip(t.chars()) {
            if !direct_mapping.contains_key(&c1) && !reverse_mapping.contains_key(&c2) {
                direct_mapping.insert(c1, c2);
                reverse_mapping.insert(c2, c1);
            }

            if direct_mapping.get(&c1) != Some(&c2) || reverse_mapping.get(&c2) != Some(&c1) {
                return false;
            }
        }

        true
    }
}
