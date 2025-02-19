struct Solution;

impl Solution {
    pub fn max_profit(k: i32, prices: Vec<i32>) -> i32 {
        let size = prices.len();
        let mut buys = vec![i32::MAX; k as usize];
        let mut profits = vec![0; k as usize];

        for i in 0..size {
            buys[0] = buys[0].min(prices[i]);
            profits[0] = profits[0].max(prices[i] - buys[0]);
            for j in 1..k as usize {
                buys[j] = buys[j].min(prices[i] - profits[j - 1]);
                profits[j] = profits[j].max(prices[i] - buys[j]);
            }
        }

        profits[k as usize - 1]
    }
}

impl Solution {
    pub fn max_profit(k: i32, prices: Vec<i32>) -> i32 {
        let size = prices.len();
        let mut buys = vec![i32::MAX; k as usize];
        let mut profits = vec![0; k as usize];

        for price in prices {
            buys[0] = buys[0].min(price);
            profits[0] = profits[0].max(price - buys[0]);
            for j in 1..k as usize {
                buys[j] = buys[j].min(price - profits[j - 1]);
                profits[j] = profits[j].max(price - buys[j]);
            }
        }

        profits[k as usize - 1]
    }
}

impl Solution {
    pub fn max_profit(k: i32, prices: Vec<i32>) -> i32 {
        let size = prices.len();
        let mut buys = vec![i32::MAX; k as usize];
        let mut profits = vec![0; k as usize];

        for price in prices {
            for i in 0..k as usize {
                buys[i] = buys[i].min(price - if i == 0 { 0 } else { profits[i - 1] });
                profits[i] = profits[i].max(price - buys[i]);
            }
        }

        profits[k as usize - 1]
    }
}
