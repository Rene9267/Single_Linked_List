#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Node singly_node_t;
enum Type
{
    INT,
    STRING,
    CHAR,
    DOBULE,
    FLOAT,
    UINT64,
    LAST_TYPE
};

int SLL_Append(singly_node_t **head, void *item, size_t struct_type);
singly_node_t *SLL_PopBottom(singly_node_t **head);
singly_node_t *SLL_Remove(singly_node_t **head, int index);
singly_node_t *SLL_PopTop(singly_node_t **head);
singly_node_t *SLL_GetTail(singly_node_t **head);
int SLL_Lenght(singly_node_t **head);

struct Node
{
    singly_node_t *linked_node;
    void *data;
    enum Type data_type;
};
