struct Solution;

impl Solution {
    pub fn min_flips(a: i32, b: i32, c: i32) -> i32 {
        let mut flips = 0;
        let mut a = a;
        let mut b = b;
        let mut c = c;

        while a != 0 || b != 0 || c != 0 {
            let (x, y, z) = (a & 0x1, b & 0x1, c & 0x1);

            if z == 0 {
                flips += x + y;
            } else {
                if (x | y) == 0 {
                    flips += 1;
                }
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        flips
    }
}
