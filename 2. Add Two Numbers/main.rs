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
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut list1 = l1.clone();
        let mut list2 = l2.clone();
        let mut head1 = list1.as_mut();
        let mut head2 = list2.as_mut();
        let mut carry = 0;

        while head1 != None || head2 != None {
            let mut sum = carry;

            if let Some(node) = head1.as_ref() {
                sum += node.val;
            }

            if let Some(node) = head2.as_ref() {
                sum += node.val;
            }

            carry = sum / 10;

            if let Some(node) = head1 {
                node.val = sum % 10;

                if head2 == None && node.next == None {
                    if carry != 0 {
                        node.next = Some(Box::new(ListNode::new(carry)));
                    }

                    return list1;
                }

                head1 = node.next.as_mut();
            }

            if let Some(node) = head2 {
                node.val = sum % 10;

                if head1 == None && node.next == None {
                    if carry != 0 {
                        node.next = Some(Box::new(ListNode::new(carry)));
                    }

                    return list2;
                }

                head2 = node.next.as_mut();
            }
        }

        list1
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
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut dummy_head = Some(Box::new(ListNode::new(0)));
        let mut current_node = dummy_head.as_mut();
        let mut head1 = l1.as_ref();
        let mut head2 = l2.as_ref();
        let mut carry = 0;

        while head1 != None || head2 != None {
            let mut sum = carry;

            if let Some(node) = head1 {
                sum += node.val;
            }

            if let Some(node) = head2 {
                sum += node.val;
            }

            carry = sum / 10;

            if let Some(node) = current_node {
                node.next = Some(Box::new(ListNode::new(sum % 10)));
                current_node = node.next.as_mut();
            }

            if let Some(node) = head1 {
                head1 = node.next.as_ref();
            }

            if let Some(node) = head2 {
                head2 = node.next.as_ref();
            }
        }

        if carry != 0 {
            if let Some(node) = current_node {
                node.next = Some(Box::new(ListNode::new(carry)));
            }
        }

        dummy_head.unwrap().next
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
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut dummy_head = Some(Box::new(ListNode::new(0)));
        let mut current_node = dummy_head.as_mut();
        let mut head1 = l1.as_ref();
        let mut head2 = l2.as_ref();
        let mut carry = 0;

        while head1.is_some() || head2.is_some() || carry != 0 {
            let mut sum = carry;

            if let Some(node) = head1 {
                sum += node.val;
                head1 = node.next.as_ref();
            }

            if let Some(node) = head2 {
                sum += node.val;
                head2 = node.next.as_ref();
            }

            carry = sum / 10;

            if let Some(node) = current_node {
                node.next = Some(Box::new(ListNode::new(sum % 10)));
                current_node = node.next.as_mut();
            }
        }

        dummy_head.unwrap().next
    }
}
