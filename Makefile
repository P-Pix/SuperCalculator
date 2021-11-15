DATA	=	src/*.cpp\
			src/Algebra/*.cpp\
			src/Maths/*.cpp\
			src/Trigo/*.cpp\
			src/Window/*.cpp\

LIB    	=   `pkg-config gtkmm-3.0 --cflags --libs`\

VERSION = 	-std=c++2a\

NAME    =	SuperCalculator.obj\

compile:
	@echo "Compiling..."
	@(g++ -o $(NAME) $(DATA) $(LIB) $(VERSION))
	@echo "Compilation done."

clean:
	@echo "Cleaning..."
	@(rm -f $(NAME))
	@echo "Cleaning done."

sources:
	@echo "Sources:"
	@(ls -l $(DATA))

static:
	@echo "Static:"
	@(ls -l $(LIB))

