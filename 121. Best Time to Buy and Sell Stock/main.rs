struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut max_prof = 0;
        let mut buy = prices[0];

        for price in prices {
            if (buy > price) {
                buy = price;
                continue;
            }

            max_prof = max_prof.max(price - buy);
        }

        max_prof
    }
}

use std::cmp::{max, min};

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        prices
            .iter()
            .fold((0, i32::MAX), |(profit, buy), &price| {
                (max(profit, price - buy), min(buy, price))
            })
            .0
    }
}
