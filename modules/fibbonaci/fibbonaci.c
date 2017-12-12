#include "fibbonaci.h"
#include "api_registry.h"



uint16_t get_next(struct dng_fibbonaci_o* inst) {
	uint16_t current = inst->current;
	uint16_t prev = inst->previous;

	uint16_t res = prev + current;

	inst->previous = inst->current;
	inst->current = res;

	return res;
}

void load_fibbonaci(struct dng_api_registry_i *reg, bool reload) {
	struct dng_fibbonaci_i* fib = malloc(sizeof(struct dng_fibbonaci_i));
	fib->inst = malloc(sizeof(struct dng_fibbonaci_o));
	fib->inst->current = 1;
	fib->inst->previous = 0;
	fib->get_next = get_next;

	int first = fib->get_next(fib->inst);
	int next = fib->get_next(fib->inst);
	printf("%d\n", first);
	printf("%d\n", next);
}

/*void unload_fibbonaci(struct dng_api_registry_i *reg, bool reload) {*/
/*}*/
