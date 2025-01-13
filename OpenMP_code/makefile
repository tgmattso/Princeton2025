#
#  USAGE:
#     make          ... to build the programs
#     make test     ... to run the default test case
#     make clean    ... remove object files and executables
#

#  define compiler, linker, and optimization flags plus library refs
CC          = gcc
CLINKER     = $(CC)
LIBS        = -lm
CFLAGS      = -fopenmp
OPTFLAGS    = -std=c11 -fopenmp -O0 

# All the executables supported by this makefile
EXES = hello pi mandel mm_testbed jac_solv pi_mc linked hist 

# Lists of object files needed to build executables listed above
MM_OBJS  = mm_testbed.o mm_utils.o mm_tst_cases.o mm_ijk.o mm_opt.o 

JAC_OBJS = jac_solv.o mm_utils.o 

PMC_OBJS = pi_mc.o random.o

HIST_OBJS = hist.o random.o

all: $(EXES)

jac_solv: $(JAC_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o jac_solv $(JAC_OBJS) $(LIBS)

mm_testbed: $(MM_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o mm_testbed $(MM_OBJS) $(LIBS)

linked: linked.o 
	$(CLINKER) $(OPTFLAGS) -o linked linked.o $(LIBS)

hello$(EXE): hello.o 
	$(CLINKER) $(OPTFLAGS) -o hello hello.o $(LIBS)

pi$(EXE): pi.o 
	$(CLINKER) $(OPTFLAGS) -o pi pi.o $(LIBS)

mandel:  mandel.o 
	$(CLINKER) $(OPTFLAGS) -o mandel mandel.o $(LIBS)

pi_mc: $(PMC_OBJS) random.h
	$(CLINKER) $(OPTFLAGS) -o pi_mc $(PMC_OBJS) $(LIBS)

hist$(EXE): $(HIST_OBJS) random.h
	$(CLINKER) $(OPTFLAGS) -o hist $(HIST_OBJS) $(LIBS)

test: $(EXES)
	./hello 
	./pi 
	./pi_mc 
	./mandel 
	./mm_testbed 
	./linked 
	./hist 
	./jac_solv 

clean:
	rm $(EXES) *.o

.SUFFIXES:
.SUFFIXES: .c .cpp .o

.c.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CC) $(CFLAGS) -c $<
