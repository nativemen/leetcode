struct Solution;

use std::collections::HashMap;

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let mut result = Vec::new();

        if digits.is_empty() {
            return result;
        }

        let mut array = String::new();
        Self::backtrack(digits.as_bytes(), 0, &mut array, &mut result);

        result
    }

    fn backtrack(digits: &[u8], index: usize, array: &mut String, result: &mut Vec<String>) {
        if index == digits.len() {
            result.push(array.to_string());
            return;
        }

        let maps: HashMap<char, &str> = vec![
            ('2', "abc"),
            ('3', "def"),
            ('4', "ghi"),
            ('5', "jkl"),
            ('6', "mno"),
            ('7', "pqrs"),
            ('8', "tuv"),
            ('9', "wxyz"),
        ]
        .into_iter()
        .collect();

        for c in maps[&(digits[index] as char)].bytes() {
            array.push(c as char);
            Self::backtrack(digits, index + 1, array, result);
            array.pop();
        }
    }
}
