# コンパイラとフラグ
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# ディレクトリ
SRC_DIR = src
OUTPUT_DIR = output

# 実行ファイル名
TARGET = $(OUTPUT_DIR)/library_system

# オブジェクトファイル
OBJECTS = $(OUTPUT_DIR)/main.o $(OUTPUT_DIR)/Book.o $(OUTPUT_DIR)/Library.o

# デフォルトターゲット
all: $(OUTPUT_DIR) $(TARGET)

# outputディレクトリの作成
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# 実行ファイルの作成
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# オブジェクトファイルの作成
$(OUTPUT_DIR)/main.o: $(SRC_DIR)/main.cpp $(SRC_DIR)/Library.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(OUTPUT_DIR)/main.o

$(OUTPUT_DIR)/Book.o: $(SRC_DIR)/Book.cpp $(SRC_DIR)/Book.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Book.cpp -o $(OUTPUT_DIR)/Book.o

$(OUTPUT_DIR)/Library.o: $(SRC_DIR)/Library.cpp $(SRC_DIR)/Library.h $(SRC_DIR)/Book.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Library.cpp -o $(OUTPUT_DIR)/Library.o

# クリーンアップ
clean:
	rm -rf $(OUTPUT_DIR)

.PHONY: all clean