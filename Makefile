SOURCES = main.cpp \
          tree/tree.cpp \
          linkedlist/linkedlist.cpp 
HEADERS =
BUILDDIR = build

SOURCE  = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(SOURCES))

CXXFLAG = -g -O0 

all: $(SOURCE)
	-@echo '1 $@ - $<'
	g++ $(CXXFLAG) -o cxbrg $<
	
$(BUILDDIR)/%.o: %.cpp
	-@echo '2: $@ - $<'
	mkdir -p $(@D)
	g++ $(CXXFLAG) -c -o $@ $< 

clean:
	rm -rf  $(BUILDDIR)
		
		


 