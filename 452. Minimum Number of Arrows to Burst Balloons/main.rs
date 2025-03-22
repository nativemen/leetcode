struct Solution;

impl Solution {
    pub fn find_min_arrow_shots(points: Vec<Vec<i32>>) -> i32 {
        let mut points = points;
        points.sort();

        let mut index = 0;

        for i in 0..points.len() {
            if points[index][1] < points[i][0] {
                index += 1;
                points[index][0] = points[i][0];
                points[index][1] = points[i][1];
            } else {
                points[index][0] = points[index][0].max(points[i][0]);
                points[index][1] = points[index][1].min(points[i][1]);
            }
        }

        index as i32 + 1
    }
}

impl Solution {
    pub fn find_min_arrow_shots(points: Vec<Vec<i32>>) -> i32 {
        let mut points = points;
        points.sort();
    }
}
