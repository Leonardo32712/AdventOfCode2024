BUILD_DIR = build
EXECUTABLE = $(BUILD_DIR)/hello

hello: $(BUILD_DIR)
	g++ src/hello.cc -std=c++14 -g -Wall -o $(EXECUTABLE)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

run: hello
	@$(EXECUTABLE) input.txt

clean:
	rm -f $(BUILD_DIR)/*.exe
