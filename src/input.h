#ifndef INPUT_H
#define INPUT_H
#include "Split_Def.h"



/* Step 0: Configure some parameters by commenting/uncommenting #defines out */
	/* Supported languages: lang_C, lang_CPP, lang_Java, lang_JS, lang_CSharp */
	#define Print_Language lang_C
	/* Data Types */
//	#define Use_const_type
	#define Automatically_insert_data_types
	#define Use_stdint_data_types /* C and CPP Only */
//	#define Use_var_instead_of_let /* JS Only */
	/* Formatting */
	#define Confirm_that_variable_names_are_legal_C_variable_names /* You may need to reconfigure this function to your specifications */
	#define Print_spaces_after_commas
//	#define Print_array_elements_on_separate_lines

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

#endif /* SPLIT_DEF_H */