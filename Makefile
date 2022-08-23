compile:
	gcc generator.c -o generator.out

run:
	./generator.out

clean:
	rm generator.out
	rm badcalculator.c
