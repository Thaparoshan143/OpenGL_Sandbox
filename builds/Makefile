
CXX = g++ --std=c++11
CFLAGS = -Wall
BUILD_NAME = ./Exe/test
OBJ_PATH = .
INC_PATH = -I./includes
LINKER_MAC = -L. .././includes/lib/mac/libglfw.3.3.dylib
LINKER_WIN = -L. .././includes/lib/win/libglfw3dll.a
DIR_OFF = .././src/
ASSEMBLE_CMD = 	${CXX} ${CFLAGS} -c
	
FILE_DEPENDENCIES = main.o glad.o Shader.o Window.o

# Short hand for combining all the object file into one executable form
WIN_COMMAND = ${CXX} ${CFLAGS} -o ${BUILD_NAME} ${OBJ_PATH}/*.o ${INC_PATH} ${LINKER_WIN}
MAC_COMMAND = ${CXX} ${CFLAGS} -o ${BUILD_NAME} ${OBJ_PATH}/*.o ${INC_PATH} ${LINKER_MAC}

win_m: ${FILE_DEPENDENCIES}
	${WIN_COMMAND}

mac_m: ${FILE_DEPENDENCIES}
	${MAC_COMMAND}

main.o: ${DIR_OFF}main.cpp
	${ASSEMBLE_CMD} -o ${OBJ_PATH}/main.o ${DIR_OFF}main.cpp

glad.o: ${DIR_OFF}glad.cpp
	${ASSEMBLE_CMD} -o ${OBJ_PATH}/glad.o ${DIR_OFF}glad.cpp

Shader.o: ${DIR_OFF}Helpers/Shader.cpp ${DIR_OFF}Helpers/Shader.h
	${ASSEMBLE_CMD} -o ${OBJ_PATH}/Shader.o ${DIR_OFF}Helpers/Shader.cpp

Window.o: ${DIR_OFF}Helpers/Window.cpp ${DIR_OFF}Helpers/Window.h
	${ASSEMBLE_CMD} -o ${OBJ_PATH}/Window.o ${DIR_OFF}Helpers/Window.cpp
