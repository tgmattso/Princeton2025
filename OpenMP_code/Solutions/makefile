#
#  USAGE:
#     make          ... to build all programs
#     make clean    ... to remove object files and executables
#     make test     ... to run the default test case
#
#  define compiler, linker, and optimization flags plus library refs
CC          = gcc-14
CLINKER     = $(CC)
LIBS        = -lm
CFLAGS      = -fopenmp
OPTFLAGS    = -std=c11 -fopenmp -O3 

EXES= hello_par pi_spmd_simple pi_spmd_final \
            pi_loop  jac_solv_parfor racey_par \
            mm_testbed mandel_par pi_task \
            linked_tasks linked_notasks jac_solv_parfor

JAC_PARFOR_OBJS  = jac_solv_parfor.o mm_utils.o 

MM_OBJS = mm_ijk.o mm_ikj.o mm_ikj_par.o mm_testbed.o mm_trans.o mm_tst_cases.o mm_utils.o

all: $(EXES)

hello_par: hello_par.o
	$(CLINKER) $(OPTFLAGS) -o hello_par hello_par.o $(LIBS)

pi_spmd_simple: pi_spmd_simple.o  
	$(CLINKER) $(OPTFLAGS) -o pi_spmd_simple pi_spmd_simple.o $(LIBS)

pi_spmd_final: pi_spmd_final.o
	$(CLINKER) $(OPTFLAGS) -o pi_spmd_final pi_spmd_final.o $(LIBS)

pi_loop: pi_loop.o
	$(CLINKER) $(OPTFLAGS) -o pi_loop pi_loop.o $(LIBS)

mm_testbed: $(MM_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o mm_testbed $(MM_OBJS) $(LIBS)

mandel_par: mandel_par.o
	$(CLINKER) $(OPTFLAGS) -o mandel_par mandel_par.o $(LIBS)

pi_task: pi_task.o
	$(CLINKER) $(OPTFLAGS) -o pi_task pi_task.o $(LIBS)

racey_par: racey_par.o
	$(CLINKER) $(OPTFLAGS) -o racey_par racey_par.o $(LIBS)

linked_tasks: linked_tasks.o
	$(CLINKER) $(OPTFLAGS) -o linked_tasks linked_tasks.o $(LIBS)

linked_notasks: linked_notasks.o
	$(CLINKER) $(OPTFLAGS) -o linked_notasks linked_notasks.o $(LIBS)

jac_solv_parfor: $(JAC_PARFOR_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o jac_solv_parfor $(JAC_PARFOR_OBJS) $(LIBS)

test: $(EXES)
	./hello_par
	./pi_spmd_simple
	./pi_spmd_final
	./pi_loop
	./mm_testbed
	./mandel_par
	./pi_task
	./racey_par
	./linked_tasks
	./linked_notasks
	./jac_solv_parfor

clean:
	$(RM) $(EXES) *.o

.SUFFIXES:
.SUFFIXES: .c .cpp  .o

.c.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CC) $(CFLAGS) -c $<
