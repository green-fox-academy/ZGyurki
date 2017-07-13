#ifndef SERVERS_H_INCLUDED
#define SERVERS_H_INCLUDED

void thread_messenger();
void thread_discovery();
void thread_broadcast();

void winsock_init();
void create_socket();
void set_sockopt();
void start_threads();
void let_the_party_started();

#endif // SERVERS_H_INCLUDED
