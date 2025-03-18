BUILD_DIR := build
BUILD_INTERFACE_DIR := build/include
SRC_DIR := src
TEST_DIR := tests
BUILD_ARGS := -Wall -Wextra -Wpedantic
LIB_NAME := owolib

# build test with library and run.
test: finish
	gcc $(BUILD_ARGS) $(TEST_DIR)/test.c ./$(BUILD_DIR)/$(LIB_NAME).dll -o test
	./test $(TEST_DIR)/map.txt

# cleanup unused .o files.
finish: copyHeaders
	rm -f *.o

# copy header files to the build dir.
copyHeaders: link
	find ./$(SRC_DIR)/ -name "*.h" -exec cp {} ./build/include/ \;

# Compile object files to a shared dll.
link: mkDirs
	gcc -shared -o ./$(BUILD_DIR)/$(LIB_NAME).dll *.o

# create dirs for compiled library.
mkDirs: compile
	if [ -d "$(BUILD_DIR)" ]; then rm -Rf $(BUILD_DIR); fi
	mkdir $(BUILD_DIR)
	if [ -d "$(BUILD_INTERFACE_DIR)" ]; then rm -Rf $(BUILD_INTERFACE_DIR); fi
	mkdir $(BUILD_INTERFACE_DIR)

# compile C to object code.
compile:
	gcc $(BUILD_ARGS) -c ./$(SRC_DIR)/*.c

# remove build dir.
rem:
	if [ -d "$(BUILD_DIR)" ]; then rm -Rf $(BUILD_DIR); fi
	rm -f test
	rm -f *.exe
	rm -f *.dll