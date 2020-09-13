#include <iostream>
#include "mylib.h"

using namespace std;

int main(){
	
	Boolean** P_Q = new Boolean* [4];
    for (int i=0; i<4; i++){
        P_Q[i] = new Boolean[2];
    }

	P_Q[0][0] = F;
	P_Q[0][1] = T;
	P_Q[1][0] = F;
	P_Q[1][1] = T;
	P_Q[2][0] = T;
	P_Q[2][1] = F;
	P_Q[3][0] = T;
	P_Q[3][1] = T;

	logic_calculator cal(P_Q, true);
	
	return 0;
}