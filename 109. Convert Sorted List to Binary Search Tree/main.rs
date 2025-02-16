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
    pub fn sorted_list_to_bst(head: Option<Box<ListNode>>) -> Option<Rc<RefCell<TreeNode>>> {
        let v = Self::to_vec(head);

        Self::helper(&v, 0, v.len() as i32 - 1)
    }

    fn to_vec(head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut v = Vec::new();
        let mut root = head;
        while let Some(node) = root {
            v.push(node.val);
            root = node.next;
        }

        v
    }

    fn helper(v: &Vec<i32>, left: i32, right: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if left > right {
            return None;
        }

        let mid = (left + right + 1) / 2;
        let mut node = TreeNode::new(v[mid as usize]);
        node.left = Self::helper(v, left, mid - 1);
        node.right = Self::helper(v, mid + 1, right);

        Some(Rc::new(RefCell::new(node)))
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
    pub fn sorted_list_to_bst(head: Option<Box<ListNode>>) -> Option<Rc<RefCell<TreeNode>>> {
        let v = Self::to_vec(head);

        Self::helper(&v)
    }

    fn to_vec(head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut v = Vec::new();
        let mut root = head;
        while let Some(node) = root {
            v.push(node.val);
            root = node.next;
        }

        v
    }

    fn helper(v: &Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        if v.is_empty() {
            return None;
        }

        let mid = v.len() / 2;
        let mut node = TreeNode::new(v[mid]);
        node.left = Self::helper(&v[..mid].to_vec());
        node.right = Self::helper(&v[mid + 1..].to_vec());

        Some(Rc::new(RefCell::new(node)))
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
impl<'a> Solution {
    pub fn sorted_list_to_bst(head: Option<Box<ListNode>>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::helper(head.as_ref(), None)
    }

    fn findListMiddle(
        head: Option<&'a Box<ListNode>>,
        tail: Option<&'a Box<ListNode>>,
    ) -> Option<&'a Box<ListNode>> {
        let mut slow = head;
        let mut fast = head;

        while fast != tail && fast.and_then(|node| node.next.as_ref()) != tail {
            slow = slow.and_then(|node| node.next.as_ref());
            fast = fast.and_then(|node| node.next.as_ref());
            fast = fast.and_then(|node| node.next.as_ref());
        }

        slow
    }

    fn helper(
        head: Option<&Box<ListNode>>,
        tail: Option<&Box<ListNode>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if head == tail {
            return None;
        }

        let mid_node = Self::findListMiddle(head, tail);
        let mut node = TreeNode::new(mid_node.unwrap().val);
        if (head == mid_node) {
            return Some(Rc::new(RefCell::new(node)));
        }
        node.left = Self::helper(head, mid_node);
        node.right = Self::helper(mid_node.unwrap().next.as_ref(), tail);

        Some(Rc::new(RefCell::new(node)))
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
    pub fn sorted_list_to_bst(head: Option<Box<ListNode>>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::helper(head)
    }

    fn split_list_at_middle(
        mut head: Option<Box<ListNode>>,
    ) -> (Option<Box<ListNode>>, Option<Box<ListNode>>) {
        if head.is_none() {
            return (None, None);
        }

        let mut slow = head.as_ref();
        let mut fast = head.as_ref();
        let mut count = 0;

        while fast.is_some() && fast.as_ref().unwrap().next.is_some() {
            slow = slow.unwrap().next.as_ref();
            fast = fast.unwrap().next.as_ref().unwrap().next.as_ref();
            count += 1;
        }

        if count == 0 {
            let middle = head.take();
            return (None, middle);
        }

        let mut current = &mut head;
        for _ in 0..count {
            current = &mut current.as_mut().unwrap().next;
        }

        let middle = current.take();

        (head, middle)
    }

    fn helper(head: Option<Box<ListNode>>) -> Option<Rc<RefCell<TreeNode>>> {
        if head.is_none() {
            return None;
        }

        let (left, mid) = Self::split_list_at_middle(head);
        let mut node = TreeNode::new(mid.as_ref().unwrap().val);
        node.left = Self::helper(left);
        node.right = Self::helper(mid.unwrap().next);

        Some(Rc::new(RefCell::new(node)))
    }
}
