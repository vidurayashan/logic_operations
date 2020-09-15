#include <iostream>
#include <string>

enum value{         /* enum newly defined boolean */
    F=0,              /*make F as 0 and T as 1 to make logic operations easy */
    T
};

class Boolean{
public:
	char value;
	
	Boolean(){
		value = F;
	}
	
	Boolean operator!(){
		Boolean ans;
		ans.value = ( this->value == T ) ? F : T;
		return ans;
	}
};

class mylib{
public:

    Boolean conjunction( Boolean &a, Boolean &b);
    Boolean disjunction( Boolean &a, Boolean &b);
    Boolean xjunction  ( Boolean &a, Boolean &b);
	
    void print_table(Boolean * table_p, Boolean * table_q, Boolean * table_ans);

};
