struct Solution;

impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut result = Vec::new();

        Self::backtrack(&mut result, String::new(), n, n);

        result
    }

    fn backtrack(result: &mut Vec<String>, s: String, left: i32, right: i32) {
        if left == 0 && right == 0 {
            result.push(s);
            return;
        }

        if left > 0 {
            Self::backtrack(result, s.clone() + "(", left - 1, right);
        }

        if right > left {
            Self::backtrack(result, s.clone() + ")", left, right - 1);
        }
    }
}

impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut result = Vec::new();
        let mut s = String::new();

        Self::backtrack(&mut result, &mut s, n, n);

        result
    }

    fn backtrack(result: &mut Vec<String>, s: &mut String, left: i32, right: i32) {
        if left == 0 && right == 0 {
            result.push(s.clone());
            return;
        }

        if left > 0 {
            s.push('(');
            Self::backtrack(result, s, left - 1, right);
            s.pop();
        }

        if right > left {
            s.push(')');
            Self::backtrack(result, s, left, right - 1);
            s.pop();
        }
    }
}
