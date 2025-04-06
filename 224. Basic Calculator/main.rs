struct Solution;

impl Solution {
    pub fn calculate(s: String) -> i32 {
        let mut result = 0;
        let mut num = 0;
        let mut sign = 1;
        let mut stack = Vec::new();

        for c in s.chars() {
            if c.is_ascii_digit() {
                num *= 10;
                num += c as i32 - '0' as i32;
            } else if c == '+' {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if c == '-' {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if c == '(' {
                stack.push(result);
                stack.push(sign);
                result = 0;
                num = 0;
                sign = 1;
            } else if c == ')' {
                result += sign * num;
                result *= stack.last().unwrap();
                stack.pop();
                result += stack.last().unwrap();
                stack.pop();
                num = 0;
                sign = 1;
            }
        }

        result + sign * num
    }
}

impl Solution {
    pub fn calculate(s: String) -> i32 {
        let mut result = 0;
        let mut num = 0;
        let mut sign = 1;
        let mut stack = Vec::new();

        for c in s.chars() {
            if c.is_ascii_digit() {
                num *= 10;
                num += c.to_digit(10).unwrap() as i32;
            } else if c == '+' {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if c == '-' {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if c == '(' {
                stack.push(result);
                stack.push(sign);
                result = 0;
                num = 0;
                sign = 1;
            } else if c == ')' {
                result += sign * num;
                result *= stack.pop().unwrap();
                result += stack.pop().unwrap();
                num = 0;
                sign = 1;
            }
        }

        result + sign * num
    }
}
