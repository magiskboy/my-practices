CC = gcc

# Compiler flags:
# -g: adds debugging info to .exe file
# -Wall: turns on most compiler warnings
CFLAGS = -Wall

# List of src files:
SRC_SERVER = server.c
SRC_CLIENT = client.c

# Build target executable:
TARGET_SERVER = server
TARGET_CLIENT = client

all: $(TARGET_SERVER) $(TARGET_CLIENT)

$(TARGET_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(TARGET_SERVER) $(SRC_SERVER)
$(TARGET_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(TARGET_CLIENT) $(SRC_CLIENT)

clean:
	$(RM) *.o $(shell find . -type f -executable ! -name "*.*")
