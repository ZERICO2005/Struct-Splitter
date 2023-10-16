#ifndef INPUT_H
#define INPUT_H
#include "Split_Def.h"

/* Step 0: Configure some parameters by commenting/uncommenting #defines out */

	#define Confirm_that_variable_names_are_legal_C_variable_names /* You may need to reconfigure this function to your specifications */
//	#define Print_JS_Arrays
//	#define Automatically_insert_data_types
	#define Print_spaces_after_commas
//	#define Print_array_elements_on_separate_lines

/* Step 1: Define the struct */
struct _Input_Struct {
	
}; typedef struct _Input_Struct Input_Struct;

/* Step 2: How should each element be printed */
const char* Input_Type[] = {
	
};

/* Step 3: What each parrell array should be called */
const char* Input_Name[] = {
	
};

/* Step 4: Insert struct data below */
const Input_Struct Input_Data[] = {
	
};

/* Step 5: Save, compile, and run bin/Split.exe */

/*
**	printf formatting on 64bit Windows
**
**	char "%c"
**	char* "%s"
**	
**	int8_t "%hhd"
**	int16_t "%hd"
**	int32_t "%d"
**	int64_t "%lld"
**	
**	uint8_t "%hhu"
**	uint16_t "%hu"
**	uint32_t "%u"
**	uint64_t "%llu"
**	size_t "%llu"
**	
**	float "%f"
**	double "%lf"
*/

#endif /* SPLIT_DEF_H */