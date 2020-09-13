#include <iostream>
#include <string>

enum Boolean{         /* enum newly defined boolean */
    F=0,              /*make F as 0 and T as 1 to make logic operations easy */
    T
};

/*
This class contains a set of functions that does logic operations for
TWO given variables.
*/
class logic_calculator{
public:

    void cal_disjunction( Boolean * table1, Boolean * table2 , Boolean * answer);
    void cal_conjunction( Boolean * table1, Boolean * table2 , Boolean * answer);
    void cal_negation( Boolean * table , Boolean * answer);
    void cal_xdisjunction();

    void print_table(Boolean * table_p, Boolean * table_q, Boolean * table_ans);

private:
    Boolean conjunction( Boolean p1, Boolean p2 );
    Boolean disjunction( Boolean p1, Boolean p2 );
    Boolean negation( Boolean p );

};