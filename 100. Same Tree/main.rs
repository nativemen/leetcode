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
    pub fn is_same_tree(
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        if let (Some(node1), Some(node2)) = (p.as_ref(), q.as_ref()) {
            let node1_ref = node1.borrow();
            let node2_ref = node2.borrow();
            return node1_ref.val == node2_ref.val
                && Self::is_same_tree(node1_ref.left.clone(), node2_ref.left.clone())
                && Self::is_same_tree(node1_ref.right.clone(), node2_ref.right.clone());
        } else if p.is_none() && q.is_none() {
            return true;
        } else {F
            return false;
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
    pub fn is_same_tree(
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        let mut stack = vec![(p, q)];

        while !stack.is_empty() {
            let (p, q) = stack.pop().unwrap();

            if let (Some(node1), Some(node2)) = (p.as_ref(), q.as_ref()) {
                let node1_ref = node1.borrow();
                let node2_ref = node2.borrow();

                if node1_ref.val == node2_ref.val {
                    stack.push((node1_ref.left.clone(), node2_ref.left.clone()));
                    stack.push((node1_ref.right.clone(), node2_ref.right.clone()));
                } else {
                    return false;
                }
            } else if p.is_none() && q.is_none() {
                continue;
            } else {
                return false;
            }
        }

        true
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
    pub fn is_same_tree(
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        match (p, q) {
            (None, None) => true,
            (Some(node1), Some(node2)) => {
                let node1_ref = node1.borrow();
                let node2_ref = node2.borrow();
                if (node1_ref.val != node2_ref.val) {
                    return false;
                }

                Self::is_same_tree(node1_ref.left.clone(), node2_ref.left.clone())
                    && Self::is_same_tree(node1_ref.right.clone(), node2_ref.right.clone())
            }
            _ => false,
        }
    }
}