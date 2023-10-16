/*
**	Author: zerico2005 (2023)
**	Project: Struct-Splitter
**	License: MIT License
**	A copy of the MIT License should be included with
**	this project. If not, see https://opensource.org/license/MIT
*/

#ifndef SPLIT_DEF_H
#define SPLIT_DEF_H

/* Includes */

#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>

/* Constants */

#define STRUCT_SPLITTER_DATE "2023/10/16" /* YYYY/MM/DD */
#define STRUCT_SPLITTER_V_MAJOR 1
#define STRUCT_SPLITTER_V_MINOR 1
#define STRUCT_SPLITTER_V_PATCH 0

/* Macros */

#define STR_M(x) #x
#define STR_N(x) STR_M(x)

#define ARRAY_LENGTH(x) ( (sizeof(x[0]) != 0) ? (sizeof(x) / sizeof(x[0])) : 0 )
#define TEXT_LENGTH(x) ( (sizeof(x[0]) != 0) ? ( ((sizeof(x) / sizeof(x[0])) != 0) ? ((sizeof(x) / sizeof(x[0])) - 1) : 0 ) : 0 )
#define FREE(x) free(x); x = NULL

#define printF(...) printf(__VA_ARGS__); fflush(stdout)
#define printError(...) printf("\nError: "); printf(__VA_ARGS__); printf("\n"); fflush(stdout)

#define STRUCT_SPLITTER_VERSION STR_N(STRUCT_SPLITTER_V_MAJOR) "." STR_N(STRUCT_SPLITTER_V_MINOR) "." STR_N(STRUCT_SPLITTER_V_PATCH)

/* Languages */

#define lang_C 0
#define lang_CPP lang_C
#define lang_CPlusPlus lang_C

#define lang_JS 1
#define lang_JavaScript lang_JS

#define lang_Java 2

#define lang_CSharp 3
#define lang_CS lang_CSharp

#define lang_COUNT 4

#endif /* SPLIT_DEF_H */