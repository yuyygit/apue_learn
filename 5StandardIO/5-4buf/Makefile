#目标文件;
TARGET = buftest
#目标文件存放目录
BINDIR = ./bin
#所有的目录
DIR = ./src/main .
#obj文件存放路径
OBJPATH = objpath
lib_of_apue = -lapue

CFLAGS =-g -D_GNU_SOURCE -c -o

#获取目录下所有的.c文件
FILES = $(foreach dir,$(DIR),$(wildcard $(dir)/*.c))

#obj文件名
OBJS = $(patsubst %.c,%.o,$(FILES))


all: $(OBJS) $(TARGET) 

$(OBJS):%.o:%.c $(OBJPATH)
	@echo DIR $(DIR)
	@echo FILES $(FILES)
	$(CC) $(CFLAGS) $(OBJPATH)/$(notdir $@) $< $(lib_of_apue)

#链接所有的二进制文件成程序
$(TARGET) : $(BINDIR)
	$(CC) -o $(BINDIR)/$@ $(OBJPATH)/*.o $(lib_of_apue)
$(BINDIR):
	mkdir -p $(BINDIR)
$(OBJPATH):
	mkdir -p $(OBJPATH)

.PHONY: clean
clean:
	-rm $(OBJPATH)/*.o
	-rm $(BINDIR)/$(TARGET)
