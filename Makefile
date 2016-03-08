# Makefile for cdluminate/withlinux
#  this Makefile will compile all sources in withlinux
#
.PHONY: main all all-binary all-doc
main: all

all: all-binary all-doc

all-binary:
	$(MAKE) -C kernel/xv6-rev6/
	$(MAKE) -C booknote/lua/codes/
	$(MAKE) -C booknote/acm/code/
	$(MAKE) -C booknote/cppprimerplus/codes/
	$(MAKE) -C lang/cpp_qt/
	$(MAKE) -C lang/c/
	$(MAKE) -C lang/cpp/
	$(MAKE) -C booknote/prog.math.mind/code/
all-doc:
	$(MAKE) -C minisys/
	$(MAKE) -C kernel/ok6410/
	$(MAKE) -C booknote/ann_matlab/

clean:
	-$(MAKE) -C lang/cpp/ clean purge
	-$(MAKE) -C kernel/xv6-rev6/ clean purge
	-$(MAKE) -C booknote/lua/codes/ clean purge
	-$(MAKE) -C booknote/acm/code/ clean purge
	-$(MAKE) -C booknote/cppprimerplus/codes/ clean purge
	-$(MAKE) -C lang/cpp_qt/ clean purge
	-$(MAKE) -C lang/c/ clean purge
	-$(MAKE) -C booknote/prog.math.mind/code/ clean purge
	-$(MAKE) -C minisys/ clean purge
	-$(MAKE) -C kernel/ok6410/ clean purge
	-$(MAKE) -C booknote/ann_matlab/ clean purge
