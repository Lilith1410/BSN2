CC 		:= gcc 

### SOURCE EXTENSION
SRCEXT		= c

### DIRECTORIES
SRCDIR		= src
OBJDIR 		= build
BINDIR		= bin
INCLDIR		= include

### SOURCE-, HEADERFILES
SRCS 		= $(shell find $(SRCDIR) -name '*.$(SRCEXT)')
HDR			= $(shell find $())
OBJS		= $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SRCS:.$(SRCEXT)=.o))

### EXTENDED FLAGS AND LIBRARIES
DEBUG		= -g
INCLUDES	= -i include
CFLAGS		= -Wall -pedantic -ansi -std=c11
LDFLAGS 	=

### DIRECTORY NAME AS PROJECT NAME
TARGET_NAME	= $(shell basename $(PWD))
TARGET		= $(BINDIR)/$(TARGET_NAME)

all : $(TARGET)
	@echo $(TARGET) "is up to date"


### LINK STATE ###
$(TARGET) : $(OBJS)
	@echo ":: build finished"
	@echo ":: linking"
	$(CC) $(CFLAGS) -o $@ $^
	
### COMPILE EACH SOURCE FILE FROM SOURCE FOLDER TO BUILD FOLDER ###
$(OBJDIR)/%.o : $(SRCDIR)/%.$(SRCEXT)
	@echo ":: build"
	$(CC) $(CFLAGS) -c -o $@ $<

### SET THE COMPILER DEBUG FLAG IF $@ = "debug"
debug : CFLAGS += $(DEBUG)
debug : $(TARGET) 
	@echo ":: debug build finished"

clean :
	$(RM) $(BINDIR)/$(TARGET_NAME)
	$(RM) -r $(OBJDIR)/*

list : $(TARGET)
	@echo "################################################"
	@echo "######## List symbols of "$(TARGET) "#########"
	@echo "################################################"
	nm $(TARGET)

run : $(TARGET)
	@echo "################################################"
	@echo "############## Run "$(TARGET) "###############"
	@echo "################################################"
	./$(TARGET)
