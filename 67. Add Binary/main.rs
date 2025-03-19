struct Solution;

impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let mut index1 = a.len() as i32 - 1;
        let mut index2 = b.len() as i32 - 1;
        let mut carry = 0;
        let mut result = Vec::new();

        while index1 >= 0 || index2 >= 0 || carry > 0 {
            let digit1 = if index1 >= 0 {
                a.chars().nth(index1 as usize).unwrap() as i32 - '0' as i32
            } else {
                0
            };
            let digit2 = if index2 >= 0 {
                b.chars().nth(index2 as usize).unwrap() as i32 - '0' as i32
            } else {
                0
            };
            let sum = digit1 + digit2 + carry;
            result.push((b'0' + (sum & 1) as u8) as char);
            carry = sum >> 1;
            index1 -= 1;
            index2 -= 1;
        }

        result.reverse();
        result.iter().collect()
    }
}

impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let a = a.as_bytes();
        let b = b.as_bytes();
        let mut index1 = a.len() as i32 - 1;
        let mut index2 = b.len() as i32 - 1;
        let mut carry = 0;
        let mut result = Vec::new();

        while index1 >= 0 || index2 >= 0 || carry > 0 {
            let digit1 = if index1 >= 0 {
                a[index1 as usize] as i32 - '0' as i32
            } else {
                0
            };
            let digit2 = if index2 >= 0 {
                b[index2 as usize] as i32 - '0' as i32
            } else {
                0
            };
            let sum = digit1 + digit2 + carry;
            result.push((b'0' + (sum & 1) as u8) as char);
            carry = sum >> 1;
            index1 -= 1;
            index2 -= 1;
        }

        result.reverse();
        result.iter().collect()
    }
}
