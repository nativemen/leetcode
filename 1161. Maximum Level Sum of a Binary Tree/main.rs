struct Solution;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root.is_none() {
            return 0;
        }

        let mut q = VecDeque::new();

        q.push_back(root);

        let mut max_sum = i32::MIN;
        let mut level = 1;
        let mut max_level = 1;

        while !q.is_empty() {
            let size = q.len();
            let mut sum = 0;

            for _ in 0..size {
                if let Some(Some(node)) = q.pop_front() {
                    let node_ref = node.borrow();

                    sum += node_ref.val;

                    if node_ref.left.is_some() {
                        q.push_back(node_ref.left.clone());
                    }

                    if node_ref.right.is_some() {
                        q.push_back(node_ref.right.clone());
                    }
                }
            }

            if max_sum < sum {
                max_sum = sum;
                max_level = level;
            }

            level += 1;
        }

        max_level
    }
}

// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root.is_none() {
            return 0;
        }

        let mut q = VecDeque::new();

        q.push_back(root);

        let mut sums = Vec::new();

        while !q.is_empty() {
            let size = q.len();
            let mut sum = 0;

            for _ in 0..size {
                if let Some(Some(node)) = q.pop_front() {
                    let node_ref = node.borrow();

                    sum += node_ref.val;

                    if node_ref.left.is_some() {
                        q.push_back(node_ref.left.clone());
                    }

                    if node_ref.right.is_some() {
                        q.push_back(node_ref.right.clone());
                    }
                }
            }

            sums.push(sum);
        }

        if let Some((index, _)) = sums
            .iter()
            .enumerate()
            .max_by(|&(i1, &value1), &(i2, &value2)| value1.cmp(&value2).then(i2.cmp(&i1)))
        {
            index as i32 + 1
        } else {
            0
        }
    }
}
