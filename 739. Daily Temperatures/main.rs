struct Solution;

impl Solution {
    pub fn daily_temperatures(temperatures: Vec<i32>) -> Vec<i32> {
        let temp_size = temperatures.len();
        let mut result = vec![0; temp_size];
        let mut stack = Vec::new();

        for i in 0..temp_size {
            while !stack.is_empty() && temperatures[i] > temperatures[*stack.last().unwrap()] {
                let index = stack.pop().unwrap();
                result[index] = (i - index) as i32;
            }

            stack.push(i);
        }

        result
    }
}


impl Solution {
    pub fn daily_temperatures(temperatures: Vec<i32>) -> Vec<i32> {
        let temp_size = temperatures.len();
        let mut result = vec![0; temp_size];
        let mut stack = Vec::new();

        for i in 0..temp_size {
            while let Some(&index) = stack.last() {
                if temperatures[i] <= temperatures[index] {
                    break;
                }
                stack.pop();
                result[index] = (i - index) as i32;
            }

            stack.push(i);
        }

        result
    }
}
