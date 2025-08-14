#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

typedef struct {
    char *memory_pool; 
    char *current_pos; 
    char *previous[128]; 
    int prev_arr_in; 
    size_t pool_size; 
} stackAllocator; 

int stackInit(stackAllocator* allocator, size_t size, char* data); 
void* stackAlloc(stackAllocator* allocator, size_t size); 
void stackDealloc(stackAllocator* allocator); 
void stackReset(stackAllocator* allocator); 

static size_t SIZE = 128; // in bytes

int main(int argc, char *argv[]) {
    char data[SIZE];
    stackAllocator allocator; 
    stackInit(&allocator, SIZE, data); 
    char input = '!'; 
    while (input != 'q') {
        printf("Allocate (a), Deallocate (d), Quit (q), Reset (r): "); 
        scanf(" %c", &input); 
        if (input == 'a') {
            int bytes = 0; 
            while (bytes <= 0) {
                printf("How many bytes do you want to allocate (1 <= bytes)? "); 
                scanf("%d", &bytes); 
            }
            size_t ubytes = bytes; 
            stackAlloc(&allocator, ubytes); 
        } else if (input == 'r') {
            stackReset(&allocator); 
        } else if (input == 'q') {
            return 0; 
        } else if (input == 'd') {
            stackDealloc(&allocator); 
        } else {
            printf("Invalid Input - Try Again\n");
        }
    }
    return 0; 
}

int stackInit(stackAllocator* allocator, size_t size, char* data) {
    allocator->memory_pool = data; 
    allocator->current_pos = data; 
    allocator->pool_size = size; 
    allocator->prev_arr_in = 0;
    printf("Initialized.\n"); 
    printf("Pool Size: %zu; Memory Pool: %p; Current: %p\n", size, data, data); 
    return 0; 
}

void* stackAlloc(stackAllocator* allocator, size_t size) {
    if (allocator->pool_size - (allocator->current_pos - allocator->memory_pool) < size) {
        printf("\nNot enough memory in pool\n\n"); 
        return NULL; 
    } else if (size <= 0) {
        printf("\nCannot allocate less than 1 byte of memory\n\n");
        return NULL; 
    } else {
        allocator->previous[allocator->prev_arr_in] = allocator->current_pos; 
        allocator->prev_arr_in ++; 
        char* temp = allocator->current_pos;
        allocator->current_pos += size; 
        printf("\nAllocated %zu bytes of memory.\n", size); 
        printf("Pool Size: %zu; Memory Pool: %p; Current: %p\n", allocator->pool_size, allocator->memory_pool, allocator->current_pos); 
        printf("Used %zu bytes of memory\n\n", allocator->current_pos - allocator->memory_pool);
        return temp; 
    }
}

void stackDealloc(stackAllocator* allocator) {
    if (allocator->prev_arr_in == 0) {
        printf("\nNo memory allocated\n\n"); 
        return; 
    }
    char* temp = allocator->current_pos;
    allocator->prev_arr_in--;
    allocator->current_pos = allocator->previous[allocator->prev_arr_in]; 
    size_t size = temp - allocator->previous[allocator->prev_arr_in];
    printf("\nDeallocated %zu bytes of memory.\n", size); 
    printf("Pool Size: %zu; Memory Pool: %p; Current: %p\n", allocator->pool_size, allocator->memory_pool, allocator->current_pos); 
    printf("Used %zu bytes of memory\n\n", allocator->current_pos - allocator->memory_pool);
}

void stackReset(stackAllocator* allocator) {
    allocator->current_pos = allocator->memory_pool; 
    allocator->prev_arr_in = 0; 
    printf("\nMemory Reset\n"); 
    printf("Pool Size: %zu; Memory Pool: %p; Current: %p\n\n", allocator->pool_size, allocator->memory_pool, allocator->current_pos); 
}
