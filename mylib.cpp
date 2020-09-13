#include "mylib.h"

using namespace std;

Boolean conjunction( Boolean p1, Boolean p2 ){
	bool p1_bool = static_cast<bool>(p1);
	bool p2_bool = static_cast<bool>(p2);

	if ( p1_bool & p2_bool ){
		return T;
	}else{
		return F;
	}
}

logic_calculator::logic_calculator(Boolean** init_PQ_table, bool print_table){
	PQ_table = init_PQ_table;

	if (print_table){
		cout << " P | Q " << endl;
		for (int i=0; i<4; i++){
			cout << " " << PQ_table[i][0] << " | " << PQ_table[i][1] << endl;
		}
	}
}

void logic_calculator::cal_conjunction( int * table, bool print_table){

	if ( table == nullptr ){
		for (int i=0; i<4; i++){
			current_answer[i] = conjunction(PQ_table[i][0], PQ_table[i][1]);
		}
	}

}

void logic_calculator::print_curr_table(){
	cout << " Current Table :" << endl;
	for (int i=0; i<4; i++){
		cout <<  current_answer[i] << endl;
	}
}

