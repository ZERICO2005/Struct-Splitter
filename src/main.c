/*
**	Author: zerico2005 (2023)
**	Project: Struct-Splitter
**	License: MIT License
**	A copy of the MIT License should be included with
**	this project. If not, see https://opensource.org/license/MIT
*/

#include "Split_Def.h"
#include "input.h"

/* Sets Print_Language to lang_C if it is not defined or set */
#ifndef Print_Language
	#define Print_Language lang_C
#endif
#if ~(~Print_Language + 0) == 0 && ~(~Print_Language + 1)
	#undef Print_Language
	#define Print_Language lang_C
#endif

size_t Input_Struct_Size = sizeof(Input_Struct);
size_t Input_Struct_Len = 0; /* Set as part of the input validation process */
size_t Input_Type_Size = sizeof(Input_Type);
size_t Input_Type_Len = ARRAY_LENGTH(Input_Type);
size_t Input_Name_Size = sizeof(Input_Name);
size_t Input_Name_Len = ARRAY_LENGTH(Input_Name);
size_t Input_Data_Size = sizeof(Input_Data);
size_t Input_Data_Len = ARRAY_LENGTH(Input_Data);

int containsText(const char* strA, size_t lenA, const char* strB, size_t lenB) {
	//printF("\n%s %s | %llu %llu",strA,strB,lenA,lenB);
	if (lenA == 0 || lenB == 0) {
		return 0;
	}
	if (lenA < lenB) {
		return 0;
	}
	size_t posA = 0;
	size_t posB = 0;
	while (1) {
		if (strA[posA] == '\0' || strB[posB] == '\0') {
			break;
		}
		if (strA[posA] == strB[posB]) {
			posB++;
		} else {
			posB = 0;
		}
		if (posB == lenB) {
			return 1;
		}
		posA++;
	}
	return 0;
}

int checkVariableName(const char* name) {
	size_t i = 0;
	while (name[i] != '\0') { /* Checks that the variable name contains at least one valid variable name letter */
		if (
			(name[i] >= '0' && name[i] <= '9') ||
			(name[i] >= 'A' && name[i] <= 'Z') ||
			(name[i] >= 'a' && name[i] <= 'z') ||
			(name[i] == '_')
		) {
			return 0;
		}
		i++;
	}
	printError("Invalid variable name \"%s\"",name);
	return -1;
} 

