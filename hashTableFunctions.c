#include "HashTable.h"

uint32_t getHash(const char *key, const size_t key_len)
{
    uint32_t hash, i;
    for (hash = i = 0; i < key_len; i++)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return abs(hash);
}

void addElementToHTable(char *str, int value, struct cell *HASH_TABLE)
{
    int hIndex = (getHash(str, strlen(str))) % COUNT_OF_ELEMENTS;
    addElementToCell(value, getHash(str, strlen(str)), &HASH_TABLE[hIndex]);
}

void addElementToCell(int value, uint32_t localHash, struct cell *thisCell)
{
    if(thisCell->value == NULL)
    {
        thisCell->value = initIntValue();
        thisCell->localHash = init_Uint32_tValue();
        *thisCell->value = value;
        *thisCell->localHash = localHash;
    }
    else if (thisCell->nextCell == NULL)
    {
        thisCell->nextCell = initNextCell();
        addElementToCell(value, localHash, thisCell->nextCell);
    }
    else
    {
        addElementToCell(value, localHash, thisCell->nextCell);
    }
}

int getValue(uint32_t localHash, struct cell *HASH_TABLE)
{
    if (HASH_TABLE[localHash % COUNT_OF_ELEMENTS].localHash == NULL)
    {
        printf("ERROR");
        return -1;
    }
    else
    {
        return getCellValue(localHash, &HASH_TABLE[localHash % COUNT_OF_ELEMENTS]);
    }
}

int getCellValue(uint32_t localHash, struct cell *thisCell)
{
    if (*thisCell->localHash == localHash)
    {
        return *thisCell->value;
    }
    else
    {
        return getCellValue(localHash, thisCell->nextCell);
    }
}

int* initIntValue()
{
    int *value = (int*)malloc(sizeof(int));
    return value;
}

uint32_t* init_Uint32_tValue()
{
    uint32_t *value = (uint32_t*)malloc(sizeof(uint32_t));
    return value;
}

struct cell* initNextCell()
{
    struct cell *nextCell = (struct cell*)malloc(sizeof(struct cell));
    return nextCell;
}

struct cell* initTable()
{
    struct cell *table = (struct cell*)malloc(COUNT_OF_ELEMENTS * sizeof(struct cell));
    return table;
}

void destructTable(struct cell *HASH_TABLE)
{
    for(int i = 0; i < COUNT_OF_ELEMENTS; i++)
    {
        destructCell(&HASH_TABLE[i]);
    }
    free(HASH_TABLE);
}

void destructCell(struct cell *thisCell)
{
    if(thisCell->value != NULL)
    {
        free(thisCell->value);
        free(thisCell->localHash);
        if (thisCell->nextCell != NULL)
        {
            destructCell(thisCell->nextCell);
        }
    }
}
