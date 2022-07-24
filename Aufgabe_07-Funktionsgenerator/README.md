Compilation:
	compile funktion without additional DEBUG information: 		'make compile_main_static'
	compile funktion with additional DEBUG information: 		'make compile_mainDEBUG_static'

Usage:
	standard execution:	'./main_function-generator.elf'
	->	x axis values are written to 'outstream_x.txt'
	->      y axis values are written to 'outstream_y.txt'


	default amount of values:			100
	manual set:		'./main_function-generator.elf -n [int]'


	default resolution of sawblade function:	20
	manual set:		'./main_function-generator.elf -r [int]'

	
	help:			'./main_function-generator.elf -h'

	version:		'./main_function-generator.elf -v'	
