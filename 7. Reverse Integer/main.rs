impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut str = x
            .to_string()
            .chars()
            .skip_while(|&c| c == '-')
            .collect::<Vec<char>>()
            .iter()
            .rev()
            .collect::<String>();

        if x < 0 {
            str.insert_str(0, "-");
        }

        str.parse::<i32>().unwrap_or(0)
    }
}

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let str = x.abs().to_string().chars().rev().collect::<String>();
        let result = str.parse::<i32>().unwrap_or(0);
        if x < 0 {
            -result
        } else {
            result
        }
    }
}

class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN = -pow(2, 31)
        INT_MAX = pow(2, 31) - 1

        offset = if x < 0 {
            1
        } else {
            0
        }
        result = int(str(abs(x))[offset:][::-1])

        if result < INT_MIN or result > INT_MAX:
            return 0

        return result

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let result = 0;

        while x != 0 {
            let digit = x % 10;
<
            if (result > i32::MAX / 10) || (result == i32::MAX / 10 && digit > i32::MAX % 10) || (result < i32::MIN / 10) ||
             (result == i32::MIN / 10 && digit < i32::MIN % 10) {
                return false;
            }

            result = result * 10 + digit;
            x /= 10;
        }

        return result;
    }
}
