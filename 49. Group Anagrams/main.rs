struct Solution;

use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut maps = HashMap::new();

        for str in strs {
            let mut word = str.chars().collect::<Vec<_>>();
            word.sort();
            let key = word.iter().collect::<String>();
            maps.entry(key).or_insert(Vec::new()).push(str.clone());
        }

        maps.into_values().collect()
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut maps = HashMap::new();

        for str in strs {
            let mut counter = vec![0; 26];
            for c in str.as_bytes() {
                counter[(c - b'a') as usize] += 1;
            }

            maps.entry(counter).or_insert(Vec::new()).push(str.clone());
        }

        maps.into_values().collect()
    }
}
