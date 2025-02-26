struct Solution;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut result = 0;
        let mut prev = '\0';

        for c in s.chars() {
            match c {
                'I' => result += 1,
                'V' => result += if prev == 'I' { 4 - 1 } else { 5 },
                'X' => result += if prev == 'I' { 9 - 1 } else { 10 },
                'L' => result += if prev == 'X' { 40 - 10 } else { 50 },
                'C' => result += if prev == 'X' { 90 - 10 } else { 100 },
                'D' => result += if prev == 'C' { 400 - 100 } else { 500 },
                'M' => result += if prev == 'C' { 900 - 100 } else { 1000 },
                _ => {}
            }
            prev = c;
        }

        result
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let map: HashMap<char, i32> = HashMap::from([
            ('I', 1),
            ('V', 5),
            ('X', 10),
            ('L', 50),
            ('C', 100),
            ('D', 500),
            ('M', 1000),
        ]);
        let mut result = 0;
        let mut cur = 0;
        let mut prev = 0;

        for c in s.chars().rev() {
            cur = map[&c];
            if cur >= prev {
                result += cur;
            } else {
                result -= cur;
            }
            prev = cur;
        }

        result
    }
}

impl Solution {
    fn roman_to_value(c: char) -> i32 {
        match c {
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            'M' => 1000,
            _ => 0,
        }
    }

    pub fn roman_to_int(s: String) -> i32 {
        let mut result = 0;
        let mut cur = 0;
        let mut prev = 0;

        for c in s.chars().rev() {
            cur = Self::roman_to_value(c);
            if cur >= prev {
                result += cur;
            } else {
                result -= cur;
            }
            prev = cur;
        }

        result
    }
}