size_t getTypeLength(const char* t) {
	#define conText(a,b) containsText(a,strlen(a),b,TEXT_LENGTH(b))
	size_t formatCount = 0;
	size_t i = 0;
	while (t[i] != '\0') { // Counts the amount of % symbols in the type
		if (t[i] == '%') {
			formatCount++;
		}
		i++;
	}
	if (formatCount != 1) {
		return 0;
	}
	/*
	if (formatCount == 0) {
		printError("No format specified in \"%s\"",t);
		return 0;
	} else (formatCount > 1) {
		printError("Cannot get type length from multiple formats in \"%s\"",t);
		return 0;
	}
	*/
	if (conText(t,"s")) { return sizeof(char*); }
	if (conText(t,"c")) { return sizeof(char); }
	if (conText(t,"p")) { return sizeof(void*); }
	/* decimal */
	if (conText(t,"hhd")) { return sizeof(char); }
	if (conText(t,"lld")) { return sizeof(long long); }
	if (conText(t,"hd")) { return sizeof(short); }
	if (conText(t,"ld")) { return sizeof(long); }
	if (conText(t,"d")) { return sizeof(int); }
	/* integer */
	if (conText(t,"hhi")) { return sizeof(signed char); }
	if (conText(t,"lli")) { return sizeof(signed long long); }
	if (conText(t,"hi")) { return sizeof(signed short); }
	if (conText(t,"li")) { return sizeof(signed long); }
	if (conText(t,"i")) { return sizeof(signed int); }
	/* unsigned */
	if (conText(t,"hhu")) { return sizeof(unsigned char); }
	if (conText(t,"llu")) { return sizeof(unsigned long long); }
	if (conText(t,"hu")) { return sizeof(unsigned short); }
	if (conText(t,"lu")) { return sizeof(unsigned long); }
	if (conText(t,"u")) { return sizeof(unsigned int); }
	/* octal */
	if (conText(t,"hho")) { return sizeof(unsigned char); }
	if (conText(t,"llo")) { return sizeof(unsigned long long); }
	if (conText(t,"ho")) { return sizeof(unsigned short); }
	if (conText(t,"lo")) { return sizeof(unsigned long); }
	if (conText(t,"o")) { return sizeof(unsigned int); }
	/* HEXADECIMAL */
	if (conText(t,"hhX")) { return sizeof(unsigned char); }
	if (conText(t,"llX")) { return sizeof(unsigned long long); }
	if (conText(t,"hX")) { return sizeof(unsigned short); }
	if (conText(t,"lX")) { return sizeof(unsigned long); }
	if (conText(t,"X")) { return sizeof(unsigned int); }
	/* hexadecimal */
	if (conText(t,"hhx")) { return sizeof(unsigned char); }
	if (conText(t,"llx")) { return sizeof(unsigned long long); }
	if (conText(t,"hx")) { return sizeof(unsigned short); }
	if (conText(t,"lx")) { return sizeof(unsigned long); }
	if (conText(t,"x")) { return sizeof(unsigned int); }
	/* decimal float */
	if (conText(t,"Lf")) { return sizeof(long double); }
	if (conText(t,"lf")) { return sizeof(double); }
	if (conText(t,"f")) { return sizeof(float); }
	/* DECIMAL FLOAT */
	if (conText(t,"LF")) { return sizeof(long double); }
	if (conText(t,"lF")) { return sizeof(double); }
	if (conText(t,"F")) { return sizeof(float); }
	/* hexadecimal float */
	if (conText(t,"La")) { return sizeof(long double); }
	if (conText(t,"la")) { return sizeof(double); }
	if (conText(t,"a")) { return sizeof(float); }
	/* HEXADECIMAL FLOAT */
	if (conText(t,"LA")) { return sizeof(long double); }
	if (conText(t,"lA")) { return sizeof(double); }
	if (conText(t,"A")) { return sizeof(float); }
	/* exponent float */
	if (conText(t,"Le")) { return sizeof(long double); }
	if (conText(t,"le")) { return sizeof(double); }
	if (conText(t,"e")) { return sizeof(float); }
	/* EXPONENT FLOAT */
	if (conText(t,"LE")) { return sizeof(long double); }
	if (conText(t,"lE")) { return sizeof(double); }
	if (conText(t,"E")) { return sizeof(float); }
	/* compact float */
	if (conText(t,"Lg")) { return sizeof(long double); }
	if (conText(t,"lg")) { return sizeof(double); }
	if (conText(t,"g")) { return sizeof(float); }
	/* COMPACT FLOAT */
	if (conText(t,"LG")) { return sizeof(long double); }
	if (conText(t,"lG")) { return sizeof(double); }
	if (conText(t,"G")) { return sizeof(float); }

	printError("Unknown format \"%s\"",t);
	return 0;
}
void printIntegerTypeName(size_t size, int sign) { /* -1 signed, 0 null, 1 unsigned */
	#if Print_Language == lang_Java
		if (size <= 1) { printf("byte"); return; }
		if (size <= 2) { printf("short"); return; }
		if (size <= 4) { printf("int"); return; }
		printf("long");
	#elif Print_Language == lang_C
		#ifdef Use_stdint_data_types
			if (sign == 1) { printf("u"); }
			if (size <= 1) { printf("int8_t"); return; }
			if (size <= 2) { printf("int16_t"); return; }
			if (size <= 4) { printf("int32_t"); return; }
			printf("int64_t");
		#else
			if (sign == -1) { printf("signed"); } else
			if (sign == 1) { printf("unsigned"); }
			if (size <= sizeof(char)) { printf("char"); return; }
			if (size <= sizeof(short)) { printf("short"); return; }
			if (size <= sizeof(int)) { printf("int"); return; }
			if (size <= sizeof(long)) { printf("long"); return; }
			printf("long long");
		#endif
	#endif
}

