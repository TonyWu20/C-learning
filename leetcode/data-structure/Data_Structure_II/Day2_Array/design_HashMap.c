#include <stdio.h>
#include <stdlib.h>

struct HashObj
{
    int value;
    int mapped;
};
typedef struct
{
    struct HashObj *a;
} MyHashMap;

MyHashMap *myHashMapCreate()
{
    MyHashMap *obj = malloc(sizeof(*obj));
    obj->a = calloc(100000, sizeof(struct HashObj));
    return obj;
}

void myHashMapPut(MyHashMap *obj, int key, int value)
{
    obj->a[key].value = value;
    obj->a[key].mapped = 1;
}

int myHashMapGet(MyHashMap *obj, int key)
{
    return (obj->a[key].mapped) ? obj->a[key].value : -1;
}

void myHashMapRemove(MyHashMap *obj, int key)
{
    obj->a[key].mapped = 0;
}

void myHashMapFree(MyHashMap *obj)
{
    free(obj->a);
    free(obj);
}
