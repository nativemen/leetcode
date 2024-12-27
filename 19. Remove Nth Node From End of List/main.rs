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
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode::new(0));
        dummy.next = head;

        let mut fast = dummy.clone();
        for _ in 0..n {
            fast = fast.next.unwrap();
        }

        let mut slow = dummy.as_mut();
        while let Some(node) = fast.next {
            fast = node;
            slow = slow.next.as_mut().unwrap();
        }

        slow.next = slow.next.as_mut().unwrap().next.take();

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
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut fast = head.as_ref();

        for _ in 0..n {
            fast = fast.unwrap().next.as_ref();
        }

        if fast.is_none() {
            return head.unwrap().next;
        }

        let mut new_head = head.clone();
        let mut slow = new_head.as_mut().unwrap();
        while fast.unwrap().next.is_some() {
            fast = fast.unwrap().next.as_ref();
            slow = slow.next.as_mut().unwrap();
        }

        slow.next = slow.next.as_mut().unwrap().next.take();

        return new_head;
    }
}
