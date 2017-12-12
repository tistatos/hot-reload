/**
* @file api_registry.h
* @author Erik Sandrén
* @date 05-12-2017
* @brief [Description Goes Here]
*/

#ifndef __API_REGISTRY_H__
#define __API_REGISTRY_H__

struct dng_api_registry_i {
	void (*add)(const char *name, void *interf);
	void (*remove)(void *interf);
	void *(*first)(const char *name);
	void *(*next)(void *prev);
};

#endif
