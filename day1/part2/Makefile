BUILD_DIR = build
EXECUTABLE = $(BUILD_DIR)/advent

advent: $(BUILD_DIR)
	g++ src/advent.cc -std=c++14 -g -Wall -o $(EXECUTABLE)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

run: advent
	@$(EXECUTABLE) input.txt

clean:
	rm -f $(BUILD_DIR)/*.exe
