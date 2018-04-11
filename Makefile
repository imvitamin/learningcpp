SOURCES = main.cpp                        \
          tree/tree.cpp                   \
          linkedlist/linkedlist.cpp       \
          sorts/sort.cpp       
          
HEADERS = .                               \
          sorts
          
BUILDDIR = build

SOURCE_  = $(patsubst %.cpp, %.o, $(SOURCES))
SOURCE   = $(foreach d, $(SOURCE_), $(BUILDDIR)/$(d) )

HEADER   = $(foreach d, $(HEADERS), -I$(d) )

CXXFLAG = -g -O0 

all: $(SOURCE)
	-@echo $(SOURCE)
	g++ $(CXXFLAG) $(HEADER) $(SOURCE) -o cxbrg
	
$(BUILDDIR)/%.o: %.cpp
	-@echo '$@ $<'
	mkdir -p $(@D)
	g++ $(CXXFLAG) $(HEADER) -c -o $@ $< 

clean:
	rm -rf  $(BUILDDIR)
		
		


 