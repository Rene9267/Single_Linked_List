#include <Singly_Linked_List.h>

#define NULL_CHECK(item)                           \
    {                                              \
        if (!item)                                 \
        {                                          \
            printf("Unable to allocate memory\n"); \
            return -1;                             \
        }                                          \
    }

singly_node_t *SLL_GetTail(singly_node_t **head)
{
    if (!head || !*head)
        return NULL;

    singly_node_t *current_node = *head;
    singly_node_t *last_node = NULL;
    while (current_node)
    {
        last_node = current_node;
        current_node = current_node->linked_node;
    }

    return last_node;
}

int SLL_Append(singly_node_t **head, void *item, size_t struct_type)
{
    singly_node_t *current_node = SLL_GetTail(head);
    singly_node_t *appended_node = malloc(struct_type);
    NULL_CHECK(appended_node);
    appended_node->data = item;
    appended_node->linked_node = NULL;
    if (!current_node)
    {
        *head = appended_node;
        // printf("I added an element at the begin :%s\n\n", (char *)item);
        return 0;
    }
    current_node->linked_node = appended_node;
    return 1;
}

singly_node_t *SLL_PopTop(singly_node_t **head)
{
    if (!head || !*head)
        return NULL;

    singly_node_t *current_node = *head;

    *head = (*head)->linked_node;
    current_node->linked_node = NULL;
    return current_node;
}

singly_node_t *SLL_PopBottom(singly_node_t **head)
{
    if (!head || !*head)
        return NULL;

    // Linked list with one item
    singly_node_t *current_node = *head;
    if (!current_node->linked_node)
    {
        *head = (*head)->linked_node;
        current_node->linked_node = NULL;
        return current_node;
    }

    // Linked list with 2 or more items
    singly_node_t *previous_node = *head;
    while (current_node->linked_node)
    {
        previous_node = current_node;
        current_node = current_node->linked_node;
    }

    previous_node->linked_node = NULL;
    return current_node;
}

int Linked_List_Lenght(singly_node_t **head)
{
    if (!head || !*head)
        return 0;

    singly_node_t *temp = *head;
    int lenght = -1;
    while (temp)
    {
        lenght++;
        if (!temp->linked_node)
            return lenght;
        temp = temp->linked_node;
    }
    return lenght;
}

singly_node_t *SLL_Remove(singly_node_t **head, int index)
{
    if (!head || !*head)
        return NULL;

    singly_node_t *current_node = *head;
    singly_node_t *previous_node = *head;

    if (index == 0)
    {
        return SLL_PopTop(head);
    }

    for (int i = 0; i < index; ++i)
    {
        previous_node = current_node;
        current_node = current_node->linked_node;
        if (!current_node)
            return NULL;
    }

    previous_node->linked_node = current_node->linked_node;
    return current_node;
}

singly_node_t *Revert(singly_node_t **head)
{
    singly_node_t **copy_node = head;
    singly_node_t *new_linked = NULL;
    singly_node_t *popped_item;
    int prova = Linked_List_Lenght(head);

    for (size_t i = 0; i < prova; i++)
    {
        SLL_Append(&new_linked, (struct list_node *)SLL_PopBottom(head)->data, sizeof(singly_node_t));
    }
    return new_linked;
}
