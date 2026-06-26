RTEMS_API = 6
RTEMS_CPU = sparc
RTEMS_BSP = gr740

.DEFAULT_GOAL := all

RTEMS_ROOT = /opt/rtems/6
PKG_CONFIG = $(RTEMS_ROOT)/lib/pkgconfig/$(RTEMS_CPU)-rtems$(RTEMS_API)-$(RTEMS_BSP).pc
BUILDDIR = b-$(RTEMS_BSP)

WARNFLAGS = -Wall -Wextra
OPTFLAGS = -O0 -g -fno-omit-frame-pointer -ffunction-sections -fdata-sections
EXEEXT = .exe

SUPPORT_INCLUDE = -I/workspace/samples/utils/include

ABI_FLAGS = $(shell pkg-config --cflags $(PKG_CONFIG))
LDFLAGS = $(shell pkg-config --libs $(PKG_CONFIG)) -lrtemsbsp -lrtemstest -lrtemscpu -lm
CPPFLAGS = $(SUPPORT_INCLUDE)
CFLAGS = $(WARNFLAGS) $(ABI_FLAGS) $(OPTFLAGS)
CXXFLAGS = $(WARNFLAGS) $(ABI_FLAGS) $(OPTFLAGS)
ASFLAGS = $(ABI_FLAGS)

CCLINK = $(CC) $(CFLAGS) -Wl,-Map,$(APP).map
CXXLINK = $(CXX) $(CXXFLAGS) -Wl,-Map,$(APP).map

export PATH := $(RTEMS_ROOT)/bin:$(PATH)

export AR = $(RTEMS_CPU)-rtems$(RTEMS_API)-ar
export AS = $(RTEMS_CPU)-rtems$(RTEMS_API)-as
export CC = $(RTEMS_CPU)-rtems$(RTEMS_API)-gcc
export CXX = $(RTEMS_CPU)-rtems$(RTEMS_API)-g++
export LD = $(RTEMS_CPU)-rtems$(RTEMS_API)-ld
export NM = $(RTEMS_CPU)-rtems$(RTEMS_API)-nm
export OBJCOPY = $(RTEMS_CPU)-rtems$(RTEMS_API)-objcopy
export RANLIB = $(RTEMS_CPU)-rtems$(RTEMS_API)-ranlib
export SIZE = $(RTEMS_CPU)-rtems$(RTEMS_API)-size
export STRIP = $(RTEMS_CPU)-rtems$(RTEMS_API)-strip

APP = app
APP_C_FILES =
APP_C_FILES += init.c
APP_C_FILES += main.c
APP_OBJS = $(APP_C_FILES:%.c=$(BUILDDIR)/%.o)

all: $(APP)$(EXEEXT)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/init.o: init.c | $(BUILDDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/main.o: main.c | $(BUILDDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(APP)$(EXEEXT): $(APP_OBJS)
	$(CCLINK) $^ $(LDFLAGS) -o $@

run: $(APP)$(EXEEXT)
	sparc-rtems$(RTEMS_API)-sis -gr740 -dumbio -r s $<

clean:
	rm -rf $(BUILDDIR) $(APP)$(EXEEXT) $(APP).map
