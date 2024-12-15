impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        let mut max_wealth: i32 = 0;
        for customer in accounts {
            max_wealth = max_wealth.max(customer.iter().sum());
        }

        max_wealth
    }
}

impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        accounts
            .iter()
            .map(|customer| customer.iter().sum())
            .max()
            .unwrap()
    }
}
