/**
* @file api_registry.h
* @author Erik Sandrén
* @date 05-12-2017
* @brief [Description Goes Here]
*/

#ifndef __API_REGISTRY_H__
#define __API_REGISTRY_H__


typedef void (*api_load_ptr)(struct dng_api_registry_i*, bool);


struct dng_api_node {
	void* api;
	void* interf;
	struct dng_api_node* next;
};

struct dng_api_registry_i {
	void (*add)(const char* name, void* interf);
	void (*remove)(void* interf);
	void *(*first)(const char* name);
	//void *(*next)(void* prev);
};

struct dng_api_registry_i* initializeRegistry();
void* load_api(struct dng_api_registry_i* api_registry, const char* api, const bool reload);

#endif
