#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in the chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

/* install: put (name, defn) in hash table. */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* not found */
        np = malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else { /* already there*/
        free(np->defn);
    }
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

void remove_node(char *name) {
    struct nlist *prev_np, *np;
    unsigned hashval = hash(name);

    for (np = hashtab[hashval], prev_np = NULL; np != NULL; prev_np = np, np = np->next) {
        if (strcmp(name, np->name) == 0) { // found it.
            free(np->name);
            free(np->defn);
            if (prev_np == NULL) {
                hashtab[hashval] = np->next;
            } else {
                prev_np->next = np->next;
            }
            // free(np); //seg fault?
        }
    }
}

void print_table()
{
    for (int i = 0; i < HASHSIZE; i++) {
        int printed = 0;
        for (struct nlist *n = hashtab[i]; n != NULL; n = n->next) {
            printf("hash %d: <name-%s, def-%s> ", i, n->name, n->defn);
            printed = 1;
        }
        if (printed)
            putchar('\n');
    }
}

int main(int argc, char **argv)
{
    install("hello", "world");
    install("hello2", "world2");
    install("hello3", "world3");
    remove_node("hello3");
    struct nlist *val = lookup("hello");
    if (val)
        printf("%s\n", val->defn);

    print_table();
}
