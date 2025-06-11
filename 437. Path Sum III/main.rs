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
    pub fn path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> i32 {
        fn calc_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i64, started: bool) -> i32 {
            let mut count = 0;

            if let Some(node) = root {
                let node_ref = node.borrow();

                if target_sum == node_ref.val as i64 {
                    count += 1;
                }

                if !started {
                    count += calc_sum(node_ref.left.clone(), target_sum, started);
                    count += calc_sum(node_ref.right.clone(), target_sum, started);
                }

                count += calc_sum(
                    node_ref.left.clone(),
                    target_sum - node_ref.val as i64,
                    true,
                );

                count += calc_sum(
                    node_ref.right.clone(),
                    target_sum - node_ref.val as i64,
                    true,
                );
            }

            count
        }

        calc_sum(root, target_sum as i64, false)
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
    pub fn path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> i32 {
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32, q: &mut Vec<i32>) -> i32 {
            let mut count = 0;

            if let Some(node) = root {
                let node_ref = node.borrow();

                q.push(node_ref.val);

                let mut sum: i64 = 0;

                for &num in q.iter().rev() {
                    sum += num as i64;
                    if sum == target_sum as i64 {
                        count += 1;
                    }
                }

                count += dfs(node_ref.left.clone(), target_sum, q);
                count += dfs(node_ref.right.clone(), target_sum, q);

                q.pop();
            }

            count
        }

        let mut q = Vec::new();

        dfs(root, target_sum, &mut q)
    }
}
