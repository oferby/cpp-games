all_files = ${wildcard *.cpp}

all: dodir ${all_files}
	echo done

${all_files}: %.cpp: %

%:
	g++ $@.cpp -o ../bin/arrays/$@


dodir:
	mkdir -p ../bin/arrays



clean:
	rm -r ../bin
