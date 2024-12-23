use std::cmp::Ordering;

struct Solution;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut s1 = s.chars().collect::<Vec<char>>();
        let mut s2 = t.chars().collect::<Vec<char>>();
        s1.sort();
        s2.sort();
        if s1.cmp(&s2) != Ordering::Equal {
            return false;
        }

        return true;
    }
}

use std::cmp::Ordering;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut s1 = s.chars().collect::<Vec<char>>();
        let mut s2 = t.chars().collect::<Vec<char>>();

        s1.sort();
        s2.sort();

        s1 == s2
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut map: HashMap<char, i32> = HashMap::new();
        for c in s.chars() {
            *map.entry(c).or_insert(0) += 1;
        }
        for c in t.chars() {
            *map.entry(c).or_insert(0) -= 1;
        }

        for &count in map.values() {
            if count != 0 {
                return false;
            }
        }

        true
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut map: HashMap<char, i32> = HashMap::new();
        for c in s.chars() {
            *map.entry(c).or_insert(0) += 1;
        }
        for c in t.chars() {
            *map.entry(c).or_insert(0) -= 1;
        }

        map.iter().all(|(&c, &count)| count == 0)
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut map: HashMap<char, i32> = HashMap::new();
        for c in s.chars() {
            *map.entry(c).or_insert(0) += 1;
        }
        for c in t.chars() {
            if map.get(&c) == None || map[&c] == 0 {
                return false;
            }
            *map.entry(c).or_insert(0) -= 1;
        }

        true
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut map1: HashMap<char, i32> = HashMap::new();
        let mut map2: HashMap<char, i32> = HashMap::new();
        for c in s.chars() {
            *map.entry(c).or_insert(0) += 1;
        }
        for c in t.chars() {
            if map.get(&c) == None || map[&c] == 0 {
                return false;
            }
            *map.entry(c).or_insert(0) -= 1;
        }

        true
    }

    pub fn counter(str: String) -> HashMap<char, i32> {
        let mut map: HashMap<char, i32> = HashMap::new();
        str.chars()
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        Solution::counter(s).eq(&Solution::counter(t))
    }

    pub fn counter(str: String) -> HashMap<char, i32> {
        let mut map: HashMap<char, i32> = HashMap::new();
        str.chars().for_each(|c| {
            *map.entry(c).or_insert(0) += 1;
        });

        map
    }
}
