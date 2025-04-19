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
use std::rc::Rc;
impl Solution {
    fn sum(node: &Option<Rc<RefCell<TreeNode>>>, num: i32) -> i32 {
        match node {
            None => 0,
            Some(node) => {
                let node_ref = node.borrow();
                let num = num * 10 + node_ref.val;

                if node_ref.left.is_none() && node_ref.right.is_none() {
                    return num;
                }

                return Self::sum(&node_ref.left, num) + Self::sum(&node_ref.right, num);
            }
        }
    }

    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::sum(&root, 0)
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
use std::rc::Rc;
impl Solution {
    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, num: i32, sum: &mut i32) {
        match node {
            None => (),
            Some(node) => {
                let node_ref = node.borrow();
                let num = num * 10 + node_ref.val;

                if node_ref.left.is_none() && node_ref.right.is_none() {
                    *sum += num;
                    return;
                }

                Self::dfs(&node_ref.left, num, sum);
                Self::dfs(&node_ref.right, num, sum);
            }
        }
    }

    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut sum = 0;

        Self::dfs(&root, 0, &mut sum);

        sum
    }
}
