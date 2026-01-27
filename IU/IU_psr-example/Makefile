RTEMS_API = 6
RTEMS_CPU = sparc
RTEMS_BSP = gr740

RTEMS_ROOT = /opt/rtems/6
PKG_CONFIG = $(RTEMS_ROOT)/lib/pkgconfig/$(RTEMS_CPU)-rtems$(RTEMS_API)-$(RTEMS_BSP).pc
BUILDDIR = b-$(RTEMS_BSP)

DEPFLAGS = -MT $@ -MD -MP -MF $(basename $@).d
WARNFLAGS = -Wall -Wextra
OPTFLAGS = -O0 -g -fno-inline
EXEEXT = .exe

ABI_FLAGS = $(shell pkg-config --cflags $(PKG_CONFIG))
LDFLAGS = $(shell pkg-config --libs $(PKG_CONFIG)) -lrtemsbsp -lrtemstest -lrtemscpu -lm
CFLAGS = $(DEPFLAGS) $(WARNFLAGS) $(ABI_FLAGS) $(OPTFLAGS)
ASFLAGS = $(ABI_FLAGS)

CCLINK = $(CC) $(CFLAGS) -Wl,-Map,$(basename $@).map

$(BUILDDIR)/%.o: %.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

export PATH := $(RTEMS_ROOT)/bin:$(PATH)

export AR = $(RTEMS_CPU)-rtems$(RTEMS_API)-ar
export AS = $(RTEMS_CPU)-rtems$(RTEMS_API)-as
export CC = $(RTEMS_CPU)-rtems$(RTEMS_API)-gcc
export LD = $(RTEMS_CPU)-rtems$(RTEMS_API)-ld
export NM = $(RTEMS_CPU)-rtems$(RTEMS_API)-nm
export OBJCOPY = $(RTEMS_CPU)-rtems$(RTEMS_API)-objcopy
export RANLIB = $(RTEMS_CPU)-rtems$(RTEMS_API)-ranlib
export SIZE = $(RTEMS_CPU)-rtems$(RTEMS_API)-size
export STRIP = $(RTEMS_CPU)-rtems$(RTEMS_API)-strip

APP = $(BUILDDIR)/app
APP_C_FILES = main.c
APP_OBJS = $(APP_C_FILES:%.c=$(BUILDDIR)/%.o)
APP_DEPS = $(APP_C_FILES:%.c=$(BUILDDIR)/%.d)

all: $(APP)$(EXEEXT)

$(BUILDDIR):
	mkdir $(BUILDDIR)

$(APP)$(EXEEXT): $(APP_OBJS)
	$(CCLINK) $^ $(LDFLAGS) -o $@

run: $(APP)$(EXEEXT)
	sparc-rtems$(RTEMS_API)-sis -gr740 -dumbio -r s $<

clean:
	rm -rf $(BUILDDIR)

-include $(APP_DEPS)
