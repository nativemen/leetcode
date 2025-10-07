struct Solution;

impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        grid.iter()
            .flat_map(|line| line.iter())
            .filter(|&&x| x < 0)
            .count() as i32
    }
}

impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        grid.iter()
            .map(|line| line.iter().filter(|&&x| x < 0).count() as i32)
            .sum()
    }
}
