struct Solution;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */
impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let mut left = 1;
        let mut right = n;

        while left <= right {
            let mut mid = ((left as i64 + right as i64) / 2) as i32;
            let result = guess(mid);

            if result < 0 {
                right = mid - 1;
            } else if result > 0 {
                left = mid + 1;
            } else {
                return mid;
            }
        }

        -1
    }
}

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */
impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let mut left = 1;
        let mut right = n;

        while left <= right {
            let mut mid = ((left as i64 + right as i64) / 2) as i32;
            match guess(mid) {
                0 => return mid,
                -1 => right = mid - 1,
                _d => left = mid + 1,
            };
        }

        -1
    }
}
