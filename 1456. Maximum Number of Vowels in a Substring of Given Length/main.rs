struct Solution;

impl Solution {
    pub fn max_vowels(s: String, k: i32) -> i32 {
        fn vowel_check(c: char) -> i32 {
            if "aeiou".contains(c) {
                return 1;
            }

            0
        }

        let len = s.len();
        let mut count = 0;
        let mut max_count = 0;
        let s = s.as_bytes();

        for i in 0..len {
            count += vowel_check(s[i] as char);
            if i >= k as usize {
                count -= vowel_check(s[i - k as usize] as char);
            }
            max_count = max_count.max(count);
        }

        max_count
    }
}

impl Solution {
    pub fn max_vowels(s: String, k: i32) -> i32 {
        let vowels = vec!['a', 'e', 'i', 'o', 'u'];
        let s = s.chars().collect::<Vec<_>>();
        let len = s.len();
        let mut count = 0;
        let mut max_count = 0;

        for i in 0..len {
            if vowels.contains(&s[i]) {
                count += 1;
            }
            if i >= k as usize && vowels.contains(&s[i - k as usize]) {
                count -= 1;
            }
            max_count = max_count.max(count);
        }

        max_count
    }
}

impl Solution {
    pub fn max_vowels(s: String, k: i32) -> i32 {
        let vowels = vec![
            1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        ];
        let s = s.chars().collect::<Vec<_>>();
        let len = s.len();
        let mut count = 0;
        let mut max_count = 0;

        for i in 0..len {
            count += vowels[s[i] as usize - 'a' as usize];
            if i >= k as usize {
                count -= vowels[s[i - k as usize] as usize - 'a' as usize];
            }
            max_count = max_count.max(count);
        }

        max_count
    }
}
