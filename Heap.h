//
// Created by 蒋兴宇 on 16/2/2023.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef int HPDataType;
typedef struct Heap
{
    HPDataType* a;
    int size;
    int capacity;
}HP;

void HeapInit(HP* hp);
void HeapPrint(HP* hp);
void HeapDestroy(HP* hp);
void HeapPush(HP* hp, HPDataType x);
void HeapPop(HP* hp);
bool HeapIsEmpty(HP* hp);
int HeapSize(HP* hp);
void swap(HPDataType* px, HPDataType* py);

void UpperAdjust(HPDataType* a, int child);
void DownAdjust(HPDataType* a, int size, int parent);
#endif //HEAP_HEAP_H
