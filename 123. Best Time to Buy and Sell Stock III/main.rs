struct Solution;

use std::cmp::{max, min};

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let size = prices.len();
        let mut left = vec![0; size];
        let mut lowest = prices[0];

        for i in 1..size {
            lowest = min(lowest, prices[i]);
            left[i] = max(left[i - 1], prices[i] - lowest);
        }

        let mut right = vec![0; size];
        let mut highest = prices[size - 1];
        for i in (0..size - 1).rev() {
            highest = max(highest, prices[i]);
            right[i] = max(right[i + 1], highest - prices[i]);
        }

        let mut max_profit = right[0];
        for i in 1..size {
            max_profit = max(max_profit, left[i - 1] + right[i]);
        }

        max_profit
    }
}


impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let size = prices.len();
        let mut buy1 = i32::MAX;
        let mut buy2 = i32::MAX;
        let mut profit1 = 0;
        let mut profit2 = 0;

        for i in 0..size {
            buy1 = buy1.min(prices[i]);
            profit1 = profit1.max(prices[i] - buy1);
            buy2 = buy2.min(prices[i] - profit1);
            profit2 = profit2.max(prices[i] - buy2);
        }

        profit2
    }
}
