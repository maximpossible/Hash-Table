#include "HashTable.h"

#define WIDTH 128

int main()
{
    //const char *str = "hash-tablica";
    struct cell *HASH_TABLE = initTable();

    //addElementToHTable("tn", 10, HASH_TABLE);

    // printf("HASH: %d", getHash(str, strlen(str)));
    // printf("\n\nmain  %d", *HASH_TABLE[3].value);
    addElementToCell(12,  getHash("tk", strlen("tk")),&HASH_TABLE[3]);
    //printf("\n\nmain  %d", *HASH_TABLE[3].nextCell->value);



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
            //printf("%d\n", getValue(getHash(buf, strlen(buf)), HASH_TABLE));
        }
        fclose(fin);
    }



    // addElementToHTable("t1", atoi(buf), HASH_TABLE);
    // printf("%d\n", getValue(getHash("t1", 2), HASH_TABLE));

//    addElementToHTable("n", 20, HASH_TABLE);
//    addElementToHTable("tn", 1, HASH_TABLE);
//    addElementToHTable("tk", 50, HASH_TABLE);
//    addElementToHTable("u1", 44, HASH_TABLE);
//    addElementToHTable("u2", 54, HASH_TABLE);
//    addElementToHTable("Uvx1", 56, HASH_TABLE);
//    addElementToHTable("Uvx2", 60, HASH_TABLE);
//    addElementToHTable("r1", 4, HASH_TABLE);
//    addElementToHTable("r2", 8, HASH_TABLE);
//    addElementToHTable("r3", 5, HASH_TABLE);
//    addElementToHTable("r4", 10, HASH_TABLE);
//    addElementToHTable("t1", 10, HASH_TABLE);
//    addElementToHTable("t2", 20, HASH_TABLE);
//    addElementToHTable("t5", 1, HASH_TABLE);
//    addElementToHTable("t6", 2, HASH_TABLE);
//    addElementToHTable("t7", 3, HASH_TABLE);
//    addElementToHTable("t8", 4, HASH_TABLE);
//    addElementToHTable("t9", 6, HASH_TABLE);


//   printf("\n\n%d\n", getHash("n", 1) % COUNT_OF_ELEMENTS);
//     printf("hash = %d\n", getHash("t7", 2)% COUNT_OF_ELEMENTS );
//    printf("%d\n", getHash("u2", 2)% COUNT_OF_ELEMENTS);




    printf("\n\n\n%d", getValue(getHash("n", 1), HASH_TABLE));
    printf("\n%d", getValue(getHash("tn", 2), HASH_TABLE));
    printf("\n%d\n\n\n", getValue(getHash("tk", 2), HASH_TABLE));
    printf("\n%d", getValue(getHash("u1", 2), HASH_TABLE));
    printf("\n%d", getValue(getHash("u2", 2), HASH_TABLE));
    printf("\n%d", getValue(getHash("Uvx1", 4), HASH_TABLE));
    printf("\n%d", getValue(getHash("Uvx2", 4), HASH_TABLE));
    printf("\n%d", getValue(getHash("r1", 2), HASH_TABLE));
    printf("\n%d", getValue(getHash("r2", 2), HASH_TABLE));
    printf("\n%d", getValue(getHash("r3", 2), HASH_TABLE));
    printf("\n%d", getValue(getHash("r4", 2), HASH_TABLE));
    printf("\n%d", getValue(getHash("t1", 2), HASH_TABLE));
    printf("\n%d", getValue(getHash("t2", 2), HASH_TABLE));
    printf("\n%d", getValue(getHash("t5", 2), HASH_TABLE));
    printf("\n%d", getValue(getHash("t6", 2), HASH_TABLE));
    printf("\n%d", getValue(getHash("t7", 2), HASH_TABLE));
    printf("\n%d", getValue(getHash("t8", 2), HASH_TABLE));
    printf("\n%d", getValue(getHash("t9", 2), HASH_TABLE));

//printf("\n\n%d", *HASH_TABLE[7].localHash);
//printf("\n\n%d", *HASH_TABLE[7].nextCell->localHash);

    //printf("%d", *HASH_TABLE[7].value);

   // destructTable(HASH_TABLE);

    return 0;
}
