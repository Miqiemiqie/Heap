#include "Heap.h"

void test1()
{
    //大堆
    HP hp;
    int a[] = {4,5,3,8,9,2};
    HeapInit(&hp);
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
        HeapPush(&hp,a[i]);
    }
    HeapPrint(&hp);
    HeapPop(&hp);
    HeapPrint(&hp);
    HeapPop(&hp);
    HeapPrint(&hp);
    HeapPop(&hp);
    HeapPrint(&hp);

    HeapDestroy(&hp);

}
void HeapSort(int* a, int n)
{
    //***********把a构建成小堆***********
    //方法1：
    /*for (int i = 1; i < n; ++i) {
        UpperAdjust(a, i);
    }*/
//    方法2：使用向下调整算法
//          向下调整算法前提：左右子树都是小/大堆那
//    叶子所在的子树不需要调，所以需要倒着从第一个非叶子节点的子树开始向下调整
//    类似递归，让他们从树底到树顶逐步成为小堆(如果需要构建成为小堆)
    for (int i = (n-1-1)/2; i >= 0; --i) {
        DownAdjust(a, n, i);
    }
    //***********把a排成升序***********
    /*for (int end = n-1; end >0 ; --end) {
        swap(&a[0], &a[end]);
        DownAdjust(a,end,0);
    }*/
    int end = n-1;
    while (end>0)
    {
        swap(&a[0], &a[end]);
        DownAdjust(a,end,0);
        end--;
    }
}

int main() {

    //test1();
    int a[] = {70,56,30,25,15,10,75,33,50,69};
    HeapSort(a,sizeof(a)/sizeof(a[0]));
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
        printf("%d ", a[i]);
    }

    return 0;
}