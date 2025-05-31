struct Solution;

impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let mut t = s.chars().collect::<Vec<_>>();
        let vowels = "aeiouAEIOU";
        let size = t.len();
        let mut left = 0;
        let mut right = size as i32 - 1;

        while left < right {
            while left < size as i32 && !vowels.contains(t[left as usize]) {
                left += 1;
            }

            while right >= 0 && !vowels.contains(t[right as usize]) {
                right -= 1;
            }

            if left < right {
                t.swap(left as usize, right as usize);
                left += 1;
                right -= 1;
            }
        }

        t.iter().collect::<String>()
    }
}

impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let mut t = s.chars().collect::<Vec<_>>();
        let vowels = "aeiouAEIOU";
        let size = t.len();
        let mut left = 0;
        let mut right = size as i32 - 1;

        while left < right {
            if !vowels.contains(t[left as usize]) {
                left += 1;
            }

            if !vowels.contains(t[right as usize]) {
                right -= 1;
            }

            if vowels.contains(t[left as usize]) && vowels.contains(t[right as usize]) {
                t.swap(left as usize, right as usize);
                left += 1;
                right -= 1;
            }
        }

        t.iter().collect::<String>()
    }
}

impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let vowels = "aeiouAEIOU";
        let mut r = s.chars().rev().filter(|&c| vowels.contains(c));

        s.chars()
            .map(|c| {
                if vowels.contains(c) {
                    r.next().unwrap()
                } else {
                    c
                }
            })
            .collect()
    }
}

impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let is_vowels = |c| matches!(c, 'a' | 'e' | 'i' | 'o' | 'u' | 'A' | 'E' | 'I' | 'O' | 'U');
        let mut r = s.chars().rev().filter(|&c| is_vowels(c));

        s.chars()
            .map(|c| if is_vowels(c) { r.next().unwrap() } else { c })
            .collect()
    }
}
