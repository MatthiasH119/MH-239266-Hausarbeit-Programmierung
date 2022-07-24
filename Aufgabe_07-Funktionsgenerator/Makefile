compile_main_static:		compile_application_staticlib
	gcc -o main_function-generator.elf main_function-generator.c -l_static_function-generator -lm

compile_mainDEBUG_static:	compile_applicationDEBUG_staticlib
	gcc -o main_function-generator.elf main_function-generator.c -l_static_function-generator -lm -DDEBUG


compile_application_staticlib:
	gcc -c static_function-generator.c
	ar -crs lib_static_function-generator.a static_function-generator.o
	sudo cp static_function-generator.h /usr/include
	sudo cp lib_static_function-generator.a /usr/lib

compile_applicationDEBUG_staticlib:
	gcc -c static_function-generator.c -DDEBUG
	ar -crs lib_static_function-generator.a static_function-generator.o
	sudo cp static_function-generator.h /usr/include
	sudo cp lib_static_function-generator.a /usr/lib
