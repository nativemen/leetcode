struct Solution;

impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut intervals = intervals;
        intervals.sort();

        let mut result = Vec::new();
        result.push(vec![intervals[0][0], intervals[0][1]]);
        let mut index = 0;

        for interval in intervals {
            if result[index][1] < interval[0] {
                index += 1;
                result.push(interval.clone());
            } else {
                result[index][1] = result[index][1].max(interval[1]);
            }
        }

        result
    }
}