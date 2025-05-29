struct Solution;

impl Solution {
    pub fn partition_string(s: String) -> i32 {
        let mut count = vec![0; 26];
        let mut num = 1;

        for c in s.chars() {
            let index = c as usize - 'a' as usize;

            if count[index] == 1 {
                count = vec![0; 26];
                num += 1;
            }

            count[index] = 1;
        }

        num
    }
}

impl Solution {
    pub fn partition_string(s: String) -> i32 {
        let mut mask = 0;
        let mut num = 1;

        for c in s.chars() {
            let bit = 1 << (c as usize - 'a' as usize);

            if (mask & bit) != 0 {
                mask = 0;
                num += 1;
            }

            mask |= bit;
        }

        num
    }
}

use std::collections::HashSet;

impl Solution {
    pub fn partition_string(s: String) -> i32 {
        let mut sets = HashSet::new();
        let mut num = 1;

        for c in s.chars() {
            if sets.contains(&c) {
                sets.clear();
                num += 1;
            }

            sets.insert(c);
        }

        num
    }
}
