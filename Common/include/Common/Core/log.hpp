#pragma once
// Logging
//
// Used for debugging and logging
//

#include <iostream>

//
// cerr is used for errors & non verbose info
// clog is used for the console
//


// Defined (or not) in the .in file by cmake
#define BTDAPI_LOG_METHODS
/* #undef BTDAPI_LOG_METHODS_VERBOSE */
#define BTDAPI_LOG_LOADING
#define BTDAPI_LOG_DEBUG
#define BTDAPI_LOG_WARNING
#define BTDAPI_LOG_INFO
#define BTDAPI_LOG_VERBOSE


#define PRINTE(x) (std::cerr << x << std::endl)
#define PRINTL(x) (std::clog << x << std::endl)

//
// All these log varients do the same thing, just a way of controlling the level of info you want
// at compile time. Log is still supported
//
// Message style used:
//
// INFO: FooBar
// WARNING: FooBar
// ERROR: FooBar
//
// If the info is externel, Eg Windows/Vulkan giving you the info
//
// WININFO: FooBar
// VKERROR: FooBar
//

// LOGM -	Method Log.		Eg: in foo.bar()		LOGM("INFO: Doing foo.bar")		(Executing a method)
// LOGMV -	Verbose Method Log.

// LOGL -	Loading Log.	Eg: in foo.init()		LOGS("INFO: Loading foo")		(Loading a component)
// LOGD -	Debug Log.		Eg: in foo.bar(int x)	LOGD("DEBUG: x = " << x)		(Printing values wihout a debugger)
// LOGW -	Warning Log.	Eg:	in foo.bar(int x)	LOGD("WARNING: x > 100.")		(Unexpected or potentially problematic behaviour)
// LOGI -	Info Log.		Eg: in foo.bar()		LOGL("INFO: foobar enabled")	(General information)


// LOGV -	Vebose Log.		Eg:	in foo.bar()		LOGV("INFO: The weather is sunny today")
// LOGV if it doesn't fall under any of these catagoeries

// LOGE -	Logs Error.	Eg: in foo.bar()		PERR("ERROR: No foo detected!")		(Crash with info)
// LOGE will throw an exception when called

// Avoid using this, this will always be logged.
//#define LOG(x) (PRINTE(x))

#if defined(BTDAPI_LOG_METHODS)
#define LOGM(x) (PRINTE(x))
#else
#define LOGM(x) ((void)0)
#endif

#if defined(BTDAPI_LOG_METHODS_VERBOSE)
#define LOGMV(x) (PRINTE(x))
#else
#define LOGMV(x) ((void)0)
#endif

#if defined(BTDAPI_LOG_LOADING)
#define LOGL(x) (PRINTE(x))
#else
#define LOGL(x) ((void)0)
#endif

#if defined(BTDAPI_LOG_DEBUG)
#define LOGD(x) (PRINTE(x))
#else
#define LOGD(x) ((void)0)
#endif

#if defined(BTDAPI_LOG_WARNING)
#define LOGW(x) (PRINTE(x))
#else
#define LOGW(x) ((void)0)
#endif

#if defined(BTDAPI_LOG_INFO)
#define LOGI(x) (PRINTE(x))
#else
#define LOGI(x) ((void)0)
#endif

#if defined(BTDAPI_LOG_VERBOSE)
#define LOGV(x) (PRINTE(x))
#else
#define LOGV(x) ((void)0)
#endif

#define LOGE(x) { \
PRINTE(x);\
throw std::exception("Error!");\
}
// The above exception should hopefully crash the program.
