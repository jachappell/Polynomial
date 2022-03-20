PROG1=example1
PROG2=example2
OBJDIR=.obj
CC=g++

CFLAGS = -Wall -std=c++14 -I ..

$(shell mkdir -p $(OBJDIR)) 

all: $(PROG1) $(PROG2)

OBJS1 = $(OBJDIR)/example1.o
OBJS2 = $(OBJDIR)/example2.o

$(PROG1) : $(OBJS1)
	$(CC) $(OBJS1) $(LDFLAGS) -o $(PROG1)
$(PROG2) : $(OBJS2)
	$(CC) $(OBJS2) $(LDFLAGS) -o $(PROG2)

-include $(OBJS:.o=.d)

$(OBJDIR)/%.o: %.cpp ../Polynomial.h
	$(CC) -c $(CFLAGS) $*.cpp -o $(OBJDIR)/$*.o
	$(CC) -MM $(CFLAGS) $*.cpp > $(OBJDIR)/$*.d
	@mv -f $(OBJDIR)/$*.d $(OBJDIR)/$*.d.tmp
	@sed -e 's|.*:|$(OBJDIR)/$*.o:|' < $(OBJDIR)/$*.d.tmp > $(OBJDIR)/$*.d
	@sed -e 's/.*://' -e 's/\\$$//' < $(OBJDIR)/$*.d.tmp | fmt -1 | \
	  sed -e 's/^ *//' -e 's/$$/:/' >> $(OBJDIR)/$*.d
	@rm -f $(OBJDIR)/$*.d.tmp

clean:
	rm -rf $(PROG1) $(PROG2) $(OBJDIR)

