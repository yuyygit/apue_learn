#目标文件
TARGET = Test
#目标文件存放目录
BINDIR = bin
#所有的目录
DIR = ./hellolib .
#obj文件存放路径
OBJPATH = ./objpath

-include $(source:.c=.d)

#获取目录下所有的.c文件
FILES = $(foreach dir,$(DIR),$(wildcard $(dir)/*.c))

#obj文件名
OBJS = $(patsubst %.c,%.o,$(FILES))

all: $(OBJS) $(TARGET)

$(OBJS):%.o:%.c
	@echo DIR $(DIR)
	@echo FILES $(FILES)
	$(CC) -c -g -MMD $< -o $(OBJPATH)/$(notdir $@) -MF $*.d -MP 

#链接所有的二进制文件成程序
$(TARGET) : $(OBJPATH)
	$(CC) -o $(BINDIR)/$@ $(OBJPATH)/*.o
$(BINDIR):
	mkdir -p $(BINDIR)
$(OBJPATH):
	mkdir -p $(OBJPATH)

.PHONY: clean
clean:
	-rm $(OBJPATH)/*.o
	-rm $(BINDIR)/$(TARGET)
