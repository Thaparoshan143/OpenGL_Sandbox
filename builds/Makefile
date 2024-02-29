CXX = g++ --std=c++11
CFLAGS = -Wall
BUILD_NAME = ./Exe/test
OBJ_PATH = .
INC_PATH = -I .././includes -I .././includes/freetypeinc -I .././includes/freetypeinc/freetype
LINKER_MAC = -L. .././lib/mac/libglfw.3.3.dylib -L. .././lib/mac/libfreetype.6.dylib
LINKER_WIN = -L. .././lib/win/libglfw3dll.a -L. .././lib/win/libfreetype.dll.a
PLATFORM_DIR_OFF = ../Platform/OpenGL/
SANDBOX_DIR_OFF = ../Sandbox/
UTIL_DIR_OFF = ../Util/
	
UNAME_S := $(shell uname -s)
ASSEMBLE_CMD = 	${CXX} ${CFLAGS} -c

ifeq ($(UNAME_S), Linux) #LINUX
	ECHO_MESSAGE = "Linux"
endif

ifeq ($(UNAME_S), Darwin) #APPLE
	ECHO_MESSAGE = "MAC OS"
endif

ifeq ($(OS), Windows_NT) #WINDOWS
	ECHO_MESSAGE = "Windows"
endif

# FILE_DEPENDENCIES = main.obj glad.obj OpenGL_Shader.obj OpenGL_Window.obj OpenGL_Application.obj Util.obj
FILE_DEPENDENCIES = main.obj glad.obj OpenGL_Shader.obj OpenGL_Window.obj OpenGL_Application.obj

# Short hand for combining all the object file into one executable form
WIN_COMMAND = ${CXX} ${CFLAGS} -o ${BUILD_NAME} ${OBJ_PATH}/*.obj ${INC_PATH} ${LINKER_WIN}
MAC_COMMAND = ${CXX} ${CFLAGS} -o ${BUILD_NAME} ${OBJ_PATH}/*.obj ${INC_PATH} ${LINKER_MAC}

build_m: ${FILE_DEPENDENCIES}
ifeq (${UNAME_S}, Darwin)
	${MAC_COMMAND}
else
	$(WIN_COMMAND)
endif

build_clean: clean build_m

main.obj: ${SANDBOX_DIR_OFF}main.cpp
	${ASSEMBLE_CMD} -o ${OBJ_PATH}/main.obj ${SANDBOX_DIR_OFF}main.cpp

glad.obj: ${SANDBOX_DIR_OFF}glad.cpp
	${ASSEMBLE_CMD} -o ${OBJ_PATH}/glad.obj ${SANDBOX_DIR_OFF}glad.cpp

OpenGL_Shader.obj: ${PLATFORM_DIR_OFF}OpenGL_Shader.cpp ${PLATFORM_DIR_OFF}OpenGL_Shader.h
	${ASSEMBLE_CMD} -o ${OBJ_PATH}/OpenGL_Shader.obj ${PLATFORM_DIR_OFF}OpenGL_Shader.cpp

OpenGL_Window.obj: ${PLATFORM_DIR_OFF}OpenGL_Window.cpp ${PLATFORM_DIR_OFF}OpenGL_Window.h
	${ASSEMBLE_CMD} -o ${OBJ_PATH}/OpenGL_Window.obj ${PLATFORM_DIR_OFF}OpenGL_Window.cpp

OpenGL_Application.obj: ${PLATFORM_DIR_OFF}OpenGL_Application.cpp ${PLATFORM_DIR_OFF}OpenGL_Application.h
	${ASSEMBLE_CMD} -o ${OBJ_PATH}/OpenGL_Application.obj ${PLATFORM_DIR_OFF}OpenGL_Application.cpp


Util.obj: ${UTIL_DIR_OFF}*.cpp
	${ASSEMBLE_CMD} -o ${OBJ_PATH}/Util.obj ${UTIL_DIR_OFF}*.cpp

clean:
ifeq (${UNAME_S}, Darwin)
	rm -f *.obj
else
	del -f *.obj
endif