#The Compiler being used
CC = g++

#All the flags related to debugging and error management.
CFLAGS = -std=c++11 -Wall -Wextra -g

#The name of the executable file.
TARGET = FissionApp

#All of the source code that needs linking and compiling.
SRC = Source/Application.cpp\
      Source/Graphics/Window.cpp

#The path to the includes directory from the source of compilation.
INCLUDES = -I./Includes

#The path to all of the linking dependencies for the project. Also from the source of compilation.
LFLAGS = -L./Dependencies

#All of the dependencies needed to be linked.
LIBS = -lGL -lGLU -lGLEW -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -l Xcursor

#Sets every individual file in SRC into an object .o file
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)
	@echo Compilation Successful.

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJ) $(LFLAGS) $(LIBS)
	@echo Linked Successfully.

#Compiles all .cpp files into .o files that were stated previously.
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	echo Copmpiling $<
