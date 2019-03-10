#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100
struct tnode {                // узел дерева
    char *word;                  // указатель на строку (слово)
    int count;                   // число вхождений
    struct tnode *left;          // левый потомок
    struct tnode *right;         // правый потомок
};
// Функция добавления узла к дереву
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;
    if(p == nullptr) {
        p = (struct tnode *)malloc(sizeof(struct tnode));
        p->word = _strdup(w);
        p->count = 1;
        p->left = p->right = nullptr;
    } else if((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if(cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}
// Функция удаления поддерева
void freemem(tnode *tree) {
    if(tree!=nullptr) {
        freemem(tree->left);
        freemem(tree->right);
        free(tree);
    }
}
// Функция вывода дерева
void treeprint(struct tnode *p) {
    if(p != nullptr) {
        treeprint(p->left);
        printf("%d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}
int main() {
    struct tnode *root;
    char word[MAXWORD];
    root = nullptr;
    do {
        scanf_s("%s",word);
        if(isalpha(word[0]))
            root = addtree(root, word);
    }while(word[0]!='0');    // условие выхода – ввод символа ‘0’
    treeprint(root);
    freemem(root);
    getchar();
    getchar();
    return 0;
}