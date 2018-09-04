#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>

#define COUNT_OF_ELEMENTS 8

uint32_t getHash(const char *key, const size_t key_len);
struct cell* initTable();
void addElementToHTable(char *str, int value, struct cell *HASH_TABLE);
void addElementToCell(int value, uint32_t localHash, struct cell *thisCell);
uint32_t* init_Uint32_tValue();
struct cell* initNextCell();
int getValue(uint32_t localHash, struct cell *HASH_TABLE);
int getCellValue(uint32_t localHash, struct cell *thisCell);
int* initIntValue();
void destructTable(struct cell *HASH_TABLE);
void destructCell(struct cell *thisCell);


struct cell
{
    int *value;
    uint32_t *localHash;
    struct cell *nextCell;
};
