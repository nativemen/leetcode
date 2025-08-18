struct Solution;

impl Solution {
    pub fn successful_pairs(spells: Vec<i32>, potions: Vec<i32>, success: i64) -> Vec<i32> {
        let mut potions = potions;
        potions.sort();

        let spells_size = spells.len();
        let potions_size = potions.len();
        let mut result = Vec::new();

        for i in 0..spells_size {
            let mut left = 0;
            let mut right = potions_size;

            while left < right {
                let mid = (left + right) / 2;

                if (spells[i] as i64) * (potions[mid] as i64) < success {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            result.push((potions_size - left) as i32);
        }

        result
    }
}

impl Solution {
    pub fn successful_pairs(spells: Vec<i32>, potions: Vec<i32>, success: i64) -> Vec<i32> {
        let mut potions = potions;
        potions.sort();

        let spells_size = spells.len();
        let potions_size = potions.len();
        let mut spells = spells;

        for i in 0..spells_size {
            let mut left = 0;
            let mut right = potions_size;

            while left < right {
                let mid = (left + right) / 2;

                if (spells[i] as i64) * (potions[mid] as i64) < success {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            spells[i] = (potions_size - left) as i32;
        }

        spells
    }
}
