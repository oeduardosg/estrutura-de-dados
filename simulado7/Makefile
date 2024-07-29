run:
	gcc *.c -o teste
	valgrind --leak-check=full ./teste $(ARGS)

saferun:
	gcc *.c -g -o teste
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=outval.txt ./teste