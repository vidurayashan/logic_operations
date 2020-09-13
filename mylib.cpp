#include "mylib.h"

/*
Type: Private (not exposed to outside of the class. No one can access this except within the class)
Parameters: Two Boolean values for conjunction.
Return: 
*/
Boolean logic_calculator::conjunction( Boolean p1, Boolean p2 ){
	bool p1_bool = static_cast<bool>(p1);
	bool p2_bool = static_cast<bool>(p2);

	if ( p1_bool & p2_bool ){
		return T;
	}else{
		return F;
	}
}

Boolean logic_calculator::disjunction( Boolean p1, Boolean p2 ){
	bool p1_bool = static_cast<bool>(p1);
	bool p2_bool = static_cast<bool>(p2);

	if ( p1_bool | p2_bool ){
		return T;
	}else{
		return F;
	}
}

Boolean logic_calculator::negation( Boolean p ){
	bool p_bool = static_cast<bool>(p);

	if ( p_bool ){
		return F;
	}else{
		return T;
	}
}

void logic_calculator::cal_disjunction( Boolean * table1, Boolean * table2 , Boolean * answer) {
	for (int i=0; i<4; i++){
		answer[i] = disjunction(table1[i], table2[i]);
	}
}

void logic_calculator::cal_conjunction( Boolean * table1, Boolean * table2 , Boolean * answer) {
	for (int i=0; i<4; i++){
		answer[i] = conjunction(table1[i], table2[i]);
	}
}

void logic_calculator::cal_negation( Boolean * table , Boolean * answer){
	for (int i=0; i<4; i++){
		answer[i] = negation(table[i]);
	}
}

void logic_calculator::print_table(Boolean * table_p, Boolean * table_q, Boolean * table_ans){
        std::cout << "+---------------------+" << std::endl;
        std::cout << "| p | q | Evaluated   |" << std::endl;
        std::cout << "|   |   | expression  |" << std::endl;
        std::cout << "+---------------------+" << std::endl;
        for (int i=0; i<4; i++){
            std::cout << "| " <<  ( (table_p[i] == T) ? 'T': 'F') << " | " << ( (table_q[i] == T) ? 'T': 'F') << " |      " << ( (table_ans[i] == T) ? 'T': 'F') << "      |" << std::endl; 
        }
        std::cout << "+---------------------+" << std::endl << std::endl;
    }

