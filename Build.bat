@echo off

if exist "Bin" (
    RD /S /Q "Bin"
)

MD "Bin"
clang -o Bin\Single_Linked_List.exe -Iinclude Test\Main_Test.c Src\Single_Linked_List.c
