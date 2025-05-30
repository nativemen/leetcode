struct Solution;

impl Solution {
    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        fn gcd(a: usize, b: usize) -> usize {
            if b == 0 {
                return a;
            }

            gcd(b, a % b)
        }

        let s1 = str1.clone() + &str2;
        let s2 = str2.clone() + &str1;

        if s1 != s2 {
            return String::new();
        }

        let gcd_len = gcd(str1.len(), str2.len());

        s1[..gcd_len].to_string()
    }
}
