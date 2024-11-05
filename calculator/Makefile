# Компилятор
CXX=g++
CXXFLAGS=-Wall -g

# Целевой файл
TARGET=calculator

# Список исходных файлов
SRC=calculator.cpp

# Правило для сборки программы
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Очистка скомпилированных файлов
clean:
	rm -f $(TARGET) *.o