void printFloatType(size_t size) {
	if (size <= sizeof(float)) { printf("float"); return; }
	if (size <= sizeof(double)) { printf("double"); return; }
	#if Print_Language == lang_C	
		printf("long ");
	#endif
	printf("double");
}

void printTypeName(const char* t) {
	#define conText(a,b) containsText(a,strlen(a),b,TEXT_LENGTH(b))
	size_t formatCount = 0;
	size_t i = 0;
	while (t[i] != '\0') {
		if (t[i] == '%') { formatCount++; }
		i++;
	}
	if (formatCount != 1) { return; }
	#if Print_Language == lang_C
		if (conText(t,"s")) { printf("char* "); return; }
		if (conText(t,"c")) { printf("char "); return; }
		if (conText(t,"p")) { printf("void* "); return; }
	#elif Print_Language == lang_Java
		if (conText(t,"s")) { printf("String"); return; }
		if (conText(t,"c")) { printf("char"); return; }
	#elif Print_Language == lang_CSharp
		if (conText(t,"s")) { printf("string"); return; }
		if (conText(t,"c")) { printf("char"); return; }
	#endif
	/* decimal */
	if (conText(t,"hhd")) { printIntegerTypeName(sizeof(char),0); return; }
	if (conText(t,"lld")) { printIntegerTypeName(sizeof(long long),0); return; }
	if (conText(t,"hd")) { printIntegerTypeName(sizeof(short),0); return; }
	if (conText(t,"ld")) { printIntegerTypeName(sizeof(long),0); return; }
	if (conText(t,"d")) { printIntegerTypeName(sizeof(int),0); return; }
	/* integer */
	if (conText(t,"hhi")) { printIntegerTypeName(sizeof(signed char),-1); return; }
	if (conText(t,"lli")) { printIntegerTypeName(sizeof(signed long long),-1); return; }
	if (conText(t,"hi")) { printIntegerTypeName(sizeof(signed short),-1); return; }
	if (conText(t,"li")) { printIntegerTypeName(sizeof(signed long),-1); return; }
	if (conText(t,"i")) { printIntegerTypeName(sizeof(signed int),-1); return; }
	/* unsigned */
	if (conText(t,"hhu")) { printIntegerTypeName(sizeof(unsigned char),1); return; }
	if (conText(t,"llu")) { printIntegerTypeName(sizeof(unsigned long long),1); return; }
	if (conText(t,"hu")) { printIntegerTypeName(sizeof(unsigned short),1); return; }
	if (conText(t,"lu")) { printIntegerTypeName(sizeof(unsigned long),1); return; }
	if (conText(t,"u")) { printIntegerTypeName(sizeof(unsigned int),1); return; }
	/* octal */
	if (conText(t,"hho")) { printIntegerTypeName(sizeof(unsigned char),1); return; }
	if (conText(t,"llo")) { printIntegerTypeName(sizeof(unsigned long long),1); return; }
	if (conText(t,"ho")) { printIntegerTypeName(sizeof(unsigned short),1); return; }
	if (conText(t,"lo")) { printIntegerTypeName(sizeof(unsigned long),1); return; }
	if (conText(t,"o")) { printIntegerTypeName(sizeof(unsigned int),1); return; }
	/* HEXADECIMAL */
	if (conText(t,"hhX")) { printIntegerTypeName(sizeof(unsigned char),1); return; }
	if (conText(t,"llX")) { printIntegerTypeName(sizeof(unsigned long long),1); return; }
	if (conText(t,"hX")) { printIntegerTypeName(sizeof(unsigned short),1); return; }
	if (conText(t,"lX")) { printIntegerTypeName(sizeof(unsigned long),1); return; }
	if (conText(t,"X")) { printIntegerTypeName(sizeof(unsigned int),1); return; }
	/* hexadecimal */
	if (conText(t,"hhx")) { printIntegerTypeName(sizeof(unsigned char),1); return; }
	if (conText(t,"llx")) { printIntegerTypeName(sizeof(unsigned long long),1); return; }
	if (conText(t,"hx")) { printIntegerTypeName(sizeof(unsigned short),1); return; }
	if (conText(t,"lx")) { printIntegerTypeName(sizeof(unsigned long),1); return; }
	if (conText(t,"x")) { printIntegerTypeName(sizeof(unsigned int),1); return; }
	/* decimal float */
	if (conText(t,"Lf")) { printf("long double "); return; }
	if (conText(t,"lf")) { printf("double "); return; }
	if (conText(t,"f")) { printf("float "); return; }
	/* DECIMAL FLOAT */
	if (conText(t,"LF")) { printf("long double "); return; }
	if (conText(t,"lF")) { printf("double "); return; }
	if (conText(t,"F")) { printf("float "); return; }
	/* hexadecimal float */
	if (conText(t,"La")) { printf("long double "); return; }
	if (conText(t,"la")) { printf("double "); return; }
	if (conText(t,"a")) { printf("float "); return; }
	/* HEXADECIMAL FLOAT */
	if (conText(t,"LA")) { printf("long double "); return; }
	if (conText(t,"lA")) { printf("double "); return; }
	if (conText(t,"A")) { printf("float "); return; }
	/* exponent float */
	if (conText(t,"Le")) { printf("long double "); return; }
	if (conText(t,"le")) { printf("double "); return; }
	if (conText(t,"e")) { printf("float "); return; }
	/* EXPONENT FLOAT */
	if (conText(t,"LE")) { printf("long double "); return; }
	if (conText(t,"lE")) { printf("double "); return; }
	if (conText(t,"E")) { printf("float "); return; }
	/* compact float */
	if (conText(t,"Lg")) { printf("long double "); return; }
	if (conText(t,"lg")) { printf("double "); return; }
	if (conText(t,"g")) { printf("float "); return; }
	/* COMPACT FLOAT */
	if (conText(t,"LG")) { printf("long double "); return; }
	if (conText(t,"lG")) { printf("double "); return; }
	if (conText(t,"G")) { printf("float "); return; }
	printError("Unknown format \"%s\"",t);
}

