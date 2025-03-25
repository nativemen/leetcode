struct Solution;

impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        let mut stack = Vec::new();

        for token in tokens {
            if token == "+" {
                if let (Some(num2), Some(num1)) = (stack.pop(), stack.pop()) {
                    stack.push(num1 + num2);
                }
            } else if token == "-" {
                if let (Some(num2), Some(num1)) = (stack.pop(), stack.pop()) {
                    stack.push(num1 - num2);
                }
            } else if token == "*" {
                if let (Some(num2), Some(num1)) = (stack.pop(), stack.pop()) {
                    stack.push(num1 * num2);
                }
            } else if token == "/" {
                if let (Some(num2), Some(num1)) = (stack.pop(), stack.pop()) {
                    stack.push(num1 / num2);
                }
            } else {
                stack.push(token.parse().unwrap());
            }
        }

        stack[stack.len() - 1]
    }
}

impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        let mut stack = Vec::new();

        for token in tokens.iter() {
            match token.as_str() {
                "+" | "-" | "*" | "/" => {
                    if let (Some(num2), Some(num1)) = (stack.pop(), stack.pop()) {
                        let value = match token.as_str() {
                            "+" => num1 + num2,
                            "-" => num1 - num2,
                            "*" => num1 * num2,
                            "/" => num1 / num2,
                            _ => unreachable!(),
                        };

                        stack.push(value);
                    }
                }
                _ => {
                    stack.push(token.parse().unwrap());
                }
            }
        }

        stack.pop().unwrap()
    }
}
