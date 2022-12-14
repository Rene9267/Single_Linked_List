@echo off

if exist "bin" (
    RD /S /Q "bin"
)

MD "bin"
clang -o Bin\Single_Linked_List.exe -Iinclude Test\Main_Test.c Src\Singly_Linked_List.c
