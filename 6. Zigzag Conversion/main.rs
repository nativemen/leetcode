struct Solution;

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 {
            return s;
        }

        let mut rows = vec![String::new(); num_rows as usize];
        let mut level = 0;
        let mut direction = -1;

        for c in s.chars() {
            rows[level as usize].push(c);
            if level % (num_rows - 1) == 0 {
                direction *= -1;
            }
            level += direction;
        }

        rows.join("")
    }
}

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 {
            return s;
        }

        let mut result = String::new();
        let size = s.len();

        for i in 0..num_rows as usize {
            for j in (i..size).step_by(2 * (num_rows as usize - 1)) {
                result.push(s.chars().nth(j).unwrap());
                if i > 0
                    && i < num_rows as usize - 1
                    && j + 2 * (num_rows as usize - 1) - 2 * i < size
                {
                    result.push(
                        s.chars()
                            .nth(j + 2 * (num_rows as usize - 1) - 2 * i)
                            .unwrap(),
                    );
                }
            }
        }

        result
    }
}

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        let mut result: Vec<_> = (0..num_rows)
            .chain((1..num_rows - 1).rev())
            .cycle()
            .zip(s.chars())
            .collect();
        result.sort_by_key(|&(row, _)| row);
        result.iter().map(|&(_, c)| c).collect()
    }
}
