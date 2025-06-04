struct Solution;

use std::collections::HashMap;
use std::collections::HashSet;

impl Solution {
    pub fn close_strings(word1: String, word2: String) -> bool {
        let set1: HashSet<char> = HashSet::from_iter(word1.chars());
        let set2: HashSet<char> = HashSet::from_iter(word2.chars());

        if !set1.eq(&set2) {
            return false;
        }

        let mut maps1 = HashMap::new();
        let mut maps2 = HashMap::new();

        for c in word1.chars() {
            maps1.entry(c).and_modify(|count| *count += 1).or_insert(1);
        }

        for c in word2.chars() {
            maps2.entry(c).and_modify(|count| *count += 1).or_insert(1);
        }

        let mut v1 = maps1.values().cloned().collect::<Vec<_>>();
        let mut v2 = maps2.values().cloned().collect::<Vec<_>>();

        v1.sort();
        v2.sort();

        v1.eq(&v2)
    }
}

impl Solution {
    pub fn close_strings(word1: String, word2: String) -> bool {
        const FREQ_SIZE: usize = 26;
        let mut freq1 = vec![0; FREQ_SIZE];
        let mut freq2 = vec![0; FREQ_SIZE];

        for c in word1.bytes() {
            freq1[(c - b'a') as usize] += 1;
        }

        for c in word2.bytes() {
            freq2[(c - b'a') as usize] += 1;
        }

        for i in 0..FREQ_SIZE {
            if freq1[i] != freq2[i] && (freq1[i] == 0 || freq2[i] == 0) {
                return false;
            }
        }

        freq1.sort();
        freq2.sort();

        freq1 == freq2
    }
}
