PROJ := glog blas template stl gauss
ELF  := glog_demo blas template_demo stl_demo gauss

main: clean $(PROJ)

glog:
	$(MAKE) -f glog.mk
blas:
	g++ blas.cpp -lglog -lblas -Wall -o blas
gauss:
	g++ gauss.cpp -lglog -lblas -Wall -o gauss
template:
	g++ template.cpp -lglog -Wall -o template_demo
stl:
	g++ stl.cpp -lglog -Wall -o stl_demo

clean:
	-$(RM) $(ELF)
