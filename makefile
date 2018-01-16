# config
name    = SDL2OO
bin     = bin
source  = src
include = include
libs    = SDL2main SDL2 SDL2_image SDL2_ttf opengl32 glu32
# macros  = main=WinMain
# tools
gcc   = x86_64-w64-mingw32-g++
mkdir = mkdir
rm    = rm -fv
ar    = ar
# macros
mBase    = $(basename $(notdir $(1)))
mPath    = $(addprefix $(1),$(addsuffix $(2),$(3)))
mObj     = $(call mPath,$(1)/,.o,$(call mBase,$(2)))
mCompile = $(gcc) -c -o $(1) $(2)
mLink    = $(gcc) -o $(1) $(2)
mLib     = $(ar) r $(1) $(2)
# vars
macros     := $(addprefix -D,$(macros))
binFile    := $(call mPath,$(bin)/,.exe,$(name))
srcFiles   := $(foreach src,$(source),$(wildcard $(src)/*.cpp))
srclFiles  := $(foreach src,$(libsrc),$(wildcard $(src)/*.cpp))
objFiles   := $(call mObj,$(bin),$(srcFiles))
objlFiles  := $(call mObj,$(bin),$(srclFiles))
incFiles   := $(foreach inc,$(include),$(wildcard $(inc)/*.hpp))
libDir     := $(foreach l,$(lib),-L$(l))
libsOption := $(foreach lib,$(libs),-l$(lib)) $(libDir)
incOption  := $(foreach inc,$(include),-iquote$(inc))
Target = $@
#commands
compile: $(binFile)

builLib: $(libFile)

first:
	$(mkdir) $(bin) $(source) $(include) $(lib) $(libsrc)

clean:
	$(rm) $(binFile) $(objFiles) $(libFile) $(objlFiles)

cleanbin:
	$(rm) $(binFile)

test: $(binFile)
	$(binFile)

# rules
$(libFile): $(objlFiles)
	$(call mLib,$(libFile),$(objlFiles))

$(binFile): $(objFiles) $(libFile)
	$(call mLink,$(binFile),$(objFiles) $(libsOption) $(incOption))


# to fix
define fCompile
$(call mObj,$(bin),$(1)): $(1)
	$(call mCompile,$(value Target),$(1) $(incOption) $(macros))
endef

$(foreach src,$(srcFiles) $(srclFiles),$(eval $(call fCompile,$(src))))
