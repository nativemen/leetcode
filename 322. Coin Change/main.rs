struct Solution;

impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let amount = amount as usize;
        let mut dp = vec![i32::MAX; amount + 1];
        dp[0] = 0;

        for i in 0..amount {
            if dp[i] == i32::MAX {
                continue;
            }

            for j in 0..coins.len() {
                if coins[j] as usize <= amount - i {
                    dp[i + coins[j] as usize] = dp[i + coins[j] as usize].min(dp[i] + 1);
                }
            }
        }

        if dp[amount] == i32::MAX {
            return -1;
        }

        dp[amount]
    }
}

impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let amount = amount as usize;
        let mut dp = vec![i32::MAX; amount + 1];
        dp[0] = 0;

        for coin in coins {
            for i in coin as usize..=amount {
                if dp[i - coin as usize] == i32::MAX {
                    continue;
                }

                dp[i] = dp[i].min(dp[i - coin as usize] + 1);
            }
        }

        if dp[amount] == i32::MAX {
            return -1;
        }

        dp[amount]
    }
}
