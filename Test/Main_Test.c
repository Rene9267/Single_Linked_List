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

#pragma region POP_BOTTOM

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

#pragma region POP_TOP

CUNIT_TEST(Test_PoTopFromOneItem)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;
    const char *item = "Hello World";
    SLL_Append(&temp_list, (char *)item, sizeof(singly_node_t));

    // 2. stimolate
    singly_node_t *popped_node = SLL_PopTop(&temp_list);

    // 3. expectation
    const char *actual_value = popped_node->data;
    const char *expected_value = item;
    CUNIT_STRING_EQ(expected_value, actual_value); // check if remove correct item
    CUNIT_IS_NULL(temp_list);                      // check if the list is empty
}

CUNIT_TEST(Test_PopTopFromNullList)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;

    // 2. stimolate
    singly_node_t *popped_node = SLL_PopTop(&temp_list);

    // 3. expectation
    CUNIT_IS_NULL(temp_list);   // check if the list is empty
    CUNIT_IS_NULL(popped_node); // check if the popped node is empty
}

CUNIT_TEST(Test_PopTopFromTwoItems)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;
    const char *item_1 = "Hello World";
    const char *item_2 = "Hello Spank";
    SLL_Append(&temp_list, (char *)item_1, sizeof(singly_node_t));
    SLL_Append(&temp_list, (char *)item_2, sizeof(singly_node_t));

    // 2. stimolate
    singly_node_t *popped_node = SLL_PopTop(&temp_list);

    // 3. expectation
    CUNIT_STRING_EQ(item_1, (char *)popped_node->data); // check the popped item
    CUNIT_STRING_EQ(item_2, (char *)temp_list->data);   // check the remaining
}
#pragma endregion

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

#pragma region TEST_GET_TAIL

CUNIT_TEST(Test_GetTailEmpty)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;

    // 2. stimolate
    singly_node_t *last_node = SLL_GetTail(&temp_list);

    // 3. expectation
    CUNIT_IS_NULL(last_node);
}

CUNIT_TEST(Test_GetTailOneItem)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;
    const char *item = "Hello World";
    SLL_Append(&temp_list, (char *)item, sizeof(temp_list));

    // 2. stimolate
    singly_node_t *last_node = SLL_GetTail(&temp_list);

    // 3. expectation
    const char *actual_value = last_node->data;
    const char *expected_value = item;
    CUNIT_STRING_EQ(expected_value, actual_value);
}

CUNIT_TEST(Test_GetTailTwoItem)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;
    const char *item = "Hello World";
    const char *item2 = "Hello Spank";
    SLL_Append(&temp_list, (char *)item, sizeof(temp_list));
    SLL_Append(&temp_list, (char *)item2, sizeof(temp_list));

    // 2. stimolate
    singly_node_t *last_node = SLL_GetTail(&temp_list);

    // 3. expectation
    const char *actual_value = last_node->data;
    const char *expected_value = item2;
    CUNIT_STRING_EQ(expected_value, actual_value);
}

#pragma endregion

#pragma region TEST_LIST_LENGHT

CUNIT_TEST(Test_LenghEmptyList)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;

    // 2. stimolate
    int list_lengt = SLL_Lenght(&temp_list);

    // 3. expectation
    int actual_value = list_lengt;
    int expected_value = 1;
}

CUNIT_TEST(Test_LenghPopulatedList)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;
    const char *item = "Hello World";
    const char *item2 = "Hello Spank";
    SLL_Append(&temp_list, (char *)item, sizeof(temp_list));
    SLL_Append(&temp_list, (char *)item2, sizeof(temp_list));

    // 2. stimolate
    int list_lengt = SLL_Lenght(&temp_list);

    // 3. expectation
    int actual_value = list_lengt;
    int expected_value = 1;
}

#pragma endregion

#pragma region TEST_REVERT

CUNIT_TEST(Test_RevertThreeItemList)
{
    // 1. Setup scenario
    singly_node_t *temp_list = NULL;
    const char *item = "Hello World";
    const char *item2 = "Hello Spank";
    const char *item3 = "Hello It's Me";
    SLL_Append(&temp_list, (char *)item, sizeof(temp_list));
    SLL_Append(&temp_list, (char *)item2, sizeof(temp_list));
    SLL_Append(&temp_list, (char *)item3, sizeof(temp_list));

    // 2. stimolate
    singly_node_t *reverted_list = SLL_Revert(&temp_list);

    // 3. expectation
    // 1) element
    const char *actual_value = reverted_list->data;
    const char *expected_value = item3;
    CUNIT_STRING_EQ(expected_value, actual_value);

    // 2) element
    actual_value = reverted_list->linked_node->data;
    expected_value = item2;
    CUNIT_STRING_EQ(expected_value, actual_value);

    // 3) element
    actual_value = reverted_list->linked_node->linked_node->data;
    expected_value = item;
    CUNIT_STRING_EQ(expected_value, actual_value);
}

#pragma endregion
CUNIT_RUNNER(Test_GetTailEmpty, Test_RevertThreeItemList, Test_GetTailTwoItem, Test_GetTailOneItem, Test_AppendOneItem, Test_AppendMoreItem, Test_PopBottomFromOneItem, Test_PopBottomFromTwoItems, Test_RemoveFromEmptyList, Test_PoTopFromOneItem, Test_RemoveOutOfRangeItem, Test_RemoveFromOneItemList, Test_PopTopFromNullList, Test_RemoveFromTwoItemList, Test_PopTopFromTwoItems, Test_PopBottomFromNullList);
