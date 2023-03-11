# create a make file for the project (cpp)

# define the compiler

CC = g++

# define any compile-time flags 
CFLAGS = -Wall -m32 -fPIC -std=c++11 -Wunused-but-set-variable -O0 -masm=intel

# define any directories containing header files other than /usr/include

INCLUDES =  -I. -I./minhook/include/

# define library paths in addition to /usr/lib

LFLAGS = -L./minhook/lib/

# define any libraries to link into executable:

LIBS = -lMinHook

# define the C source files (main.cpp cheat.cpp etc)

SRCS = $(wildcard *.cpp)

# define the C object files

OBJS = $(SRCS:.cpp=.o)

# define the executable file

MAIN = cheat.dll

# define the main target

all: $(MAIN)

# define the C++ source file

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -shared -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# define the C object file

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# define the clean target

clean:
	rm -f $(OBJS) $(MAIN)

