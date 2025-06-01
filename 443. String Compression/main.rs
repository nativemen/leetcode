struct Solution;

impl Solution {
    pub fn compress(chars: &mut Vec<char>) -> i32 {
        let chars_size = chars.len();
        let mut count = 1;
        let mut len = 0;
        let mut current = chars[0];

        for i in 0..chars_size {
            if i + 1 == chars_size || chars[i] != chars[i + 1] {
                chars[len] = current;
                len += 1;

                if count > 1 {
                    for c in count.to_string().chars() {
                        chars[len] = c;
                        len += 1;
                    }
                }

                if i + 1 < chars_size {
                    current = chars[i + 1];
                    count = 1;
                }
            } else {
                count += 1;
            }
        }

        len as i32
    }
}