int validateInput() {
	/* Empty Input Errors */
	if (Input_Struct_Size == 0) { printError("Input_Struct has a size of 0\nPlease fill out \"input.h\""); return -1; }
	if (Input_Type_Size == 0 || Input_Type_Len == 0) { printError("Input_Type has a size of 0\nPlease fill out \"input.h\""); return -1; }
	if (Input_Name_Size == 0 || Input_Name_Len == 0) { printError("Input_Name has a size of 0\nPlease fill out \"input.h\""); return -1; }
	if (Input_Data_Size == 0 || Input_Data_Len == 0) { printError("Input_Struct has a size of 0\nPlease fill out \"input.h\""); return -1; }
	/* Length/Size Errors */
	if (Input_Type_Len != Input_Name_Len) {
		printError("Input_Type and Input_Name do NOT have the same length (%llu != %llu)",Input_Type_Len,Input_Name_Len);
		return -1;
	}
	size_t struct_size = 0;
	for (size_t t = 0; t < Input_Type_Len; t++) {
		size_t typeLength = getTypeLength(Input_Type[t]);
		if (typeLength == 0) {
			return -1;
		}
		struct_size += typeLength;
		Input_Struct_Len++;
	}
	if (struct_size > Input_Struct_Size) {
		printError("Input_Type is larger than sizeof(Input_Struct) (%llu > %llu)",struct_size,Input_Struct_Size);
		return -1;
	} else if (struct_size < Input_Struct_Size) {
		printError("Input_Type is smaller than sizeof(Input_Struct) (%llu < %llu)",struct_size,Input_Struct_Size);
		return -1;
	}
	/* Name Errors */
	#ifdef Confirm_that_variable_names_are_legal_C_variable_names
		for (size_t n = 0; n < Input_Name_Len; n++) {
			if (checkVariableName(Input_Name[n]) != 0) {
				return -1;
			}
		}
	#endif
	return 0;
}

