#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Node singly_node;

#define NULL_CHECK(item)                           \
    {                                              \
        if (!item)                                 \
        {                                          \
            printf("Unable to allocate memory\n"); \
            return -1;                             \
        }                                          \
    }

struct Node
{
    singly_node *linked_node;
    void *data;
};

singly_node *Get_Tail(singly_node **head)
{
    if (!*head)
        return NULL;
        
    singly_node *current_node = *head;
    singly_node *last_node = NULL;
    while (current_node)
    {
        last_node = current_node;
        current_node = current_node->linked_node;
    }

    return last_node;
}

int Append(singly_node **head, void *item, size_t struct_type)
{
    singly_node *current_node = Get_Tail(head);
    singly_node *appended_node = malloc(struct_type);
    NULL_CHECK(appended_node);
    appended_node->data = item;
    appended_node->linked_node = NULL;
    if (!current_node)
    {
        *head = appended_node;
        printf("I added an element at the begin :%s\n\n", (char *)item);

        return 0;
    }
    current_node->linked_node = appended_node;
    return 1;
}

singly_node *Pop_First(singly_node **head)
{
    if (!*head)
        return NULL;

    singly_node *current_node = *head;

    *head = (*head)->linked_node;
    current_node->linked_node = NULL;
    return current_node;
}

singly_node *Pop_Last(singly_node **head)
{
    if (!*head)
        return NULL;

    singly_node *previous_node = *head;
    singly_node *current_node = *head;
    while (current_node->linked_node)
    {
        previous_node = current_node;
        current_node = current_node->linked_node;
    }
    previous_node->linked_node = NULL;

    return current_node;
}

singly_node *Remove(singly_node **head, int index)
{
    singly_node *current_node = *head;
    singly_node *previous_node = *head;
    if (index == 0)
    {
        Pop_First(head);
        return current_node;
    }

    for (int i = 0; i < index; i++)
    {
        previous_node = current_node;
        current_node = current_node->linked_node;
        if (!current_node)
        {
            printf("Index out of range");
            return NULL;
        }
    }

    previous_node->linked_node = current_node->linked_node;
    return current_node;
}

int Linked_List_Lenght(singly_node **head)
{
    singly_node *temp = *head;
    int lenght = 1;
    while (temp->linked_node)
    {
        lenght++;
        temp = temp->linked_node;
    }
    return lenght;
}

singly_node *Revert(singly_node **head)
{
    singly_node **copy_node = head;
    singly_node *new_linked = NULL;
    singly_node *popped_item;
    int prova = Linked_List_Lenght(head);

    for (size_t i = 0; i < prova; i++)
    {
        Append(&new_linked, (struct list_node *)Pop_Last(head)->data, sizeof(singly_node));
    }
    return new_linked;
}

#pragma region Main
// int main()
// {
//     singly_node * head = NULL;
//     Append(&head, "Primo");
//     Append(&head, "Secondo");
//     Append(&head, "Terzo");
//     Append(&head, "Quarto");
//     Append(&head, "Quinto");
//     Append(&head, "Sesto");
//     Append(&head, "Last append");

//     printf("%s\n", (char *)(head)->data);
//     printf("Get Tail: %s\n", (char *)Get_Tail(&head)->data);
//     printf("%s\n", (char *)Pop_First(&head));
//     printf("%s\n", (char *)(head)->data);
//     printf("Remove: %s\n", (char *)Remove(&head, 0));
//     printf("%s\n", (char *)(head)->linked_node->data);
//     printf("%s\n", (char *)(((struct list_node *)Pop_Last(&head)->data)));
//     printf("%s\n", (char *)(((struct list_node *)Pop_Last(&head)->data)));

//     singly_node * prova = head;
//     while (prova)
//     {
//         printf("%s\n", (char *)prova->data);
//         prova = prova->linked_node;
//     }

//     singly_node * reverted = Revert(&head);
//     singly_node * Revert_head = reverted;
//     while (Revert_head)
//     {
//         printf("%s\n", (char *)Revert_head->data);
//         Revert_head = Revert_head->linked_node;
//     }

//     return 0;
// }
#pragma endregion