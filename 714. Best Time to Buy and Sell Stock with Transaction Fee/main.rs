struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>, fee: i32) -> i32 {
        let mut buy = i32::MIN;
        let mut profit = 0;

        for price in prices {
            buy = buy.max(profit - price);
            profit = profit.max(buy + price - fee);
        }

        profit
    }
}
