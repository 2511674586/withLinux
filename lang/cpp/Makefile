PROJ := glog blas
ELF  := glog_demo blas

main: $(PROJ)

glog:
	$(MAKE) -f glog.mk
blas:
	g++ blas.cpp -lglog -lblas -Wall -o blas

clean:
	-$(RM) $(ELF)
