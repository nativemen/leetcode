impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        if let Some(pos) = haystack.find(&needle) {
            return pos as i32;
        }

        return -1;
    }
}

impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        let v: Vec<_> = haystack.match_indices(&needle).collect();
        if v.is_empty() {
            return -1;
        }

        return v[0].0 as i32;
    }
}

impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        let len1 = haystack.len();
        let len2 = needle.len();

        if len1 < len2 {
            return -1;
        }

        for i in 0..=len1 - len2 {
            if haystack[i..i + len2] == needle[..] {
                return i as i32;
            }
        }

        return -1;
    }
}

impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        let len1 = haystack.len();
        let len2 = needle.len();

        if len1 < len2 {
            return -1;
        }

        for i in 0..=len1 - len2 {
            if haystack.get(i..i + len2) == Some(&needle) {
                return i as i32;
            }
        }

        return -1;
    }
}

impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        let s1 = haystack.chars().collect::<Vec<_>>();
        let s2 = needle.chars().collect::<Vec<_>>();
        let len1 = s1.len();
        let len2 = s2.len();

        if len1 < len2 {
            return -1;
        }

        for i in 0..=len1 - len2 {
            let mut j = 0;
            while j < len2 && s1[i + j] == s2[j] {
                j += 1;
            }

            if j == len2 {
                return i as i32;
            }
        }

        return -1;
    }
}
