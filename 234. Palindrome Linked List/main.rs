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
    fn to_vec(list: Option<Box<ListNode>>) -> Vec<i32> {
        let mut v = Vec::new();
        let mut cur = list;

        while let Some(node) = cur {
            v.push(node.val);
            cur = node.next;
        }

        v
    }

    pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool {
        let mut v1 = Self::to_vec(head);
        let mut v2 = v1.clone();

        v2.reverse();

        v1.eq(&v2)
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
    fn to_vec(list: Option<Box<ListNode>>) -> Vec<i32> {
        let mut v = Vec::new();
        let mut cur = list.as_ref();

        while let Some(node) = cur {
            v.push(node.val);
            cur = node.next.as_ref();
        }

        v
    }

    pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool {
        let mut v = Self::to_vec(head);
        let mut left = 0;
        let mut right = v.len() - 1;

        while left < right {
            if v[left] != v[right] {
                return false;
            }

            left = left + 1;
            right = right - 1;
        }

        true
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
    pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool {
        let mut slow = &head;
        let mut fast = &head;

        while let Some(node1) = fast {
            fast = &node1.next;
            if let Some(node2) = fast {
                fast = &node2.next;
                slow = &slow.as_ref().unwrap().next;
            }
        }

        let mut prev = None;
        let mut cur = slow.clone();
        while let Some(mut node) = cur {
            cur = node.next.take();
            node.next = prev;
            prev = Some(node);
        }

        let mut list = head;
        while let (Some(node1), Some(node2)) = (list, prev) {
            if node1.val != node2.val {
                return false;
            }

            list = node1.next;
            prev = node2.next;
        }

        true
    }
}
