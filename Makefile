CC = g++ -std=c++11

CC_FLAGS= -fPIC

# colors for terminal print
GREEN_=\033[92m
_GREEN=\033[0m

LIBS =

EXE = test

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIRS = $(INC_DIR) .

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(EXE)

$(EXE): $(OBJS)
		@echo "$(GREEN_)linking target$(_GREEN)"
		mkdir -p $(BIN_DIR)
		$(CC) $(CC_FLAGS) $^ -o $(BIN_DIR)/$@  $(foreach L,$(LIBS),-l$L)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
		@echo "$(GREEN_)compiling target$(_GREEN)"
		mkdir -p $(OBJ_DIR)
		$(CC) $(CC_FLAGS) -c $< -o $@ $(foreach D,$(INC_DIRS),-I$D)

clean:
		@echo "$(GREEN_)cleaning$(_GREEN)"
		rm -rf $(OBJS) $(BIN_DIR)/*

install:
		@echo "$(GREEN_)installing header to system$(_GREEN)"
		cp $(INC_DIR)/litegraph.hpp /usr/local/include/litegraph.hpp

run:
		@echo "$(GREEN_)running test$(_GREEN)"
		./$(BIN_DIR)/$(EXE)
