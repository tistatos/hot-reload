/**
* @file main.c
* @author Erik Sandrén
* @date 05-12-2017
* @brief Main function file
*/


#include "api_registry.h"
#include "fibbonaci.h"
#include <stdlib.h>
#include <stdbool.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{

	struct dng_api_registry_i *dng_api = malloc(sizeof(struct dng_api_registry_i));

	void *fibbonaci_api = dlopen("./libdng_fibbonaci.so", RTLD_LAZY);
	char* errstr = dlerror();
	if (errstr == NULL) {
		void (*load_fibbonaci)(struct dng_api_registry_i*, bool) = dlsym(fibbonaci_api, "load_fibbonaci");

		(*load_fibbonaci)(dng_api, false);
	}
	else {
		printf ("A dynamic linking error occurred: (%s)\n", errstr);
	}

	free(dng_api);
	return 0;
}
