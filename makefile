#---- Functions
define PATH
$(foreach ELEMENT,$(1),"$(subst /,\,$(ELEMENT))")
endef

define SPOT
$(shell if not exist $(call PATH,$(dir $(1))) md $(call PATH,$(dir $(1))))
endef


#---- Variables
SOURCE   := $(patsubst src/libmoo.a/%.cc,%.cc,$(wildcard src/libmoo.a/*.cc))
RESOURCE := $(patsubst res/libmoo.a/%.rc,%.rc,$(wildcard res/libmoo.a/*.rc))
OBJECT   := $(strip $(SOURCE:.cc=.o) $(RESOURCE:.rc=.o))

OFLAGS   := -c -Wall -Wextra -std=c++23 -masm=intel -m64 -fPIC -I inc
LIB      := out/$(CONFIG)/lib
TMP      := out/$(CONFIG)/tmp


#---- Specifying flags
ifeq '$(CONFIG)' 'win-x64-dev'
OFLAGS += -O0 -ggdb -D DEVELOPMENT
endif

ifeq '$(CONFIG)' 'win-x64-rel'
OFLAGS += -O2
endif


#---- Targets
all: $(LIB)/libmoo.a


$(LIB)/libmoo.a: $(addprefix $(TMP)/libmoo.a/,$(OBJECT))
	$(call SPOT,$@)
	ar rc $(call PATH,$@) $(call PATH,$^)


$(TMP)/%.o: src/%.cc
	$(call SPOT,$@)
	clang++ -o $(call PATH,$@) $(call PATH,$^) $(OFLAGS)


$(TMP)/%.o: res/%.rc
	$(call SPOT,$@)
	windres -o $(call PATH,$@) $(call PATH,$^)