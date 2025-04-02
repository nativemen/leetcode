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
    pub fn rotate_right(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        if head.is_none() || head.as_ref().unwrap().next.is_none() || k == 0 {
            return head;
        }

        let mut count = 0;
        let mut node = head;
        let mut vec = Vec::new();

        while let Some(current) = node {
            vec.push(current.val);
            node = current.next;
            count += 1;
        }

        let shift = k as usize % count;
        vec.rotate_right(shift);

        let mut dummy = Some(Box::new(ListNode::new(0)));
        let mut node = dummy.as_mut();

        for val in vec {
            if let Some(current) = node {
                current.next = Some(Box::new(ListNode::new(val)));
                node = current.next.as_mut();
            }
        }

        dummy.unwrap().next
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
    pub fn rotate_right(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        let mut count = 0;
        let mut node = head.as_ref();

        while let Some(current) = node {
            node = current.next.as_ref();
            count += 1;
        }

        if count < 2 {
            return head;
        }

        let k = k as usize % count;

        if k == 0 {
            return head;
        }

        let mut i = 0;
        let mut new_head = None;
        let mut head = head;
        let mut node = head.as_mut();

        while let Some(current) = node {
            if i + k == count - 1 {
                new_head = current.next.take();
                break;
            } else {
                node = current.next.as_mut();
            }

            i += 1;
        }

        let mut node = new_head.as_mut();

        while let Some(current) = node {
            if current.next.is_none() {
                current.next = head;
                break;
            }

            node = current.next.as_mut();
        }

        new_head
    }
}
