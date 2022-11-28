#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#define NODE struct Node *
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
    void *data;
    NODE linked_node;
};

NODE Get_Tail(NODE *head)
{
    NODE current_node = *head;
    NODE last_node = NULL;
    while (current_node)
    {
        last_node = current_node;
        current_node = current_node->linked_node;
    }

    return last_node;
}

int Append(NODE *head, void *item)
{
    // save the code pointer in a ephermal NODE
    NODE current_node = Get_Tail(head);
    NODE appended_node = (NODE)malloc(sizeof(struct Node));
    NULL_CHECK(appended_node);
    // define the appended node
    appended_node->data = item;
    appended_node->linked_node = NULL;
    if (!current_node)
    {
        *head = appended_node;
        return 0;
    }
    // define the link at the appended node
    current_node->linked_node = appended_node;
    return 0;
}

void *Pop_First(NODE *head)
{
    if (!*head)
        return NULL;

    NODE current_node = *head;

    *head = (*head)->linked_node;
    current_node->linked_node = NULL;
    return current_node->data;
}

NODE Pop_Last(NODE *head)
{
    if (!*head)
        return NULL;
    NODE previous_node = *head;
    NODE current_node = *head;
    while (current_node->linked_node)
    {
        previous_node = current_node;
        current_node = current_node->linked_node;
    }
    previous_node->linked_node = NULL;
    // NODE ephe_data = current_node;
    // // free(current_node);
    // current_node = NULL;
    return current_node;
}

void *Remove(NODE *head, int index)
{
    NODE current_node = *head;
    NODE previous_node = *head;
    for (int i = 0; i <= index - 1; i++)
    {
        if (index == 0)
        {
            *head = current_node->linked_node;
            free(current_node);
            current_node = NULL;
            return NULL;
        }
        previous_node = current_node;
        current_node = current_node->linked_node;
    }

    previous_node->linked_node = current_node->linked_node;
    free(current_node);
    void *ephe_data = current_node->data;
    current_node = NULL;
    return ephe_data;
}

int LinkedListLenght(NODE *head)
{
    NODE temp = *head;
    int lenght = 1;
    while (temp->linked_node)
    {
        lenght++;
        temp = temp->linked_node;
    }
    return lenght;
}

NODE Revert(NODE *head)
{
    NODE *copy_node = head;
    NODE new_Linked = NULL;
    NODE Popped;
    int prova = LinkedListLenght(head);

    for (size_t i = 0; i < prova; i++)
    {
        Append(&new_Linked, (struct list_node *)Pop_Last(head)->data);
    }
    return new_Linked;
}

int main()
{
    NODE head = NULL;
    Append(&head, "Primo");
    Append(&head, "Secondo");
    Append(&head, "Terzo");
    Append(&head, "Quarto");
    Append(&head, "Quinto");
    Append(&head, "Sesto");
    Append(&head, "Last append");

    printf("%s\n", (char *)(head)->data);
    printf("Get Tail: %s\n", (char *)Get_Tail(&head)->data);
    printf("%s\n", (char *)Pop_First(&head));
    printf("%s\n", (char *)(head)->data);
    printf("Remove: %s\n", (char *)Remove(&head, 1));
    printf("%s\n", (char *)(head)->linked_node->data);
    printf("%s\n", (char *)(((struct list_node *)Pop_Last(&head)->data)));
    printf("%s\n", (char *)(((struct list_node *)Pop_Last(&head)->data)));

    NODE prova = head;
    while (prova)
    {
        printf("%s\n", (char *)prova->data);
        prova = prova->linked_node;
    }

    NODE reverted = Revert(&head);
    NODE Revert_head = reverted;
    while (Revert_head)
    {
        printf("%s\n", (char *)Revert_head->data);
        Revert_head = Revert_head->linked_node;
    }

    return 0;
}