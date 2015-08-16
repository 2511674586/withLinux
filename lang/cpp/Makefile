PROJ := glog blas template stl
ELF  := glog_demo blas template_demo stl_demo

main: $(PROJ)

glog:
	$(MAKE) -f glog.mk
blas:
	g++ blas.cpp -lglog -lblas -Wall -o blas
template:
	g++ template.cpp -lglog -Wall -o template_demo
stl:
	g++ stl.cpp -lglog -Wall -o stl_demo

clean:
	-$(RM) $(ELF)
