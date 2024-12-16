impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut count = [0; 26];
        magazine
            .chars()
            .for_each(|c| count[c as usize - 'a' as usize] += 1);
        !ransom_note.chars().any(|c| {
            count[c as usize - 'a' as usize] -= 1;
            count[c as usize - 'a' as usize] < 0
        })
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut hashmap = HashMap::new();
        magazine.chars().for_each(|c| {
            hashmap.entry(c).and_modify(|val| *val += 1).or_insert(1);
        });
        for c in ransom_note.chars() {
            match hashmap.get_mut(&c) {
                Some(n) if *n > 0 => *n -= 1,
                _ => return false,
            }
        }

        true
    }
}
