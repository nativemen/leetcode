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
    pub fn pair_sum(head: Option<Box<ListNode>>) -> i32 {
        let mut array = Vec::new();
        let mut current = head;

        while let Some(node) = current {
            array.push(node.val);
            current = node.next;
        }

        let mut left = 0;
        let mut right = array.len() - 1;
        let mut max_sum = 0;

        while left < right {
            max_sum = max_sum.max(array[left] + array[right]);
            left += 1;
            right -= 1;
        }

        max_sum
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
    pub fn pair_sum(head: Option<Box<ListNode>>) -> i32 {
        let mut slow = head.as_ref();
        let mut fast = head.as_ref();

        while fast.is_some() && fast.unwrap().next.is_some() {
            slow = slow.unwrap().next.as_ref();
            fast = fast.unwrap().next.as_ref().unwrap().next.as_ref();
        }

        let mut second = slow.cloned();
        let mut prev = None;

        while let Some(mut node) = second {
            let next = node.next.take();
            node.next = prev;
            prev = Some(node);
            second = next;
        }

        let mut max_sum = 0;
        let mut list1 = head.as_ref();
        let mut list2 = prev.as_ref();

        while let (Some(node1), Some(node2)) = (list1, list2) {
            max_sum = max_sum.max(node1.val + node2.val);
            list1 = node1.next.as_ref();
            list2 = node2.next.as_ref();
        }

        max_sum
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
    pub fn pair_sum(head: Option<Box<ListNode>>) -> i32 {
        let mut current = head.as_ref();
        let mut count = 0;

        while current.is_some() {
            count += 1;
            current = current.unwrap().next.as_ref();
        }

        let mut head = head;
        let mut prev = None;
        let mut next = None;

        for _ in 0..count / 2 {
            if let Some(mut node) = head {
                next = node.next.take();
                node.next = prev;
                prev = Some(node);
                head = next;
            }
        }

        let mut max_sum = 0;

        while let (Some(node1), Some(node2)) = (prev, head) {
            max_sum = max_sum.max(node1.val + node2.val);
            prev = node1.next;
            head = node2.next;
        }

        max_sum
    }
}
