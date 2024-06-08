
CXX = g++
BUILD_NAME = ./Exe/test
INC_PATH = ./includes
OBJ_DIR = ./
CFLAGS = --std=c++11 -Wall $(foreach D, $(INC_PATH), -I$(D))
LINKER_MAC = .././includes/lib/mac/libglfw.3.3.dylib
LINKER_WIN = .././includes/lib/win/libglfw3dll.a
DIR_OFF = .././src/
HELPER_DIR_OFF = .././src/Helpers/
UNAME_S := $(shell uname -s)

SRC_FILES = main glad
HELPERS_FILES = $(wildcard $(HELPER_DIR_OFF)*.cpp)

# Short hand for combining all the object file into one executable form
WIN_COMMAND = ${CXX} ${CFLAGS} $(foreach D, $(LINKER_WIN), -L. $(D))
MAC_COMMAND = ${CXX} ${CFLAGS} $(foreach D, $(LINKER_MAC), -L. $(D))

SRC_OBJ = $(patsubst %.cpp, $(OBJ_DIR)%.obj, $(foreach D, $(SRC_FILES), $(D).cpp))
HELPERS_OBJ = $(patsubst $(HELPER_DIR_OFF)%.cpp, $(OBJ_DIR)%.obj, $(HELPERS_FILES))

build_m: ${BUILD_NAME}

${BUILD_NAME} : ${SRC_OBJ} ${HELPERS_OBJ}
ifeq (${UNAME_S}, Darwin)
	${MAC_COMMAND} -o $@ $^ 
else
	$(WIN_COMMAND) -o $@ $^ 
endif

${OBJ_DIR}%.obj: $(HELPER_DIR_OFF)%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

${OBJ_DIR}%.obj: $(DIR_OFF)%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean_build: clean build_m

clean:
ifeq (${UNAME_S}, Darwin)
	rm -f *.obj
else
	del -f *.obj
endif