#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn spiral_matrix(m: i32, n: i32, head: Option<Box<ListNode>>) -> Vec<Vec<i32>> {
        let mut row = 0;
        let mut col = 0;
        let mut direction = 0;
        let mut result = vec![vec![-1; n as usize]; m as usize];
        let mut head = head;
        let dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];

        while let Some(node) = head {
            result[row as usize][col as usize] = node.val;

            let mut next_row = row + dirs[direction][0];
            let mut next_col = col + dirs[direction][1];

            if next_row < 0
                || next_row >= m
                || next_col < 0
                || next_col >= n
                || result[next_row as usize][next_col as usize] != -1
            {
                direction = (direction + 1) % 4;
                next_row = row + dirs[direction][0];
                next_col = col + dirs[direction][1];
            }

            row = next_row;
            col = next_col;

            head = node.next;
        }

        result
    }
}

// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn spiral_matrix(m: i32, n: i32, head: Option<Box<ListNode>>) -> Vec<Vec<i32>> {
        let mut left = 0;
        let mut right = n - 1;
        let mut top = 0;
        let mut bottom = m - 1;
        let mut head = head;
        let mut result = vec![vec![-1; n as usize]; m as usize];

        while left <= right && top <= bottom {
            for i in left..=right {
                if let Some(node) = head {
                    result[top as usize][i as usize] = node.val;
                    head = node.next;
                }
            }
            top += 1;

            for i in top..=bottom {
                if let Some(node) = head {
                    result[i as usize][right as usize] = node.val;
                    head = node.next;
                }
            }
            right -= 1;

            if top <= bottom {
                for i in (left..=right).rev() {
                    if let Some(node) = head {
                        result[bottom as usize][i as usize] = node.val;
                        head = node.next;
                    }
                }
                bottom -= 1;
            }

            if left <= right {
                for i in (top..=bottom).rev() {
                    if let Some(node) = head {
                        result[i as usize][left as usize] = node.val;
                        head = node.next;
                    }
                }
                left += 1;
            }
        }

        result
    }
}

// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn spiral_matrix(m: i32, n: i32, head: Option<Box<ListNode>>) -> Vec<Vec<i32>> {
        let mut left = 0;
        let mut right = n - 1;
        let mut top = 0;
        let mut bottom = m - 1;
        let mut count = 0;
        let mut head = head;
        let mut direction = 1;
        let mut result = vec![vec![-1; n as usize]; m as usize];
        let total = m * n;

        while count < total {
            match direction {
                1 => {
                    for i in left..=right {
                        if let Some(node) = head {
                            result[top as usize][i as usize] = node.val;
                            head = node.next;
                            count += 1;
                        } else {
                            return result;
                        }
                    }
                    top += 1;
                    direction = 2;
                }
                2 => {
                    for i in top..=bottom {
                        if let Some(node) = head {
                            result[i as usize][right as usize] = node.val;
                            head = node.next;
                            count += 1;
                        } else {
                            return result;
                        }
                    }
                    right -= 1;
                    direction = 3;
                }
                3 => {
                    for i in (left..=right).rev() {
                        if let Some(node) = head {
                            result[bottom as usize][i as usize] = node.val;
                            head = node.next;
                            count += 1;
                        } else {
                            return result;
                        }
                    }
                    bottom -= 1;
                    direction = 4;
                }
                _ => {
                    for i in (top..=bottom).rev() {
                        if let Some(node) = head {
                            result[i as usize][left as usize] = node.val;
                            head = node.next;
                            count += 1;
                        } else {
                            return result;
                        }
                    }
                    left += 1;
                    direction = 1;
                }
            }
        }

        result
    }
}
