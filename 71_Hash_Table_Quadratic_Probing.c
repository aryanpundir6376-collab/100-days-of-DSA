#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define DELETED -2

int hash(int key, int m) {
    return key % m;
}

// Insert function
void insert(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY || table[index] == DELETED) {
            table[index] = key;
            printf("Inserted %d at index %d\n", key, index);
            return;
        }
        i++;
    }

    printf("Hash Table is Full\n");
}

// Search function
void search(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }

        i++;
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;

    printf("Enter size of hash table: ");
    scanf("%d", &m);

    int table[m];

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    printf("Enter number of operations: ");
    scanf("%d", &q);

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        printf("\nEnter operation (INSERT/SEARCH) and key: ");
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(table, m, key);
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            search(table, m, key);
        } 
        else {
            printf("Invalid operation\n");
        }
    }

    return 0;
}