/**
* @file main.cpp
* @author Erik Sandrén
* @date 05-12-2017
* @brief Main function file
*/

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <dlfcn.h>
#include <iostream>
#include <unistd.h>

#include "api_registry.h"

#include "fibbonaci.h"

static struct dng_api_registry_i* dng_api = initializeRegistry();

int main(int argc, char *argv[])
{
	srand(0);
	// Load fibbonacci api
	void* fib_api = load_api(dng_api, "./libdng_fibbonaci_i.so",false);


	while(true) {
		//Get the api from registry
		struct dng_fibbonaci_i* fibb = (struct dng_fibbonaci_i*)dng_api->first(DNG_FIBBONACI_API_NAME);
		//Loop output
		uint16_t f = fibb->get_next(fibb->inst);
		std::cout << "next fibbonaci number is: " << f << std::endl;
		sleep(1);


		//FIXME: move this code to api.registry
		if(std::fstream("./libdng_fibbonaci_i.so")) {
			std::cout << "reloading fibbonaci..." << std::endl;
			dlclose(fib_api);
			fibb = (struct dng_fibbonaci_i*)dng_api->first(DNG_FIBBONACI_API_NAME);
		}
	}

	free(dng_api);
	return 0;
}
