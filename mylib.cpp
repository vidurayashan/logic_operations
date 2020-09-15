#include "mylib.h"

Boolean mylib::conjunction( Boolean &a, Boolean &b){
		Boolean ans;
		ans.value = ( a.value == T && b.value == T ) ? T : F;
		return ans;
	}
	
Boolean mylib::disjunction( Boolean &a, Boolean &b){
	Boolean ans;
	ans.value = ( a.value == T || b.value == T ) ? T : F;
	return ans;
}

Boolean mylib::xjunction( Boolean &a, Boolean &b){
	Boolean ans;
	ans.value = ( a.value == b.value ) ? F : T;
	return ans;
}

void mylib::print_table(Boolean * table_p, Boolean * table_q, Boolean * table_ans){
        std::cout << "+---------------------+" << std::endl;
        std::cout << "| p | q | Evaluated   |" << std::endl;
        std::cout << "|   |   | expression  |" << std::endl;
        std::cout << "+---------------------+" << std::endl;
        for (int i=0; i<4; i++){
            std::cout << "| " << ( (table_p[i].value == T) ? 'T': 'F') 
				     << " | " << ( (table_q[i].value == T) ? 'T': 'F') << " |      " 
				     <<          ( (table_ans[i].value == T) ? 'T': 'F') << "      |" << std::endl;  /* I have used 3 IF statements. enums cannot be printed to standard output
					                                                                              as it is without an operator overloading. This is a work-around to avoid 
																								  lot of complex code :)
					 																		   */
        }
        std::cout << "+---------------------+" << std::endl << std::endl;
    }
