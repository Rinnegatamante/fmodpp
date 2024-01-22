TARGET          := libfmodpp
SOURCES         := source

CFILES   := $(foreach dir,$(SOURCES), $(wildcard $(dir)/*.c))
CPPFILES := $(foreach dir,$(SOURCES), $(wildcard $(dir)/*.cpp))
OBJS     := $(CFILES:.c=.o) $(CPPFILES:.cpp=.o)

PREFIX  = arm-vita-eabi
CC      = $(PREFIX)-gcc
CXX     = $(PREFIX)-g++
AR      = $(PREFIX)-gcc-ar
CFLAGS  = -g -Wl,-q -O3 -ffast-math -I$(VITASDK)/arm-vita-eabi/include/fmod -mtune=cortex-a9 -mfpu=neon -Wno-incompatible-pointer-types -Wno-stringop-overflow
ASFLAGS = $(CFLAGS)

CXXFLAGS  = $(CFLAGS) -fno-exceptions -std=gnu++11 -Wno-write-strings -fpermissive -fvisibility=default -fno-inline

all: $(TARGET).a

$(TARGET).a: $(OBJS)
	$(AR) -rc $@ $^
	
clean: $(SAMPLES_CLR)
	@rm -rf $(TARGET).a $(TARGET).elf $(OBJS)
	
install: $(TARGET).a
	@mkdir -p $(VITASDK)/$(PREFIX)/lib/
	cp $(TARGET).a $(VITASDK)/$(PREFIX)/lib/

