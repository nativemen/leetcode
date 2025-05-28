use std::collections::HashMap;

struct Trie {
    children: HashMap<char, Trie>,
    is_end_of_word: bool,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Trie {
    fn new() -> Self {
        Self {
            children: HashMap::new(),
            is_end_of_word: false,
        }
    }

    fn insert(&mut self, word: String) {
        let mut node = self;

        for c in word.chars() {
            if !node.children.contains_key(&c) {
                node.children.entry(c).or_insert(Trie::new());
            }
            node = node.children.get_mut(&c).unwrap();
        }

        node.is_end_of_word = true;
    }

    fn search(&self, word: String) -> bool {
        let mut node = self;

        for c in word.chars() {
            if !node.children.contains_key(&c) {
                return false;
            }
            node = &node.children[&c];
        }

        return node.is_end_of_word;
    }

    fn starts_with(&self, prefix: String) -> bool {
        let mut node = self;

        for c in prefix.chars() {
            if !node.children.contains_key(&c) {
                return false;
            }
            node = &node.children[&c];
        }

        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * let obj = Trie::new();
 * obj.insert(word);
 * let ret_2: bool = obj.search(word);
 * let ret_3: bool = obj.starts_with(prefix);
 */


use std::collections::HashMap;

struct TrieNode {
    children: HashMap<char, TrieNode>,
    is_end_of_word: bool,
}

impl TrieNode {
    fn new() -> Self {
        Self {
            children: HashMap::new(),
            is_end_of_word: false,
        }
    }
}

struct Trie {
    root: TrieNode,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Trie {
    fn new() -> Self {
        Self {
            root: TrieNode::new(),
        }
    }

    fn insert(&mut self, word: String) {
        let mut node = &mut self.root;

        for c in word.chars() {
            if !node.children.contains_key(&c) {
                node.children.entry(c).or_insert(TrieNode::new());
            }
            node = node.children.get_mut(&c).unwrap();
        }

        node.is_end_of_word = true;
    }

    fn search(&self, word: String) -> bool {
        let mut node = &self.root;

        for c in word.chars() {
            if !node.children.contains_key(&c) {
                return false;
            }
            node = &node.children[&c];
        }

        return node.is_end_of_word;
    }

    fn starts_with(&self, prefix: String) -> bool {
        let mut node = &self.root;

        for c in prefix.chars() {
            if !node.children.contains_key(&c) {
                return false;
            }
            node = &node.children[&c];
        }

        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * let obj = Trie::new();
 * obj.insert(word);
 * let ret_2: bool = obj.search(word);
 * let ret_3: bool = obj.starts_with(prefix);
 */