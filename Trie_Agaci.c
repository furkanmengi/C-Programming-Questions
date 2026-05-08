#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET];
    int isEndOfWord;

} TrieNode;

// Yeni düğüm oluştur
TrieNode* createNode()
{
    TrieNode *node =
        (TrieNode*)malloc(sizeof(TrieNode));

    node->isEndOfWord = 0;

    for(int i = 0; i < ALPHABET; i++)
    {
        node->children[i] = NULL;
    }

    return node;
}

// Kelime ekleme
void insert(TrieNode *root, char *word)
{
    TrieNode *temp = root;

    for(int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';

        if(temp->children[index] == NULL)
        {
            temp->children[index] = createNode();
        }

        temp = temp->children[index];
    }

    temp->isEndOfWord = 1;
}

// Kelime arama
int search(TrieNode *root, char *word)
{
    TrieNode *temp = root;

    for(int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';

        if(temp->children[index] == NULL)
        {
            return 0;
        }

        temp = temp->children[index];
    }

    return temp->isEndOfWord;
}

int main()
{
    TrieNode *root = createNode();

    insert(root, "cat");
    insert(root, "car");
    insert(root, "care");

    if(search(root, "car"))
    {
        printf("Kelime bulundu\n");
    }
    else
    {
        printf("Kelime bulunamadi\n");
    }

    return 0;
}
