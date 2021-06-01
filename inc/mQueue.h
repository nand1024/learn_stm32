#ifndef __MQUEUE_H__
    #define __MQUEUE_H__
	//#define MALLOC_USE 1
    #include <stdlib.h>
    #include <stdint.h>

#ifndef MALLOC_USE
	#define SIZE_QUEUE 255
#endif

    typedef uint8_t memType;

    typedef struct virtual_memory{
        uint16_t sizeFull;      //
        uint16_t maxSize;
        uint16_t index_write;
        uint16_t index_read;
#ifdef MALLOC_USE
        memType *mem_Array;
#else
        memType mem_Array[SIZE_QUEUE];
#endif

    }type_virt_mem;

    typedef struct virtual_memory_array{
        uint8_t size;
        type_virt_mem *v_mem_arr;
    }type_v_mem_array;

    uint16_t next_index_circle(uint16_t index, uint16_t min_ind, uint16_t max_ind);
	#ifdef MALLOC_USE
    type_virt_mem* queue_init(uint8_t amountVirtMems, uint16_t sizeVirtMem);

	#else
    void queue_init(type_virt_mem *queueMemory);
	#endif
    uint16_t queue_put_data(memType *data, uint16_t size, type_virt_mem* mem_struct);
    uint16_t queue_get_data(memType *data, uint16_t size, type_virt_mem* mem_struct);


#endif
