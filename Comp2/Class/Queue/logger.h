#ifndef LOGGER_H
#define LOGGER_H

#define DEBUG 0
#define CRITICAL 1

#define LOG_DEBUG if (DEBUG) printf("DEBUG - "); if (DEBUG) printf
#define LOG_CRITICAL if (CRITICAL) printf("CRITICAL - "); if (CRITICAL) printf 


#endif