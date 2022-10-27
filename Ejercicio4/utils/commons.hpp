#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <cstdlib>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <iostream>
#include <mutex>
#include <thread>
#include <threads.h>
#include <signal.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <bits/stdc++.h>
#include <syslog.h>
#include <fstream>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/file.h>
#include <errno.h>
#include <ctype.h>

#define ArchMC "/MemoriaCompartida"
#define ArchTam 1024

using namespace ::std;

typedef struct {
    char sexo;
    char castrado;
}memoria;