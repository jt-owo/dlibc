BUILD_DIR := build
BUILD_INTERFACE_DIR := build/include
SRC_DIR := src
TEST_DIR := tests
BUILD_ARGS := -Wall -Wextra -Wpedantic
LIB_NAME := dlibc
PROJECT_NAME := dlibc

# cleanup unused .o files.
finish: copyHeaders
	rm -f *.o

# copy .h files to the build dir.
copyHeaders: link
	find ./$(SRC_DIR)/ -name "*.h" -exec cp {} ./build/include/ \;

# link all .o files to one .a file.
link: mkDirs
	ar -cvq ./$(BUILD_DIR)/$(LIB_NAME).a *.o

# create dirs for compiled library.
mkDirs: compile
	if [ -d "$(BUILD_DIR)" ]; then rm -Rf $(BUILD_DIR); fi
	mkdir $(BUILD_DIR)
	if [ -d "$(BUILD_INTERFACE_DIR)" ]; then rm -Rf $(BUILD_INTERFACE_DIR); fi
	mkdir $(BUILD_INTERFACE_DIR)

# compile .c to .o.
compile:
	gcc $(BUILD_ARGS) -c ./$(SRC_DIR)/*.c

# build test with library and run.
test:
	gcc $(BUILD_ARGS) $(TEST_DIR)/test.c ./$(BUILD_DIR)/$(LIB_NAME).a -o $(PROJECT_NAME)
	./$(PROJECT_NAME) $(TEST_DIR)/map.txt

# remove build dir.
rem:
	if [ -d "$(BUILD_DIR)" ]; then rm -Rf $(BUILD_DIR); fi