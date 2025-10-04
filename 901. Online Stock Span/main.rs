struct Solution;

struct StockSpanner {
    stk: Vec<(i32, i32)>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl StockSpanner {
    fn new() -> Self {
        StockSpanner { stk: Vec::new(), }
    }

    fn next(&mut self, price: i32) -> i32 {
        let mut span = 1;

        while !self.stk.is_empty() && self.stk.last().unwrap().0 <= price {
            span += self.stk.pop().unwrap().1;
        }

        self.stk.push((price, span));

        span
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * let obj = StockSpanner::new();
 * let ret_1: i32 = obj.next(price);
 */