void printfEscapeCode(char c) {
	if (c == '\n') {
		#if Print_Language == lang_JS
			printf("<br>");
		#else
			printf("\\n");
		#endif
	} else if (c == '\t') {
		printf("\\t");
	} else if (c == '\r') {
		printf("\\r");
	} else if (c == '\v') {
		printf("\\v");
	} else if (c == '\'') {
		printf("\\\'");
	} else if (c == '\"') {
		printf("\\\"");
	} else if (c == '\\') {
		printf("\\\\");
	} else {
		printf("%c",c);
	}
}
int printfSpecialChar(char* text) {
	if (*text != '\0') {
		printfEscapeCode(*text);
	}
	return 0;
}
int printfSpecial(char* text) {
	while (*text != '\0') {
		printfEscapeCode(*text);
		text++;
	}
	return 0;
}

#ifdef Use_const_type
	#if Print_Language == lang_Java
		#define const_type_text "final "
	#else
		#define const_type_text "const "
	#endif
#endif
#if Print_Language == lang_JS
	#ifndef const_type_text
		#ifdef Use_var_instead_of_let
			#define JS_type "var "
		#else
			#define JS_type "let "
		#endif
	#endif
#endif

void printStruct() {
	uint8_t* ptr = (uint8_t*)Input_Data;
	size_t offset = 0;
	size_t structPos = 0;
	//printf("\nInput_Data Address: %p\n",&Input_Data);
	for (size_t t = 0; t < Input_Type_Len; t++) {
		printf("\n");
		#ifdef Use_const_type
			printf(const_type_text);
		#endif
		#if Print_Language == lang_C
			#ifdef Automatically_insert_data_types
				printTypeName(Input_Type[t]);
				printf(" ");
			#endif
			printf("%s[%llu] = {",Input_Name[t],Input_Data_Len);
		#elif Print_Language == lang_JS
			#ifdef JS_type
				printf(JS_type);
			#endif
			printf("%s = [",Input_Name[t],Input_Data_Len);
		#else
			#ifdef Automatically_insert_data_types
				printTypeName(Input_Type[t]);
				printf("[] ");
			#endif
			printf("%s = {",Input_Name[t],Input_Data_Len);
		#endif
		size_t typeLength = getTypeLength(Input_Type[t]);
		uint8_t quotations = 0;
		if (containsText(Input_Type[t],strlen(Input_Type[t]),"s",TEXT_LENGTH("s"))) {
			quotations = 2;
		} else if (containsText(Input_Type[t],strlen(Input_Type[t]),"c",TEXT_LENGTH("c"))) {
			quotations = 1;
		}
		
		offset = structPos;
		for (size_t i = 0; i < Input_Data_Len; i++) {
			#ifdef Print_spaces_after_commas
				if (i != 0) { printf(", "); }
			#else
				if (i != 0) { printf(","); }
			#endif
			#ifdef Print_array_elements_on_separate_lines
				printf("\n\t");
			#endif
			/* Grabs typeLength bytes */
			size_t buf = 0;
			for (size_t b = 0; b < typeLength; b++) {
				buf *= 256;
				buf += ptr[offset + (typeLength - b - 1)];
			}
			/* Passes buf into printf where it can be interpretted as the intended data type */
			if (quotations == 0) {
				printf(Input_Type[t],buf);
			} else if (quotations == 2) {
				printf("\"");
				printfSpecial((char*)buf);
				printf("\"");
			} else if (quotations == 1) {
				printf("\'");
				printfSpecialChar((char*)buf);
				printf("\'");
			}
			offset += Input_Struct_Size;
		}
		#ifdef Print_array_elements_on_separate_lines
			printf("\n");
		#endif
		#if Print_Language == lang_JS
			printf("];");
		#else
			printf("};");
		#endif
		structPos += typeLength;
	}
}

int main() {
	#if Print_Language >= lang_COUNT || Print_Language < 0
		printError("Invalid value for \"#define Print_Language\"");
		return -1;
	#endif
	printF("\nStruct Splitter v%s | zerico2005 | %s\n",STRUCT_SPLITTER_VERSION,STRUCT_SPLITTER_DATE);
	if (validateInput() != 0) {
		return -1;
	}
	printF("\nInput_Struct: %llu members, %llu bytes\n",Input_Struct_Len,Input_Struct_Size);
	printStruct();
	return 0;
}