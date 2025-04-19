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
    pub fn flatten(root: &mut Option<Rc<RefCell<TreeNode>>>) {
        let mut node = root.clone();

        while let Some(n) = node {
            let mut n_ref = n.borrow_mut();

            if let Some(mut current_node) = n_ref.left.clone() {
                loop {
                    let right = current_node.borrow().right.clone();
                    if let Some(right_node) = right {
                        current_node = right_node;
                    } else {
                        break;
                    }
                }

                let mut current_ref = current_node.borrow_mut();
                current_ref.right = n_ref.right.take();
                n_ref.right = n_ref.left.take();
            }

            node = n_ref.right.clone();
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
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        match root {
            None => None,
            Some(node) => {
                let left_tail = Self::dfs(&node.borrow_mut().left);
                let right_tail = Self::dfs(&node.borrow_mut().right);

                if let Some(ref left_node) = left_tail {
                    left_node.borrow_mut().right = node.borrow_mut().right.take();
                    let left = node.borrow_mut().left.take();
                    node.borrow_mut().right = left;
                }

                [right_tail, left_tail, Some(node.clone())]
                    .into_iter()
                    .find(Option::is_some)
                    .unwrap()
            }
        }
    }

    pub fn flatten(root: &mut Option<Rc<RefCell<TreeNode>>>) {
        Self::dfs(root);
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
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        match root {
            None => None,
            Some(node) => {
                let mut node_ref = node.borrow_mut();
                let left_tail = Self::dfs(&node_ref.left);
                let right_tail = Self::dfs(&node_ref.right);

                match (left_tail.as_ref(), right_tail.as_ref()) {
                    (None, None) => root.clone(),
                    (Some(_), None) => {
                        let left = node_ref.left.take();
                        node_ref.right = left;
                        left_tail.clone()
                    }
                    (None, Some(_)) => right_tail,
                    (Some(_), Some(_)) => {
                        let right = node_ref.right.take();
                        left_tail.as_ref()?.borrow_mut().right = right;
                        node_ref.right = node_ref.left.take();
                        right_tail
                    }
                }
            }
        }
    }

    pub fn flatten(root: &mut Option<Rc<RefCell<TreeNode>>>) {
        Self::dfs(root);
    }
}
