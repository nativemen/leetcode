struct Solution;

impl Solution {
    pub fn erase_overlap_intervals(intervals: Vec<Vec<i32>>) -> i32 {
        let mut intervals = intervals;
        intervals.sort();

        let mut count = 0;
        let mut pre_end = intervals[0][1];

        for i in 1..intervals.len() {
            if intervals[i][0] >= pre_end {
                pre_end = intervals[i][1];
            } else {
                count += 1;
                pre_end = pre_end.min(intervals[i][1]);
            }
        }

        count
    }
}
