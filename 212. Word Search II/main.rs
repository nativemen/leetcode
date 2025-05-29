struct Solution;

use std::collections::HashMap;

struct Trie {
    children: HashMap<char, Trie>,
    is_end_of_word: bool,
}

impl Trie {
    pub fn new() -> Self {
        Self {
            children: HashMap::new(),
            is_end_of_word: false,
        }
    }

    pub fn insert_trie(&mut self, word: &str) {
        let mut node = self;

        for c in word.chars() {
            if !node.children.contains_key(&c) {
                node.children.entry(c).or_insert(Trie::new());
            }

            node = node.children.get_mut(&c).unwrap();
        }

        node.is_end_of_word = true;
    }
}

const WORD_LEN: usize = 10;

impl Solution {
    pub fn find_words(board: Vec<Vec<char>>, words: Vec<String>) -> Vec<String> {
        fn dfs(
            board: &mut Vec<Vec<char>>,
            i: i32,
            j: i32,
            word: &str,
            root: &mut Trie,
            result: &mut Vec<String>,
        ) {
            let row_size = board.len() as i32;
            let col_size = board[0].len() as i32;

            if i < 0
                || i >= row_size
                || j < 0
                || j >= col_size
                || word.len() > WORD_LEN
                || board[i as usize][j as usize] == '*'
                || !root.children.contains_key(&board[i as usize][j as usize])
            {
                return;
            }

            let original = board[i as usize][j as usize];
            let mut word = word.to_string();
            word.push(original);
            board[i as usize][j as usize] = '*';

            let mut root = root.children.get_mut(&original).unwrap();

            if root.is_end_of_word {
                result.push(word.clone());
                root.is_end_of_word = false;
            }

            dfs(board, i + 1, j, &word, root, result);
            dfs(board, i - 1, j, &word, root, result);
            dfs(board, i, j + 1, &word, root, result);
            dfs(board, i, j - 1, &word, root, result);

            board[i as usize][j as usize] = original;
            word.pop();
        }

        let mut root = Trie::new();

        for word in words.into_iter() {
            root.insert_trie(&word);
        }

        let mut board = board;
        let row_size = board.len() as i32;
        let col_size = board[0].len() as i32;
        let word = "";
        let mut result = Vec::new();

        for i in 0..row_size {
            for j in 0..col_size {
                dfs(&mut board, i, j, word, &mut root, &mut result);
            }
        }

        result
    }
}

use std::collections::HashMap;
use std::collections::HashSet;

struct Trie {
    children: HashMap<char, Trie>,
    is_end_of_word: bool,
}

impl Trie {
    pub fn new() -> Self {
        Self {
            children: HashMap::new(),
            is_end_of_word: false,
        }
    }

    pub fn insert_trie(&mut self, word: &str) {
        let mut node = self;

        for c in word.chars() {
            if !node.children.contains_key(&c) {
                node.children.entry(c).or_insert(Trie::new());
            }

            node = node.children.get_mut(&c).unwrap();
        }

        node.is_end_of_word = true;
    }
}

const WORD_LEN: usize = 10;

impl Solution {
    pub fn find_words(board: Vec<Vec<char>>, words: Vec<String>) -> Vec<String> {
        fn dfs(
            board: &mut Vec<Vec<char>>,
            i: i32,
            j: i32,
            word: &str,
            root: &Trie,
            result: &mut HashSet<String>,
        ) {
            let row_size = board.len() as i32;
            let col_size = board[0].len() as i32;

            if i < 0
                || i >= row_size
                || j < 0
                || j >= col_size
                || word.len() > WORD_LEN
                || board[i as usize][j as usize] == '*'
                || !root.children.contains_key(&board[i as usize][j as usize])
            {
                return;
            }

            let original = board[i as usize][j as usize];
            let mut word = word.to_string();
            word.push(original);
            board[i as usize][j as usize] = '*';

            let root = root.children.get(&original).unwrap();

            if root.is_end_of_word {
                result.insert(word.clone());
            }

            dfs(board, i + 1, j, &word, root, result);
            dfs(board, i - 1, j, &word, root, result);
            dfs(board, i, j + 1, &word, root, result);
            dfs(board, i, j - 1, &word, root, result);

            board[i as usize][j as usize] = original;
            word.pop();
        }

        let mut root = Trie::new();

        for word in words.into_iter() {
            root.insert_trie(&word);
        }

        let mut board = board;
        let row_size = board.len() as i32;
        let col_size = board[0].len() as i32;
        let word = "";
        let mut result = HashSet::new();

        for i in 0..row_size {
            for j in 0..col_size {
                dfs(&mut board, i, j, word, &root, &mut result);
            }
        }

        result.into_iter().collect::<Vec<String>>()
    }
}
