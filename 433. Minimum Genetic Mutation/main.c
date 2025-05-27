#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define GENE_NUM 8
#define GENE_OPTIONS 4
#define GENE_MUTATION_SIZE ((GENE_OPTIONS - 1) * GENE_NUM)

static uint16_t gene2Hash(const char *const gene) {
    const uint8_t geneMap[] = {
            ['A'] = 0,
            ['C'] = 1,
            ['G'] = 2,
            ['T'] = 3,
    };

    uint16_t hash = 0;

    for (size_t i = 0; i < strlen(gene); i++) {
        hash = (hash << 2) | geneMap[gene[i]];
    }

    return hash;
}

static void findGeneMutations(uint16_t geneHash, uint16_t *geneMutations, size_t mutSize) {
    size_t mutCount = 0;

    for (size_t i = 0; i < GENE_NUM; i++) {
        uint16_t mask = 3 << (i * 2);
        for (int j = 0; j < GENE_OPTIONS; j++) {
            uint16_t mutation = (geneHash & ~mask) | (j << (i * 2));

            if (mutation == geneHash) {
                continue;
            }

            geneMutations[mutCount++] = mutation;
        }
    }
}

int minMutation(char *startGene, char *endGene, char **bank, int bankSize) {
    bool geneHashSet[1 << 16] = {false};

    for (int i = 0; i < bankSize; i++) {
        geneHashSet[gene2Hash(bank[i])] = true;
    }

    uint16_t endGeneHash = gene2Hash(endGene);
    uint16_t geneMutations[GENE_MUTATION_SIZE];
    uint16_t q[1 << 16];
    int head = 0;
    int tail = 0;
    q[tail++] = gene2Hash(startGene);
    int steps = 0;

    while (head < tail) {
        int next = tail;
        for (int i = head; i < next; i++) {
            uint16_t current = q[i];

            if (current == endGeneHash) {
                return steps;
            }

            findGeneMutations(current, geneMutations, GENE_MUTATION_SIZE);
            for (int j = 0; j < GENE_MUTATION_SIZE; j++) {
                if (!geneHashSet[geneMutations[j]]) {
                    continue;
                }

                q[tail++] = geneMutations[j];
                geneHashSet[geneMutations[j]] = false;
            }
        }

        head = next;
        steps++;
    }

    return -1;
}

#define QUEUE_SIZE (1 << 16)

static bool isValid(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    if (len1 != len2) {
        return false;
    }

    size_t diff = 0;

    for (size_t i = 0; i < len1; i++) {
        if (s1[i] != s2[i]) {
            diff++;
        }
    }

    if (diff == 1) {
        return true;
    }

    return false;
}

int minMutation(char *startGene, char *endGene, char **bank, int bankSize) {
    int q[QUEUE_SIZE];
    int head = 0;
    int tail = 0;
    int used[bankSize + 1];

    for (int i = 0; i < bankSize; i++) {
        used[i] = false;
        if (isValid(startGene, bank[i])) {
            used[i] = true;
            q[tail++] = i;
        }
    }

    int steps = 0;

    while (head < tail) {
        steps++;

        int next = tail;

        for (int i = head; i < next; i++) {
            int index = q[i];

            if (strcmp(bank[index], endGene) == 0) {
                return steps;
            }

            for (int j = 0; j < bankSize; j++) {
                if (!used[j] && isValid(bank[index], bank[j])) {
                    used[j] = true;
                    q[tail++] = j;
                }
            }
        }

        head = next;
    }

    return -1;
}