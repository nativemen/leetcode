impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut prefix_len = strs[0].len();

        for i in 1..strs.len() {
            if prefix_len > strs[i].len() {
                prefix_len = strs[i].len();
            }
            while prefix_len > 0 && strs[0][..prefix_len] != strs[i][..prefix_len] {
                prefix_len -= 1;
            }
        }

        return strs[0][..prefix_len].to_string();
    }
}

impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut prefix_len = strs[0].len();

        for i in 1..strs.len() {
            while !strs[i].starts_with(strs[0][..prefix_len].to_owned().as_str()) {
                prefix_len -= 1;
            }

            if prefix_len == 0 {
                break;
            }
        }

        return strs[0][..prefix_len].to_string();
    }
}


impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut prefix_len = strs[0].len();

        for i in 1..strs.len() {
            let mut j = 0;
            while j < prefix_len && j < strs[i].len() && strs[i].find(&strs[0][..j + 1]) == Some(0) {
                j += 1;
            }

            prefix_len = j;
            if prefix_len == 0 {
                break;
            }
        }

        return strs[0][..prefix_len].to_string();
    }
}
