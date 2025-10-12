struct Solution;

impl Solution {
    pub fn find_right_interval(intervals: Vec<Vec<i32>>) -> Vec<i32> {
        let mut array = Vec::new();

        for (index, interval) in intervals.iter().enumerate() {
            array.push((interval[0], index));
        }

        array.sort();

        let intervals_size = intervals.len();
        let mut result = vec![-1; intervals_size];

        for i in 0..intervals_size {
            let mut left = 0;
            let mut right = intervals_size as i32 - 1;

            while left <= right {
                let mid = left + (right - left) / 2;

                if intervals[i][1] <= array[mid as usize].0 {
                    result[i] = array[mid as usize].1 as i32;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        result
    }
}

impl Solution {
    pub fn find_right_interval(intervals: Vec<Vec<i32>>) -> Vec<i32> {
        let mut array = Vec::new();

        for (index, interval) in intervals.iter().enumerate() {
            array.push((interval[0], index));
        }

        array.sort();

        let intervals_size = intervals.len();
        let mut result = vec![-1; intervals_size];

        for i in 0..intervals_size {
            let mut left = 0;
            let mut right = intervals_size as i32 - 1;

            while left <= right {
                let mid = left + (right - left) / 2;

                if intervals[i][1] <= array[mid as usize].0 {
                    result[i] = array[mid as usize].1 as i32;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        result
    }
}
