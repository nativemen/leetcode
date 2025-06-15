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
    pub fn delete_node(
        root: Option<Rc<RefCell<TreeNode>>>,
        key: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let root = root;

        if let Some(node) = root {
            let mut node_ref = node.borrow_mut();

            if node_ref.val > key {
                node_ref.left = Self::delete_node(node_ref.left.clone(), key);
            } else if node_ref.val < key {
                node_ref.right = Self::delete_node(node_ref.right.clone(), key);
            } else {
                match (node_ref.left.clone(), node_ref.right.clone()) {
                    (None, None) => return None,
                    (Some(left), None) => return Some(left),
                    (None, Some(right)) => return Some(right),
                    (Some(_), Some(right)) => {
                        let mut current = right.clone();

                        while current.borrow().left.is_some() {
                            let left = current.borrow().left.clone().unwrap();
                            current = left;
                        }

                        node_ref.val = current.borrow().val;
                        node_ref.right = Self::delete_node(node_ref.right.clone(), node_ref.val);
                    }
                }
            }

            return Some(node.clone());
        }

        None
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
    pub fn delete_node(
        root: Option<Rc<RefCell<TreeNode>>>,
        key: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let root = root;

        if let Some(node) = root {
            let mut node_ref = node.borrow_mut();

            if node_ref.val > key {
                node_ref.left = Self::delete_node(node_ref.left.clone(), key);
            } else if node_ref.val < key {
                node_ref.right = Self::delete_node(node_ref.right.clone(), key);
            } else {
                match (node_ref.left.clone(), node_ref.right.clone()) {
                    (None, None) => return None,
                    (Some(left), None) => return Some(left),
                    (None, Some(right)) => return Some(right),
                    (_, _) => {
                        let mut current = node_ref.right.clone();

                        while let Some(cur_node) = current.clone() {
                            let cur_ref = cur_node.borrow();

                            if cur_ref.left.is_some() {
                                current = cur_ref.left.clone();
                            } else {
                                break;
                            }
                        }

                        if let Some(cur_node) = current {
                            let value = cur_node.borrow().val;
                            node_ref.val = value;
                            node_ref.right = Self::delete_node(node_ref.right.clone(), value);
                        }
                    }
                }
            }

            return Some(node.clone());
        }

        None
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
    pub fn delete_node(
        root: Option<Rc<RefCell<TreeNode>>>,
        key: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let root = root;

        if let Some(node) = root {
            let mut node_ref = node.borrow_mut();

            if node_ref.val > key {
                node_ref.left = Self::delete_node(node_ref.left.clone(), key);
            } else if node_ref.val < key {
                node_ref.right = Self::delete_node(node_ref.right.clone(), key);
            } else {
                match (node_ref.left.clone(), node_ref.right.clone()) {
                    (None, None) => return None,
                    (Some(left), None) => return Some(left),
                    (None, Some(right)) => return Some(right),
                    (_, _) => {
                        let mut current = node_ref.left.clone();

                        while let Some(cur_node) = current.clone() {
                            let cur_ref = cur_node.borrow();

                            if cur_ref.right.is_some() {
                                current = cur_ref.right.clone();
                            } else {
                                break;
                            }
                        }

                        if let Some(cur_node) = current {
                            let value = cur_node.borrow().val;
                            node_ref.val = value;
                            node_ref.left = Self::delete_node(node_ref.left.clone(), value);
                        }
                    }
                }
            }

            return Some(node.clone());
        }

        None
    }
}
