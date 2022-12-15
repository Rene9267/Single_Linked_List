#include <SLL_Cunit.h>
#include <Singly_Linked_List.h>

#pragma region TEST_APPEND_ITEM

CUNIT_TEST(Test_AppendOneItem)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;
    const char *item = "Hello World";

    // 2. stimolate
    SLL_Append(&temp_list, (char *)item, sizeof(singly_node_t));

    // 3. expectation
    const char *actual_value = temp_list->data;
    const char *expected_value = item;

    CUNIT_STRING_EQ(expected_value, actual_value);
}

CUNIT_TEST(Test_AppendMoreItem)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;
    const char *item_1 = "Hello World";
    const char *item_2 = "Hello Spank";

    // 2. stimolate
    SLL_Append(&temp_list, (char *)item_1, sizeof(singly_node_t));
    SLL_Append(&temp_list, (char *)item_2, sizeof(singly_node_t));

    // 3. expectation
    // 1) element
    const char *actual_value = temp_list->data;
    const char *expected_value = item_1;
    CUNIT_STRING_EQ(expected_value, actual_value);

    // 2) element
    actual_value = temp_list->linked_node->data;
    expected_value = item_2;
    CUNIT_STRING_EQ(expected_value, actual_value);
}

#pragma endregion

#pragma region TEST_POP_ITEM

CUNIT_TEST(Test_PopBottomFromOneItem)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;
    const char *item = "Hello World";
    SLL_Append(&temp_list, (char *)item, sizeof(singly_node_t));

    // 2. stimolate
    singly_node_t *popped_node = SLL_PopBottom(&temp_list);

    // 3. expectation
    const char *actual_value = popped_node->data;
    const char *expected_value = item;
    CUNIT_STRING_EQ(expected_value, actual_value); // check if remove correct item
    CUNIT_IS_NULL(temp_list);                      // check if the list is empty
}

CUNIT_TEST(Test_PopBottomFromNullList)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;

    // 2. stimolate
    singly_node_t *popped_node = SLL_PopBottom(&temp_list);

    // 3. expectation
    CUNIT_IS_NULL(temp_list);   // check if the list is empty
    CUNIT_IS_NULL(popped_node); // check if the popped node is empty
}

CUNIT_TEST(Test_PopBottomFromTwoItems)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;
    const char *item_1 = "Hello World";
    const char *item_2 = "Hello Spank";
    SLL_Append(&temp_list, (char *)item_1, sizeof(singly_node_t));
    SLL_Append(&temp_list, (char *)item_2, sizeof(singly_node_t));

    // 2. stimolate
    singly_node_t *popped_node = SLL_PopBottom(&temp_list);

    // 3. expectation
    CUNIT_STRING_EQ(item_2, (char *)popped_node->data); // check the popped item
    CUNIT_STRING_EQ(item_1, (char *)temp_list->data);   // check the remaining
}

#pragma endregion

#pragma region TEST_REMOVE_ITEM

CUNIT_TEST(Test_RemoveFromEmptyList)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;

    // 2. stimolate
    singly_node_t *removed_node = SLL_Remove(&temp_list, 0);

    // 3. expectation
    CUNIT_IS_NULL(temp_list);    // check if the list is empty
    CUNIT_IS_NULL(removed_node); // check if the removed node is empty
}

CUNIT_TEST(Test_RemoveOutOfRangeItem)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;
    const char *item_1 = "Hello World";
    SLL_Append(&temp_list, (char *)item_1, sizeof(temp_list));

    // 2. stimolate
    singly_node_t *removed_node = SLL_Remove(&temp_list, 2);

    // 3. expectation
    CUNIT_IS_NULL(removed_node); // check if the removed node is empy

    const char *actual_value = temp_list->data;
    const char *expected_value = item_1;
    CUNIT_STRING_EQ(expected_value, actual_value); // check is the remaining item is invariate
}

CUNIT_TEST(Test_RemoveFromOneItemList)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;
    const char *item_1 = "Hello World";
    SLL_Append(&temp_list, (char *)item_1, sizeof(temp_list));

    // 2. stimolate
    singly_node_t *removed_node = SLL_Remove(&temp_list, 0);

    // 3. expectation
    CUNIT_IS_NULL(temp_list); // check if the list is empty

    const char *actual_value = removed_node->data;
    const char *expected_value = item_1;
    CUNIT_STRING_EQ(expected_value, actual_value); // check is the removed item is correct
}

CUNIT_TEST(Test_RemoveFromTwoItemList)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;
    const char *item_1 = "Hello World";
    const char *item_2 = "Hello Spank";
    SLL_Append(&temp_list, (char *)item_1, sizeof(temp_list));
    SLL_Append(&temp_list, (char *)item_2, sizeof(temp_list));

    // 2. stimolate
    singly_node_t *removed_1_node = SLL_Remove(&temp_list, 0);
    singly_node_t *removed_2_node = SLL_Remove(&temp_list, 0);

    // 3. expectation
    CUNIT_IS_NULL(temp_list); // check if the list is empty

    const char *actual_value = removed_1_node->data;
    const char *expected_value = item_1;
    CUNIT_STRING_EQ(expected_value, actual_value); // check is the removed item is correct
    actual_value = removed_2_node->data;
    expected_value = item_2;
    CUNIT_STRING_EQ(expected_value, actual_value); // check is the removed 2 item is correct
}

#pragma endregion

CUNIT_RUNNER(Test_AppendOneItem, Test_AppendMoreItem, Test_PopBottomFromOneItem, Test_PopBottomFromNullList, Test_PopBottomFromTwoItems, Test_RemoveFromEmptyList, Test_RemoveOutOfRangeItem, Test_RemoveFromOneItemList, Test_RemoveFromTwoItemList);
// int main()
// {
//     // singly_node_t * head = NULL;
//     // Append(&head, "Primo");
//     // Append(&head, "Secondo");
//     // Append(&head, "Terzo");
//     // Append(&head, "Quarto");
//     // Append(&head, "Quinto");
//     // Append(&head, "Sesto");
//     // Append(&head, "Last append");

//     // printf("%s\n", (char *)(head)->data);
//     // printf("Get Tail: %s\n", (char *)Get_Tail(&head)->data);
//     // printf("%s\n", (char *)Pop_First(&head));
//     // printf("%s\n", (char *)(head)->data);
//     // printf("Remove: %s\n", (char *)Remove(&head, 0));
//     // printf("%s\n", (char *)(head)->linked_node->data);
//     // printf("%s\n", (char *)(((struct list_node *)Pop_Last(&head)->data)));
//     // printf("%s\n", (char *)(((struct list_node *)Pop_Last(&head)->data)));

//     // singly_node_t * prova = head;
//     // while (prova)
//     // {
//     //     printf("%s\n", (char *)prova->data);
//     //     prova = prova->linked_node;
//     // }

//     // singly_node_t * reverted = Revert(&head);
//     // singly_node_t * Revert_head = reverted;
//     // while (Revert_head)
//     // {
//     //     printf("%s\n", (char *)Revert_head->data);
//     //     Revert_head = Revert_head->linked_node;
//     // }

//     return 0;
// }