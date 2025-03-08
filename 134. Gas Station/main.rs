struct Solution;

impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        if gas.iter().sum::<i32>() < cost.iter().sum::<i32>() {
            return -1;
        }

        let mut tank = 0;
        let mut start = 0;

        for i in 0..gas.len() {
            tank += gas[i] - cost[i];
            if tank < 0 {
                start = i as i32 + 1;
                tank = 0;
            }
        }

        start
    }
}

impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        let mut total = 0;
        let mut tank = 0;
        let mut start = 0;

        for i in 0..gas.len() {
            total += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if tank < 0 {
                start = i as i32 + 1;
                tank = 0;
            }
        }

        if total < 0 {
            -1
        } else {
            start
        }
    }
}
