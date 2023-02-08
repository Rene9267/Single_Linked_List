@echo off

if exist "Bin" (
    RD /S /Q "Bin"
)

MD "Bin"
clang -o Bin\Single_Linked_List.exe -Iinclude Test\*.c Src\*.c
.\Bin\Single_Linked_List.exe