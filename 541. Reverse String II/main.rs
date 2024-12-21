impl Solution {
    pub fn reverse_str(s: String, k: i32) -> String {
        s.chars()
            .collect::<Vec<char>>()
            .chunks_mut(k as usize)
            .enumerate()
            .flat_map(|(i, chunk)| {
                if i % 2 == 0 {
                    chunk.reverse();
                }
                chunk.iter().cloned()
            })
            .collect()
    }
}

impl Solution {
    pub fn reverse_str(s: String, k: i32) -> String {
        let mut vec = s.chars().collect::<Vec<char>>();

        for i in (0..vec.len()).step_by(2 * k as usize) {
            let end = std::cmp::min(i + k as usize, vec.len());
            vec[i..end].reverse();
        }

        vec.iter().collect()
    }
}

impl Solution {
    pub fn reverse_str(s: String, k: i32) -> String {
        let mut vec = s.chars().collect::<Vec<char>>();

        for i in (0..vec.len()).step_by(2 * k as usize) {
            let end = std::cmp::min(i + k as usize, vec.len());
            let mid = ((end - i + 1) / 2) as usize;
            for j in 0..mid {
                let c = vec[i + j];
                vec[i + j] = vec[end - 1 - j];
                vec[end - 1 - j] = c;
            }
        }

        vec.iter().collect()
    }
}
