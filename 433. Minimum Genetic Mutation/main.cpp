#include <cstdint>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    static constexpr size_t GENE_NUM = 8;
    static constexpr size_t GENE_OPTIONS = 4;
    static constexpr size_t GENE_MUTATION_SIZE = (GENE_OPTIONS - 1) * GENE_NUM;

    uint16_t gene2Hash(string gene) {
        uint16_t hash = 0;
        unordered_map<char, uint16_t> maps = {
                {'A', 0},
                {'C', 1},
                {'G', 2},
                {'T', 3},
        };

        for (const auto &c : gene) {
            hash = (hash << 2) | maps[c];
        }

        return hash;
    }

    void findGeneMutations(uint16_t geneHash, vector<uint16_t> &geneMutations) {
        size_t mutCount = 0;

        for (size_t i = 0; i < GENE_NUM; i++) {
            size_t mask = 3 << (i * 2);
            for (size_t j = 0; j < GENE_OPTIONS; j++) {
                uint16_t mutation = (geneHash & ~mask) | (j << (i * 2));

                if (mutation == geneHash) {
                    continue;
                }

                geneMutations[mutCount++] = mutation;
            }
        }
    }

public:
    int minMutation(string startGene, string endGene, vector<string> &bank) {
        uint16_t endGeneHash = gene2Hash(endGene);
        uint16_t q[1 << 16];
        size_t head = 0;
        size_t tail = 0;
        q[tail++] = gene2Hash(startGene);

        unordered_set<uint16_t> geneHashSet;
        for (const auto &gene : bank) {
            geneHashSet.emplace(gene2Hash(gene));
        }

        vector<uint16_t> geneMutations(GENE_MUTATION_SIZE);
        int steps = 0;

        while (head < tail) {
            size_t next = tail;

            for (size_t i = head; i < next; i++) {
                uint16_t current = q[i];

                if (current == endGeneHash) {
                    return steps;
                }

                findGeneMutations(current, geneMutations);
                for (const auto &mutation : geneMutations) {
                    if (!geneHashSet.contains(mutation)) {
                        continue;
                    }

                    q[tail++] = mutation;
                    geneHashSet.erase(geneHashSet.find(mutation));
                }
            }

            head = next;
            steps++;
        }

        return -1;
    }
};

class Solution {
    bool isValid(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        int diff = 0;

        for (size_t i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff++;
            }
        }

        if (diff == 1) {
            return true;
        }

        return false;
    }

public:
    int minMutation(string startGene, string endGene, vector<string> &bank) {
        vector<bool> used(bank.size(), false);
        queue<size_t> q;

        for (size_t i = 0; i < bank.size(); i++) {
            if (isValid(startGene, bank[i])) {
                q.push(i);
                used[i] = true;
            }
        }

        int steps = 0;

        while (!q.empty()) {
            steps++;

            int count = q.size();

            while (count > 0) {
                int index = q.front();
                q.pop();

                if (bank[index] == endGene) {
                    return steps;
                }

                for (size_t i = 0; i < bank.size(); i++) {
                    if (!used[i] && isValid(bank[index], bank[i])) {
                        used[i] = true;
                        q.push(i);
                    }
                }

                count--;
            }
        }

        return -1;
    }
};

class Solution {
    static constexpr size_t GENE_NUM = 8;

public:
    int minMutation(string startGene, string endGene, vector<string> &bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());

        if (!bankSet.contains(endGene)) {
            return -1;
        }

        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.emplace(startGene);

        vector<char> genes = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            if (current == endGene) {
                return steps;
            }

            for (int i = 0; i < GENE_NUM; i++) {
                char original = current[i];

                for (const auto &gene : genes) {
                    if (gene == original) {
                        continue;
                    }

                    current[i] = gene;

                    if (!visited.contains(current) && bankSet.contains(current)) {
                        visited.emplace(current);
                        q.push({current, steps + 1});
                    }
                }

                current[i] = original;
            }
        }

        return -1;
    }
};
