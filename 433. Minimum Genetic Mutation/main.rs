struct Solution;

use std::collections::HashMap;
use std::collections::HashSet;
use std::collections::VecDeque;

impl Solution {
    pub fn min_mutation(start_gene: String, end_gene: String, bank: Vec<String>) -> i32 {
        fn gene_to_hash(gene: &str) -> u16 {
            let mut hash = 0;
            let maps: HashMap<char, u16> =
                HashMap::from_iter(vec![('A', 0), ('C', 1), ('G', 2), ('T', 3)]);

            for c in gene.chars() {
                hash = (hash << 2) | maps[&c];
            }

            hash
        }

        fn find_mutations(gene_hash: u16) -> Vec<u16> {
            let mut gene_mutations = Vec::new();

            for i in 0..8 {
                let mask = 3 << (i * 2);

                for j in 0..4 {
                    let mutation = (gene_hash & !mask) | (j << (i * 2));

                    if mutation == gene_hash {
                        continue;
                    }

                    gene_mutations.push(mutation);
                }
            }

            gene_mutations
        }

        let end_gene_hash = gene_to_hash(&end_gene);
        let mut bank_hash_set: HashSet<u16> =
            HashSet::from_iter(bank.iter().map(|gene| gene_to_hash(gene)));
        let mut q = VecDeque::from_iter(vec![(gene_to_hash(&start_gene), 0)]);

        while !q.is_empty() {
            if let Some((current_hash, steps)) = q.pop_front() {
                if current_hash == end_gene_hash {
                    return steps;
                }

                let gene_mutations = find_mutations(current_hash);

                for mutation_hash in gene_mutations.into_iter() {
                    if !bank_hash_set.contains(&mutation_hash) {
                        continue;
                    }

                    q.push_back((mutation_hash, steps + 1));
                    bank_hash_set.remove(&mutation_hash);
                }
            }
        }

        -1
    }
}

use std::collections::HashSet;
use std::collections::VecDeque;

impl Solution {
    pub fn min_mutation(start_gene: String, end_gene: String, bank: Vec<String>) -> i32 {
        fn is_valid(s1: &str, s2: &str) -> bool {
            if s1.len() != s2.len() {
                return false;
            }

            s1.chars()
                .zip(s2.chars())
                .filter(|(c1, c2)| c1.ne(c2))
                .count()
                == 1
        }

        let mut visited = HashSet::new();
        let mut q = VecDeque::from_iter(
            bank.iter()
                .filter(|&gene| is_valid(&start_gene, &gene))
                .map(|gene| {
                    visited.insert(gene);
                    (gene, 1)
                }),
        );

        while !q.is_empty() {
            if let Some((current, steps)) = q.pop_front() {
                if end_gene.eq(current) {
                    return steps;
                }

                for gene in bank.iter() {
                    if !visited.contains(gene) && is_valid(&current, gene) {
                        q.push_back((gene, steps + 1));
                        visited.insert(gene);
                    }
                }
            }
        }

        -1
    }
}

use std::collections::HashSet;
use std::collections::VecDeque;

impl Solution {
    pub fn min_mutation(start_gene: String, end_gene: String, bank: Vec<String>) -> i32 {
        let bank_set: HashSet<String> = HashSet::from_iter(bank.into_iter());

        if !bank_set.contains(&end_gene) {
            return -1;
        }

        let mut q = VecDeque::from_iter(vec![(start_gene, 0)]);
        let mut visited: HashSet<String> = HashSet::new();
        let genes = vec!['A', 'C', 'G', 'T'];

        while !q.is_empty() {
            if let Some((current, steps)) = q.pop_front() {
                if end_gene.eq(&current) {
                    return steps;
                }

                let mut v = current.chars().collect::<Vec<_>>();
                for i in 0..v.len() {
                    let original = v[i];
                    for &c in genes.iter() {
                        v[i] = c;
                        let s = String::from_iter(v.iter());

                        if !visited.contains(&s) && bank_set.contains(&s) {
                            q.push_back((s.clone(), steps + 1));
                            visited.insert(s);
                        }
                    }
                    v[i] = original;
                }
            }
        }

        -1
    }
}
