struct Solution;

impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let clean = s
            .to_lowercase()
            .chars()
            .filter(|c| c.is_alphanumeric())
            .collect::<Vec<char>>();
        let mut rclean: Vec<char> = clean.clone();
        rclean.reverse();

        rclean == clean
    }
}

impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let clean = s
            .chars()
            .filter(|c| c.is_alphanumeric())
            .map(|c| c.to_lowercase());
        let rclean = s
            .chars()
            .reverse()
            .filter(|c| c.is_alphanumeric())
            .map(|c| c.to_lowercase());

        rclean == clean
    }
}

impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let clean = s
            .chars()
            .filter(|c| c.is_alphanumeric())
            .map(|c| c.to_ascii_lowercase());
        let rclean = clean.clone().rev();

        rclean.zip(clean).all(|(a, b)| a == b)
    }
}

impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let chars = s.to_lowercase().chars().collect::<Vec<_>>();
        let len = chars.len() as i32;
        return Self::is_equal(chars, 0, len - 1);
    }

    pub fn is_equal(chars: Vec<char>, left: i32, right: i32) -> bool {
        if left >= right {
            return true;
        }

        if !chars[left as usize].is_alphanumeric() {
            return Self::is_equal(chars, left + 1, right);
        }

        if !chars[right as usize].is_alphanumeric() {
            return Self::is_equal(chars, left, right - 1);
        }

        if chars[left as usize] == chars[right as usize] {
            return Self::is_equal(chars, left + 1, right - 1);
        }

        false
    }
}

impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let chars = s.chars().collect::<Vec<_>>();
        let mut left = 0;
        let mut right = chars.len() - 1;

        while (left < right) {
            if !chars[left].is_alphanumeric() {
                left += 1;
                continue;
            }

            if !chars[right].is_alphanumeric() {
                right -= 1;
                continue;
            }

            if chars[left].to_ascii_lowercase() != chars[right].to_ascii_lowercase() {
                return false;
            }

            left += 1;
            right -= 1;
        }

        return true;
    }
}
