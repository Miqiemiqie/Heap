//
// Created by 蒋兴宇 on 16/2/2023.
//

#include "Heap.h"

void HeapInit(HP* hp)
{
    hp->a = NULL;
    hp->size = 0;
    hp->capacity = 0;
}
void HeapPrint(HP* hp)
{
    for (int i = 0; i < hp->size; ++i) {
        printf("%d ", hp->a[i]);
    }
    printf("\n");
}
void HeapDestroy(HP* hp)
{
    free(hp->a);
    hp->capacity = hp->size = 0;
}
void swap(HPDataType* px, HPDataType* py)
{
    HPDataType tmp = *px;
    *px = *py;
    *py = tmp;
}
void UpperAdjust(HPDataType* a, int child)
{
    while (child > 0)
    {
        int parent = (child-1)/2;
        if (a[child] < a[parent])
        {
            swap(&a[parent], &a[child]);
            child = parent;
        }
        else {
            break;
        }
    }
}
void DownAdjust(HPDataType* a, int size, int parent)
{
    int child = parent * 2 + 1; //先默认child为左孩子
    while (child < size)
    {
        //先选出左有俩孩子中较大的那个
        if (a[child+1] > a[child] && child+1<size)
        {
            child++;
        }
        if (a[child] > a[parent])
        {
            swap(&a[child], &a[parent]);
            parent = child;
            child = child * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapPush(HP* hp, HPDataType x)
{
    assert(hp);
    //扩容
    if (hp->size == hp->capacity)
    {
        int newcapacity = hp->capacity==0?4:hp->capacity*2;
        HPDataType* tmp = realloc(hp->a, sizeof (HPDataType)*newcapacity);
        if (tmp == NULL)
        {
            printf("realloc fail");
            exit(-1);
        }
        hp->capacity = newcapacity;
        hp->a = tmp;
    }
    hp->a[hp->size] = x;
    hp->size++;
    //大堆的插入 实现顺序逻辑
    UpperAdjust(hp->a, hp->size-1);
}
void HeapPop(HP* hp)
{
    assert(hp);
    assert(!HeapIsEmpty(hp));
    swap(&hp->a[0],&hp->a[hp->size-1]);
    hp->size--;
    DownAdjust(hp->a, hp->size, 0);
}
bool HeapIsEmpty(HP* hp)
{
    assert(hp);
    return hp->size == 0;
}
int HeapSize(HP* hp)
{
    assert(hp);
    return hp->size;
}