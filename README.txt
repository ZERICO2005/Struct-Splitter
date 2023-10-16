Struct-Splitter v1.1.0 | zerico2005 | 2023/10/16

Struct-Splitter is a simple tool designed to split a C/C++ struct into multiple parrell arrays.

To use it, manually type the struct information and parameters into input.h, then compile and run the program. (Program was compiled using MSYS2 Mingw64 GCC on Windows 10)

In input.h, there is 5 steps to follow:
	Step 0:
		Configure some parameters by commenting/uncommenting #defines out
	Step 1:
		Fill in the struct declaration
	Step 2:
		Type in the printf formatting for each struct member. If you are unsure what to type, you can view the cheatsheet at the bottom of the README.
	Step 3:
		Type the name of each parrell array
	Step 4:
		Copy and paste the struct data that you want to split
	Step 5:
		Save, compile, and run bin/Split.exe
	
printf formatting on 64bit Windows:
	char "%c"
	char* "%s"
	
	int8_t "%hhd"
	int16_t "%hd"
	int32_t "%d"
	int64_t "%lld"
	
	uint8_t "%hhu"
	uint16_t "%hu"
	uint32_t "%u"
	uint64_t "%llu"
	size_t "%llu"
	
	float "%f"
	double "%lf"
