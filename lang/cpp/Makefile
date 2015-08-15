PROJ := glog blas template
ELF  := glog_demo blas template_demo

main: $(PROJ)

glog:
	$(MAKE) -f glog.mk
blas:
	g++ blas.cpp -lglog -lblas -Wall -o blas
template:
	g++ template.cpp -lglog -Wall -o template_demo

clean:
	-$(RM) $(ELF)
