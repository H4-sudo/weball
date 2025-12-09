CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Werror -O2 -Iinclude -Isrc

SRC_DIR := src
BUILD_DIR := build
TARGET := $(BUILD_DIR)/weball

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

.DEFAULT_GOAL := all

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
