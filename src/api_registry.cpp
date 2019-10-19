/**
* @file api_registry.cpp
* @author Erik Sandrén
* @date 05-12-2017
* @brief keeps track of loaded apis
*/

#include "api_registry.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <unordered_map>

#include <dlfcn.h>

static std::unordered_map<std::string, void*> APIs;

std::string rename_dll(std::string name) {
	int r = rand() * 1000;
	std::string new_name = name.substr(0, name.length()-3);
	new_name.append(std::to_string(r) + ".so");
	rename(name.c_str(), new_name.c_str());

	return new_name;
}

void* load_api(struct dng_api_registry_i* api_registry, char const* name, const bool reload) {
	std::string moved_dll = rename_dll(name);

	void* api = dlopen(moved_dll.c_str(), RTLD_LAZY | RTLD_LOCAL);
	char* errstr = dlerror();
	if (errstr != NULL) {
		std::cout <<  "A dynamic linking error occurred: (" << errstr << ")" << std::endl;
		return NULL;
	}

	api_load_ptr load_fibbonaci = (api_load_ptr)dlsym(api, "load_fibbonaci");
	(*load_fibbonaci)(api_registry, reload);

	return api;
}

void add(const char *name, void *interf) {
	std::cout << "loaded: " << name << std::endl;

	//dng_api_node node;
	//node.api = interf;

	APIs[name] = interf;
}

void remove_api(void *interf) {
	free(interf);
}

void* first(const char* name) {
	void* ptr = (void*)APIs[name];
	return ptr;
}

void* next(void *prev) {
	struct dng_api_node* next_node = ((struct dng_api_node*)(prev))->next;
	return (void*)next_node;
}

struct dng_api_registry_i* initializeRegistry() {
	struct dng_api_registry_i* dng_api = (struct dng_api_registry_i*)malloc(sizeof(struct dng_api_registry_i));
	dng_api->add = add;
	dng_api->remove = remove_api;
	dng_api->first = first;
	//dng_api->next = next;

	return dng_api;
}
