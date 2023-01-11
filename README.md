# Singly Linked List
Implementing the Single Linked List structure for C language

**For compiling:**
```
- .\Build.bat

      or
      
- clang -o Bin\Single_Linked_List.exe -Iinclude Test\*.c Src\*.c
```

**Singly Linked List Functions:**
```

SLL_Lenght(singly_node_t **head)
  - Return the lenght of the given List
  
SLL_PopTop(singly_node_t **head)
  - Removes the first element in the list and return it
  
SLL_Revert(singly_node_t **head)
  - Revert the whole list, the first element became the last and so on, return the head of the new list

SLL_GetTail(singly_node_t **head)
  - Return the last added element in the list

SLL_PopBottom(singly_node_t **head)
  - Remove and return the last added element in the list
  
SLL_Remove(singly_node_t **head, int index)
  - Remove and return the element a the given index (the top of the list is index 0)
  
SLL_Append(singly_node_t **head, void *item, size_t struct_type)
  - Add an element at the end of the list, return 0 if the list was empty and the added element is the first, else return 1
  
```

Under the folder **Test** there is the "Main.c" file, wich contains the test for the Singly Linked List.
The tests are defined in regions divided by application functions. CUNIT_TEST is delegated the task of starting all the tests
