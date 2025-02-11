#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_alpha(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool is_digit(char ch)
{
    return ch >= '0' && ch <= '9';
}

bool is_alnum_or_underscore(char ch)
{
    return is_alpha(ch) || is_digit(ch) || ch == '_';
}

bool is_valid_multidimensional_array(const char *declaration)
{
    const char *valid_types[] = {"int", "float", "double", "char", "long"};
    int num_valid_types = sizeof(valid_types) / sizeof(valid_types[0]);

    char buffer[256];
    strncpy(buffer, declaration, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    size_t len = strlen(buffer);
    if (len < 2 || buffer[len - 1] != ';')
    {
        return false;
    }

    buffer[len - 1] = '\0';

    char *token = strtok(buffer, " ");

    bool valid_type = false;
    for (int i = 0; i < num_valid_types; ++i)
    {
        if (strcmp(token, valid_types[i]) == 0)
        {
            valid_type = true;
            break;
        }
    }
    if (!valid_type)
    {
        return false;
    }

    token = strtok(NULL, "[");
    if (token == NULL || !is_alpha(token[0]))
    {
        return false;
    }
    for (int i = 1; token[i] != '\0'; ++i)
    {
        if (!is_alnum_or_underscore(token[i]))
        {
            return false;
        }
    }

    while ((token = strtok(NULL, "]")) != NULL)
    {
        if (token[0] != '[')
        {
            return false;
        }
        for (int i = 1; token[i] != '\0'; ++i)
        {
            if (!is_digit(token[i]))
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{

    char user_input[256];
    printf("Enter a multi-dimensional array declaration: ");
    if (fgets(user_input, sizeof(user_input), stdin) != NULL)
    {
        // Remove trailing newline
        size_t len = strlen(user_input);
        if (len > 0 && user_input[len - 1] == '\n')
        {
            user_input[len - 1] = '\0';
        }

        if (is_valid_multidimensional_array(user_input))
        {
            printf("Valid array declaration.\n");
        }
        else
        {
            printf("Invalid array declaration.\n");
        }
    }

    return 0;
}
