struct Solution;

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let str = s.trim_start();
        let mut sign = String::from("");
        let mut count = 0;
        if let Some(c) = str.chars().nth(0) {
            if c == '-' {
                sign += "-";
                count = 1;
            } else if c == '+' {
                sign += "+";
                count = 1;
            }
        };
        let result = (sign
            + &str
                .chars()
                .skip(count)
                .take_while(|c| c.is_numeric())
                .collect::<String>())
            .parse::<i32>();

        match (result) {
            Ok(num) => {
                return num;
            }
            Err(e) => match (e.kind()) {
                std::num::IntErrorKind::PosOverflow => {
                    return i32::MAX;
                }
                std::num::IntErrorKind::NegOverflow => {
                    return i32::MIN;
                }
                _ => {
                    return 0;
                }
            },
        }
    }
}

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let bytes = s.trim_start().as_bytes();
        let mut sign = 1;
        let mut start = 0;
        let length = bytes.len();
        if start < length && bytes[start] == b'-' {
            sign = -1;
            start += 1;
        } else if start < length && bytes[start] == b'+' {
            start += 1;
        }

        let mut num = 0;
        while (start < length && bytes[start].is_ascii_digit()) {
            let digit = sign * (bytes[start] - b'0') as i32;
            if num > i32::MAX / 10 || (num == i32::MAX / 10 && digit > i32::MAX % 10) {
                return i32::MAX;
            } else if num < i32::MIN / 10 || (num == i32::MIN / 10 && digit < i32::MIN % 10) {
                return i32::MIN;
            } else {
                num = num * 10 + digit;
                start += 1;
            }
        }

        return num;
    }
}
