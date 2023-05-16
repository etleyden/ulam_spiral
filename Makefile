source_files = pixel.cpp spiral.cpp
object_files = pixel.o spiral.o

build:
	g++ -g -c $(source_files)
	g++ -Wall $(object_files) -o spiral
	
print: build
	./spiral

image: build
	./spiral > spiral.ppm
	open spiral.ppm

clean:
	rm spiral.ppm
	rm *.o
	rm spiral	
	rm a.out
