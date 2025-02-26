struct Solution;

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let mut s = String::new();
        let mut num = num;

        while (num > 0) {
            if (num >= 1000) {
                s += "M";
                num -= 1000;
            } else if (num >= 900) {
                s += "CM";
                num -= 900;
            } else if (num >= 500) {
                s += "D";
                num -= 500;
            } else if (num >= 400) {
                s += "CD";
                num -= 400;
            } else if (num >= 100) {
                s += "C";
                num -= 100;
            } else if (num >= 90) {
                s += "XC";
                num -= 90;
            } else if (num >= 50) {
                s += "L";
                num -= 50;
            } else if (num >= 40) {
                s += "XL";
                num -= 40;
            } else if (num >= 10) {
                s += "X";
                num -= 10;
            } else if (num >= 9) {
                s += "IX";
                num -= 9;
            } else if (num >= 5) {
                s += "V";
                num -= 5;
            } else if (num >= 4) {
                s += "IV";
                num -= 4;
            } else {
                s += "I";
                num -= 1;
            }
        }

        return s;
    }
}

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let symbols = vec![
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
        ];
        let values = vec![1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
        let mut s = String::new();
        let mut num = num;
        let mut index = 0;

        while (num > 0) {
            while (num >= values[index]) {
                s += symbols[index];
                num -= values[index];
            }
            index += 1;
        }

        return s;
    }
}

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let tables = vec![
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I"),
        ];
        let mut s = String::new();
        let mut num = num;
        let mut index = 0;

        for (value, str) in tables {
            while num >= value {
                s += str;
                num -= value;
            }
        }

        return s;
    }
}

use std::collections::BTreeMap;

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let maps = BTreeMap::from([
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I"),
        ]);
        let mut s = String::new();
        let mut num = num;

        for (key, value) in maps.into_iter().rev() {
            while num >= key {
                s.push_str(value);
                num -= key;
            }
        }

        s
    }
}
