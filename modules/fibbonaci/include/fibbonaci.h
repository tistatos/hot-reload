/**
* @file fibbonaci.h
* @author Erik Sandrén
* @date 05-12-2017
* @brief [Description Goes Here]
*/

#ifndef __FIBBONACI_H__
#define __FIBBONACI_H__

#include <inttypes.h>
#include <stdbool.h>

#define DNG_FIBBONACI_API_NAME "dng_fibbonaci_i"

struct dng_api_registry_i;

struct dng_fibbonaci_o {
	uint16_t current;
	uint16_t previous;
};

struct dng_fibbonaci_i {
	struct dng_fibbonaci_o* inst;

	uint16_t (*get_fibbonaci_number)(uint16_t *index);
	uint16_t (*get_next)(struct dng_fibbonaci_o* inst);
	void (*reset)(struct dng_fibbonaci_o* inst);
};

void load_fibbonaci(struct dng_api_registry_i *reg, bool reload);
void unload_fibbonaci(struct dng_api_registry_i *reg, bool reload);

#endif
