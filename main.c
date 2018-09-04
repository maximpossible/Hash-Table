#include "HashTable.h"

#define WIDTH 128

int main()
{
    struct cell *HASH_TABLE = initTable();
    char *str = (char*)malloc(WIDTH * sizeof(char));
    
    FILE *fin = fopen("data.txt", "r+");
    if (fin != NULL)
    {
        while (!feof(fin))
        {
            fgets(str, WIDTH, fin);
            char *buf, *value;
            value = strtok(str, " ");
            buf = (char*)malloc(strlen(value) * sizeof(char));
            strcpy(buf, value);
            value = strtok(NULL, " ");
            printf("%s  %d\n", buf, atoi(value));

            addElementToHTable(buf, atoi(value), HASH_TABLE);
        }
        fclose(fin);
    }
    
    return 0;
}
