struct Solution;

impl Solution {
    pub fn merge_alternately(word1: String, word2: String) -> String {
        let word1 = word1.as_bytes();
        let word2 = word2.as_bytes();
        let len1 = word1.len();
        let len2 = word2.len();
        let mut word = String::new();
        let mut index = 0;

        while index < len1 || index < len2 {
            if index < len1 {
                word.push(word1[index] as char);
            }

            if index < len2 {
                word.push(word2[index] as char);
            }

            index += 1;
        }

        word
    }
}

impl Solution {
    pub fn merge_alternately(word1: String, word2: String) -> String {
        let mut chars1 = word1.chars();
        let mut chars2 = word2.chars();
        let mut word = String::new();

        loop {
            match (chars1.next(), chars2.next()) {
                (Some(c1), Some(c2)) => {
                    word.push(c1);
                    word.push(c2);
                }
                (Some(c1), None) => word.push(c1),
                (None, Some(c2)) => word.push(c2),
                (None, None) => break,
            }
        }

        word
    }
}
