use std::collections::HashMap;
use std::collections::HashSet;

impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut rows: HashMap<usize, HashSet<char>> = HashMap::new();
        let mut cols: HashMap<usize, HashSet<char>> = HashMap::new();
        let mut boxes: HashMap<usize, HashSet<char>> = HashMap::new();

        for row in 0..board.len() {
            for col in 0..board[row].len() {
                let c = board[row][col];
                if c == '.' {
                    continue;
                }

                let box_index = (row / 3) as usize * 3 + (col / 3) as usize;

                if (rows.get(&row).is_some() && rows.get(&row).unwrap().contains(&c))
                    || (cols.get(&col).is_some() && cols.get(&col).unwrap().contains(&c))
                    || (boxes.get(&box_index).is_some()
                        && boxes.get(&box_index).unwrap().contains(&c))
                {
                    return false;
                }

                rows.entry(row).or_insert(HashSet::new()).insert(c);
                cols.entry(col).or_insert(HashSet::new()).insert(c);
                boxes.entry(box_index).or_insert(HashSet::new()).insert(c);
            }
        }

        true
    }
}

use std::collections::HashSet;

impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut rows: Vec<HashSet<char>> = vec![HashSet::new(); board.len()];
        let mut cols: Vec<HashSet<char>> = vec![HashSet::new(); board.len()];
        let mut boxes: Vec<HashSet<char>> = vec![HashSet::new(); board.len()];

        for row in 0..board.len() {
            for col in 0..board[row].len() {
                let c = board[row][col];
                if c == '.' {
                    continue;
                }

                let box_index = (row / 3) as usize * 3 + (col / 3) as usize;

                if rows[row].contains(&c) || cols[col].contains(&c) || boxes[box_index].contains(&c)
                {
                    return false;
                }

                rows[row].insert(c);
                cols[col].insert(c);
                boxes[box_index].insert(c);
            }
        }

        true
    }
}
