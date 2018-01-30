src_dir = src
build_dir = build

src = $(wildcard $(src_dir)/*.cpp)
obj = $(subst $(src_dir), $(build_dir), $(src:.cpp=.o))
trg = pari.out

all: $(trg)
$(trg): $(obj)
	g++ -o $@ $(obj)

$(build_dir)/%.o:$(src_dir)/%.cpp
	g++ $< -c -o $@ 
vars: 
	@echo « src =$(src) »
	@echo « obj =$(obj) »
	@echo « trg =$(trg) »
	
clean :
	rm -rf *.o 
	rm -rf *.out
	rm -rf $(build_dir)/*.o