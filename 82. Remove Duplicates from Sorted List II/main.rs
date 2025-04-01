struct Solution;

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

use std::collections::HashMap;

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
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() || head.as_ref().unwrap().next.is_none() {
            return head;
        }

        let mut current = &head;
        let mut counts = HashMap::new();

        while let Some(node) = current {
            *counts.entry(node.val).or_insert(0) += 1;
            current = &node.next;
        }

        let mut dummy = ListNode::new(0);
        let mut tail = &mut dummy.next;
        let mut current = head;

        while let Some(mut node) = current {
            current = node.next.take();
            if counts[&node.val] == 1 {
                *tail = Some(node);
                tail = &mut tail.as_mut().unwrap().next;
            }
        }

        dummy.next
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
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() || head.as_ref().unwrap().next.is_none() {
            return head;
        }

        let mut result = None;
        let mut tail = &mut result;
        let mut head = head;
        let mut to_remove = 101;

        while let Some(mut current_node) = head {
            head = current_node.next.take();

            if current_node.val == to_remove {
                continue;
            }

            if head.is_some() && current_node.val == head.as_ref().unwrap().val {
                to_remove = current_node.val;
                continue;
            }

            tail = &mut tail.insert(current_node).next;
            to_remove = 101;
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
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() || head.as_ref().unwrap().next.is_none() {
            return head;
        }

        let mut dummy = ListNode::new(0);
        dummy.next = head;
        let mut prev = &mut dummy;

        while let Some(mut current_node) = prev.next.as_mut() {
            if current_node.next.is_some()
                && current_node.val == current_node.next.as_ref().unwrap().val
            {
                while current_node.next.is_some()
                    && current_node.val == current_node.next.as_ref().unwrap().val
                {
                    current_node = current_node.next.as_mut().unwrap();
                }

                prev.next = current_node.next.take();
            } else {
                prev = prev.next.as_mut().unwrap();
            }
        }

        dummy.next
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
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() || head.as_ref().unwrap().next.is_none() {
            return head;
        }

        let mut head = head;

        if head.as_ref().unwrap().val != head.as_ref().unwrap().next.as_ref().unwrap().val {
            head.as_mut().unwrap().next =
                Self::delete_duplicates(head.as_ref().unwrap().next.clone());
            return head;
        }

        while head.as_ref().unwrap().next.is_some()
            && head.as_ref().unwrap().val == head.as_ref().unwrap().next.as_ref().unwrap().val
        {
            head = head.unwrap().next;
        }

        Self::delete_duplicates(head.unwrap().next)
    }
}
