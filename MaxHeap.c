#include <stdio.h>
#define MAX_SIZE 100

typedef struct
{
    int key;
}element;

typedef struct{
    element heap[MAX_SIZE];
    int size;
}Heap;

void max_heap_insert(Heap * h,element item)
{
    int i;
    i = ++(h->size);

    while(i != 1 && item.key > h->heap[i/2].key)
    {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }

    h -> heap[i] = item;
}

element max_heap_delete(Heap *h)
{
    int parent,child;
    element item,temp;

    item = h->heap[1];
    temp = h->heap[(h->size)--];
    parent = 1;
    child = 2;

    while(child <= h->size)
    {
        if((child < h->size) && ( (h->heap[child].key) < h->heap[child+1].key ))
        {
            child++;
        }

        if(temp.key >= h->heap[child].key)
        {
            break;
        }

        h->heap[parent] = h->heap[child];

        parent - child;
        child *= 2;
    }
    h->heap[parent] = temp;

    return item;
}

int main(void)
{

    return 0;
}