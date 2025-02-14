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

struct Solution;

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
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut res = Vec::new();
        let mut queue = VecDeque::new();
        queue.push_back(root);

        while !queue.is_empty() {
            let mut v = Vec::new();
            for _ in 0..queue.len() {
                if let Some(Some(node)) = queue.pop_front() {
                    let node_ref = node.borrow();
                    v.push(node_ref.val);
                    queue.push_back(node_ref.left.clone());
                    queue.push_back(node_ref.right.clone());
                }
            }

            if !v.is_empty() {
                res.push(v);
            }
        }

        res
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
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut res = Vec::new();

        Self::to_vec(&mut res, root, 0);
        res
    }

    fn to_vec(ans: &mut Vec<Vec<i32>>, root: Option<Rc<RefCell<TreeNode>>>, layer: usize) {
        if let Some(node) = root {
            let node_ref = node.borrow();
            if ans.len() < layer + 1 {
                ans.push(vec![]);
            }
            ans[layer].push(node_ref.val);
            Self::to_vec(ans, node_ref.left.clone(), layer + 1);
            Self::to_vec(ans, node_ref.right.clone(), layer + 1);
        }
    }
}
