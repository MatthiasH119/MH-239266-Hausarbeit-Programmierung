compile_main_static:
	gcc -o main_function-generator.elf main_function-generator.c -l_static_function-generator -lm

compile_application_staticlib:
	gcc -c static_function-generator.c
	ar -crs lib_static_function-generator.a static_function-generator.o
	sudo cp static_function-generator.h /usr/include
	sudo cp lib_static_function-generator.a /usr/lib
