struct Solution;

impl Solution {
    pub fn decode_string(s: String) -> String {
        let mut result = String::new();
        let mut nums = Vec::new();
        let mut num = 0;

        for c in s.chars() {
            if c.is_digit(10) {
                num = num * 10 + c.to_digit(10).unwrap() as usize;
            } else if c == '[' {
                result.push(c);
                nums.push(num);
                num = 0;
            } else if c == ']' {
                let mut temp = String::new();
                while let Some(ch) = result.pop() {
                    if ch == '[' {
                        break;
                    }

                    temp.insert(0, ch);
                }

                let number = nums.pop().unwrap();
                result.push_str(temp.repeat(number).as_str());
            } else {
                result.push(c);
            }
        }

        result
    }
}

impl Solution {
    pub fn decode_string(s: String) -> String {
        let mut cur_num = 0;
        let mut cur_str = String::new();
        let mut v = Vec::new();

        for c in s.chars() {
            if c.is_digit(10) {
                cur_num = cur_num * 10 + c.to_digit(10).unwrap() as usize;
            } else if c == '[' {
                v.push((cur_str.clone(), cur_num));
                cur_num = 0;
                cur_str = String::new();
            } else if c == ']' {
                if let Some((prev_str, num)) = v.pop() {
                    cur_str = prev_str + cur_str.repeat(num).as_str();
                }
            } else {
                cur_str.push(c);
            }
        }

        cur_str
    }
}
