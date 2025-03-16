struct Solution;

use std::collections::HashMap;

impl Solution {
    pub fn word_pattern(pattern: String, s: String) -> bool {
        let mut chars = pattern.chars().collect::<Vec<_>>();
        let mut words = s.split_whitespace().collect::<Vec<_>>();

        if chars.len() != words.len() {
            return false;
        }

        let mut direct_map = HashMap::new();

        for (key, value) in chars.iter().zip(words.iter()) {
            if let Some(old_value) = direct_map.insert(key, value) {
                if old_value != value {
                    return false;
                }
            }
        }

        let mut reverse_map = HashMap::new();

        for (key, value) in words.iter().zip(chars.iter()) {
            if let Some(old_value) = reverse_map.insert(key, value) {
                if old_value != value {
                    return false;
                }
            }
        }

        true
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn word_pattern(pattern: String, s: String) -> bool {
        let mut chars = pattern.chars();

        let mut direct_map = HashMap::new();
        let mut reverse_map = HashMap::new();

        for str in s.split_whitespace() {
            match chars.next() {
                Some(c) => {
                    if let Some(old_str) = direct_map.insert(c, str) {
                        if old_str != str {
                            return false;
                        }
                    }

                    if let Some(old_c) = reverse_map.insert(str, c) {
                        if old_c != c {
                            return false;
                        }
                    }
                }
                None => return false,
            }
        }

        if chars.next().is_some() {
            return false;
        }

        true
    }
}

impl Solution {
    pub fn word_pattern(pattern: String, s: String) -> bool {
        let mut chars = pattern.chars();
        let mut hashmap = vec![""; 26];

        for str in s.split_whitespace() {
            if let Some(c) = chars.next() {
                let index = c as usize - 'a' as usize;
                if hashmap[index].is_empty() {
                    if hashmap.contains(&str) {
                        return false;
                    }
                    hashmap[index] = str;
                } else {
                    if hashmap[index] != str {
                        return false;
                    }
                }
            } else {
                return false;
            }
        }

        if chars.next().is_some() {
            return false;
        }

        true
    }
}
