#include <stdlib.h>
#include <stdio.h>

typedef struct dyn_array {
    int             capacity;
    int             size;
    int             *data;
} dyn_array_t;

dyn_array_t*
initArray(int capacity)
{
    dyn_array_t *p = (dyn_array_t *) malloc(sizeof(dyn_array_t));
    p->size = 0;
    p->capacity = capacity;
    p->data = malloc(capacity*sizeof(int));

    return p;
}

void
addElement(dyn_array_t * ar, int value)
{
    if ((ar->size)+1 > ar->capacity) {
        ar->capacity *=2;
        printf("increasing capacity to %d\n",ar->capacity);
        ar->data =  (int*)realloc(ar->data,ar->capacity*2*sizeof(int));
        if(ar->data == NULL)
        {
            printf("REALLOC FAILED!");
            return;
        }
    }
    ar->data[ar->size] = value;
    ar->size++;
}


void 
printArray(dyn_array_t * ar)
{
    printf("\n\nprinting array\n");
    printf("size: %d\n", ar->size);
    printf("capacity: %d\n", ar->capacity);
    if (ar->size == 0) {
        return;
    }
    int             i;
    for (i = 0; i < ar->size - 1; i++) {
        printf("%d, ", (ar->data)[i]);
    }
    printf("%d\n", (ar->data)[(ar->size) - 1]);
}


int 
main(int argc, char **args)
{
    const int max = 2147483647/4;

    dyn_array_t* ar = initArray(2);
    printf("capacity is %d\n\n", ar->capacity);
    for(int i =0;i<max;i++){
        addElement(ar,i);
    }

    printf("done growing\n");
    printf("capacity is %d\n\n", ar->capacity);
    printf("size is %d\n\n", ar->size);
    printf("ar->data[100]:%d\n",ar->data[100]);
    printf("ar->data[1000]:%d\n",ar->data[1000]);
    printf("ar->data[max-2]:%d\n",ar->data[max-2]);
    int x=0;
    scanf("%d",&x);
    free(ar->data);
    free(ar);
    return 0;
}
