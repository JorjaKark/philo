#include "philosophers.h"

void set_simulation_stopped(t_program *program) {
    pthread_mutex_lock(&program->stop_mutex);
    program->stop_simulation = 1;
    pthread_mutex_unlock(&program->stop_mutex);
}

int is_simulation_stopped(t_program *program) {
    pthread_mutex_lock(&program->stop_mutex);
    int stopped = program->stop_simulation;
    pthread_mutex_unlock(&program->stop_mutex);
    return stopped;
}
