struct Solution;

impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        fn is_empty(flowerbed: &Vec<i32>, pos: i32) -> bool {
            pos < 0 || pos >= flowerbed.len() as i32 || flowerbed[pos as usize] == 0
        }

        let mut count = 0;
        let mut flowerbed = flowerbed;

        for i in 0..flowerbed.len() as i32 {
            if is_empty(&flowerbed, i - 1) && is_empty(&flowerbed, i) && is_empty(&flowerbed, i + 1)
            {
                count += 1;
                flowerbed[i as usize] = 1;
            }
        }

        count >= n
    }
}

impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        let size = flowerbed.len();
        let mut count = 0;
        let mut flowerbed = flowerbed;

        for i in 0..flowerbed.len() {
            let left = i as i32 - 1 < 0 || flowerbed[i - 1] == 0;
            let right = i + 1 >= size || flowerbed[i + 1] == 0;

            if left && right && flowerbed[i] == 0 {
                count += 1;
                flowerbed[i] = 1;
            }
        }

        count >= n
    }
}
