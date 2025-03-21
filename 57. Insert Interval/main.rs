struct Solution;

impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut intervals = intervals
            .iter()
            .chain(vec![new_interval].iter())
            .cloned()
            .collect::<Vec<Vec<_>>>();
        intervals.sort();

        let mut index = 0;
        let mut result = Vec::new();
        result.push(vec![intervals[0][0], intervals[0][1]]);

        for interval in intervals.iter() {
            if result[index][1] < interval[0] {
                result.push(vec![interval[0], interval[1]]);
                index += 1;
            } else {
                result[index][1] = result[index][1].max(interval[1]);
            }
        }

        result
    }
}

impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let mut new_interval = new_interval;

        for i in 0..intervals.len() {
            if new_interval[1] < intervals[i][0] {
                result.push(vec![new_interval[0], new_interval[1]]);
                result.append(intervals[i..].to_vec().as_mut());

                return result;
            } else if new_interval[0] > intervals[i][1] {
                result.push(vec![intervals[i][0], intervals[i][1]]);
            } else {
                new_interval[0] = new_interval[0].min(intervals[i][0]);
                new_interval[1] = new_interval[1].max(intervals[i][1]);
            }
        }

        result.push(vec![new_interval[0], new_interval[1]]);

        result
    }
}

impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let mut new_interval = new_interval;
        let mut iter = intervals.into_iter();

        while let Some(interval) = iter.next() {
            if new_interval[1] < interval[0] {
                result.push(new_interval);
                result.push(interval);
                result.extend(iter);

                return result;
            } else if new_interval[0] > interval[1] {
                result.push(interval);
            } else {
                new_interval[0] = new_interval[0].min(interval[0]);
                new_interval[1] = new_interval[1].max(interval[1]);
            }
        }

        result.push(new_interval);

        result
    }
}
