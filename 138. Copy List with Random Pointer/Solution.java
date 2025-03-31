import java.util.HashMap;

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

/*
 * // Definition for a Node.
 * class Node {
 * int val;
 * Node next;
 * Node random;
 *
 * public Node(int val) {
 * this.val = val;
 * this.next = null;
 * this.random = null;
 * }
 * }
 */
class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        Node current = head;
        Node[] array = new Node[1001];
        int count = 0;

        while (current != null) {
            array[count] = new Node(current.val);
            count += 1;
            current = current.next;
        }

        current = head;
        int index = 0;

        while (current != null) {
            if (current.next != null) {
                array[index].next = array[index + 1];
            }
            if (current.random != null) {
                int idx = 0;
                Node node = head;

                while (node != current.random) {
                    node = node.next;
                    idx += 1;
                }

                array[index].random = array[idx];
            }

            index += 1;
            current = current.next;
        }

        return array[0];
    }
}

/*
 * // Definition for a Node.
 * class Node {
 * int val;
 * Node next;
 * Node random;
 *
 * public Node(int val) {
 * this.val = val;
 * this.next = null;
 * this.random = null;
 * }
 * }
 */
class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        Node current = head;

        while (current != null) {
            Node copy = new Node(current.val);
            copy.next = current.next;
            current.next = copy;
            current = copy.next;
        }

        current = head;
        while (current != null) {
            if (current.random != null) {
                current.next.random = current.random.next;
            }

            current = current.next.next;
        }

        current = head;
        Node newHead = head.next;

        while (current != null) {
            Node copy = current.next;
            current.next = copy.next;
            if (copy.next != null) {
                copy.next = copy.next.next;
            }
            current = current.next;
        }

        return newHead;
    }
}

/*
 * // Definition for a Node.
 * class Node {
 * int val;
 * Node next;
 * Node random;
 *
 * public Node(int val) {
 * this.val = val;
 * this.next = null;
 * this.random = null;
 * }
 * }
 */
class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        Map<Node, Node> maps = new HashMap<>();
        maps.put(null, null);
        Node current = head;

        while (current != null) {
            maps.put(current, new Node(current.val));
            current = current.next;
        }

        current = head;
        while (current != null) {
            maps.get(current).next = maps.get(current.next);
            maps.get(current).random = maps.get(current.random);
            current = current.next;
        }

        return maps.get(head);
    }
}

/*
 * // Definition for a Node.
 * class Node {
 * int val;
 * Node next;
 * Node random;
 *
 * public Node(int val) {
 * this.val = val;
 * this.next = null;
 * this.random = null;
 * }
 * }
 */
class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        Map<Node, Node> maps = new HashMap<>();
        Node current = head;

        while (current != null) {
            maps.put(current, new Node(current.val));
            current = current.next;
        }

        current = head;
        while (current != null) {
            if (current.next != null) {
                maps.get(current).next = maps.get(current.next);
            }

            if (current.random != null) {
                maps.get(current).random = maps.get(current.random);
            }

            current = current.next;
        }

        return maps.get(head);
    }
}

/*
 * // Definition for a Node.
 * class Node {
 * int val;
 * Node next;
 * Node random;
 *
 * public Node(int val) {
 * this.val = val;
 * this.next = null;
 * this.random = null;
 * }
 * }
 */
class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        Map<Node, Node> maps = new HashMap<>();
        maps.put(null, null);

        Node current = head;

        while (current != null) {
            if (!maps.containsKey(current)) {
                maps.put(current, new Node(current.val));
            }

            if (!maps.containsKey(current.next)) {
                maps.put(current.next, new Node(current.next.val));
            }
            maps.get(current).next = maps.get(current.next);

            if (!maps.containsKey(current.random)) {
                maps.put(current.random, new Node(current.random.val));
            }
            maps.get(current).random = maps.get(current.random);

            current = current.next;
        }

        return maps.get(head);
    }
}