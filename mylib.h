#include <iostream>

enum Boolean{
    F=0,
    T
};

class logic_calculator{
public:
    logic_calculator(Boolean** init_PQ_table, bool print_table=false);

    void cal_conjunction(  int * table = nullptr, bool print_table = false);
    void cal_disjunction( );
    void cal_negation();
    void cal_xdisjunction();

private:
    Boolean** PQ_table;
    Boolean current_answer[4];
};