#include <string.h>

#define CUNIT_TEST(name) void name()

#define CUNIT_STRING_EQ(expected, actual)                                                                       \
    if (strcmp(expected, actual) != 0)                                                                          \
    {                                                                                                           \
        printf("%s: expected [%s] but was [%s]. Errot at line:[%d]", __FUNCTION__, expected, actual, __LINE__); \
        exit(-1);                                                                                               \
    }

#define CUNIT_RUNNER(...)                           \
    int main()                                      \
    {                                               \
        void (*tests[])() = {__VA_ARGS__};          \
        int count = sizeof(tests) / sizeof(void *); \
        for (int i = 0; i < count; ++i)             \
        {                                           \
            tests[i]();                             \
        }                                           \
        printf("All [%d] Test passed!", count);     \
        return 0;                                   \
    }

