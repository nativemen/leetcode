struct Solution;

const ARRAY_SIZE: usize = 1001;

impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let mut dp = vec![0; ARRAY_SIZE + 1];

        for citation in citations {
            dp[citation as usize] += 1;
        }

        for i in (0..ARRAY_SIZE - 1).rev() {
            dp[i] += dp[i + 1];
            if dp[i] >= i {
                return i as i32;
            }
        }

        0
    }
}

impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let mut citations = citations;
        citations.sort_by(|a, b| b.cmp(a));

        let mut h = 0;
        for i in 0..citations.len() {
            if citations[i] < i as i32 + 1 {
                break;
            }

            h = i as i32 + 1;
        }

        h
    }
}

impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let mut citations = citations;
        citations.sort();
        citations.reverse();

        let mut h = 0;
        for i in 0..citations.len() {
            if citations[i] < i as i32 + 1 {
                break;
            }

            h = i as i32 + 1;
        }

        h
    }
}
