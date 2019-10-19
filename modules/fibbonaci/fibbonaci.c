#include "fibbonaci.h"
#include "api_registry.h"

#include <stdio.h>
#include <stdlib.h>

uint16_t get_fibbonaci_number(uint16_t index) {
	uint16_t prev = 1;
	uint16_t current = 1;
	for (int i = 0; i < index; ++i) {
		uint16_t temp = current;
		current = prev + current;
		prev = temp;
	}
	return current;
}

uint16_t get_next(struct dng_fibbonaci_o* inst) {
	printf("Increasing the current value of the fibbonaci state...\n");
	uint16_t current = inst->current;
	uint16_t prev = inst->previous;

	uint16_t res = prev + current;

	inst->previous = inst->current;
	inst->current = res;

	return res;
}

uint16_t get_previous(struct dng_fibbonaci_o* inst) {
	printf("decreasing the value of fibbonaci...\n");
	printf("current %i previous %i...\n", inst->current, inst->previous);
	uint16_t current = inst->current;
	uint16_t prev = inst->previous;

	uint16_t res = current - prev;


	inst->previous = res;
	inst->current = prev;

	return prev;
}

void reset(struct dng_fibbonaci_o* inst) {
	inst->current = 1;
	inst->previous = 0;
}


void load_fibbonaci(struct dng_api_registry_i *reg, bool reload) {
	printf("loading fibbonaci\n");

	struct dng_fibbonaci_i* fib = (struct dng_fibbonaci_i*)malloc(sizeof(struct dng_fibbonaci_i));
	fib->inst = (struct dng_fibbonaci_o*)malloc(sizeof(struct dng_fibbonaci_o));
	/*fib->get_next = get_next;*/
	fib->get_next = get_previous;
	fib->reset = reset;

	if(!reload) {
		fib->reset(fib->inst);
	}
	else {
		struct dng_fibbonaci_i* prev = (struct dng_fibbonaci_i*)reg->first(DNG_FIBBONACI_API_NAME);
		fib->inst->current = prev->inst->current;
		fib->inst->previous = prev->inst->previous;

		unload_fibbonaci(reg, reload);
		reg->remove((void*)prev);
	}
	reg->add(DNG_FIBBONACI_API_NAME, (void*)fib);

}

void unload_fibbonaci(struct dng_api_registry_i *reg, bool reload) {
	printf("unloading fibbonaci\n");
	struct dng_fibbonaci_i* prev = (struct dng_fibbonaci_i*)reg->first(DNG_FIBBONACI_API_NAME);
	free(prev->inst);
}
