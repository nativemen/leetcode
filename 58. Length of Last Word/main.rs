struct Solution;

impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        s.split_whitespace().last().unwrap().len() as i32
    }
}

impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut count = 0;
        let mut next = ' ';

        for c in s.chars().rev() {
            if next != ' ' && c == ' ' {
                break;
            }

            if c != ' ' {
                count += 1;
            }

            next = c;
        }

        count
    }
}
