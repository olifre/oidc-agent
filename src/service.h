#ifndef SERVICE_H
#define SERVICE_H

unsigned int provider = 0;

void parseOpt(int argc, char* const* argv) ;
int tryRefreshFlow() ;
int tryPasswordFlow() ;
int getAccessToken() ;
int test();

#endif //SERVICE_H
