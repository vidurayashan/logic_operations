#include <iostream>
#include "mylib.h"

using namespace std;

int main(){
	
	Boolean P [4];
    Boolean Q [4];

	P[0] = F;
	P[1] = F;
	P[2] = T;
	P[3] = T;

    Q[0] = F;
	Q[1] = T;
	Q[2] = F;
	Q[3] = T;


    logic_calculator cal;

    Boolean p_and_q[4];
    Boolean p_or_q[4];
    Boolean not_p[4];
    Boolean not_q[4];
    Boolean not_p_or_not_q[4];
    Boolean answer_1[4];

    cal.cal_conjunction( P, Q, p_and_q);
    cout << "Expression: " << "p ^ q" << endl;
    cal.print_table( P, Q, p_and_q);

    cal.cal_disjunction( P, Q, p_or_q);
    cout << "Expression: " << "p V q" << endl;
    cal.print_table( P, Q, p_or_q);

    cal.cal_negation(P, not_p);
	cout << "Expression: " << "~p" << endl;
    cal.print_table( P, Q, not_p);

    cal.cal_negation(Q, not_q);
	cout << "Expression: " << "~q" << endl;
    cal.print_table( P, Q, not_q);
    
    cout << "===============================================" << endl << endl;

    cal.cal_disjunction( not_p, not_q, not_p_or_not_q );
    cout << "Expression: " << "(~p V ~q)" << endl;
    cal.print_table( P, Q, not_q);

    cal.cal_disjunction( p_and_q, not_p_or_not_q, answer_1 );
    cout << "Expression: " << "(p ^ q) V (~p V ~q)" << endl;
    cal.print_table( P, Q, answer_1);

    bool ans_1_tautology = true;
    for (int i=0; i<4; i++){
        if ( answer_1[i] == F ){
            ans_1_tautology = false;
            break;
        }
    }
    

    if (ans_1_tautology){
        cout << "Expression is a tautology" << endl << endl;
    }else{
        cout << "Expression is not a taulology" << endl << endl;
    }

    cout << "===============================================" << endl << endl;

    //Showing that ~p V p is a tautology

    Boolean answer_2[4];
    cal.cal_disjunction(P, not_p, answer_2);
    cout << "Expression: " << "p V ~p" << endl;
    cal.print_table( P, Q, answer_2);

    bool ans_2_tautology = true;
    for (int i=0; i<4; i++){
        if ( answer_2[i] == F ){
            ans_2_tautology = false;
            break;
        }
    }

    if (ans_2_tautology){
        cout << "Expression is a tautology" << endl << endl;
    }else{
        cout << "Expression is not a taulology" << endl << endl;
    }

    cout << "===============================================" << endl << endl;

    cout << "Question 5:" << endl << endl;
    cout << "(a)" << endl;

    //Evaluate ~(p V q) and  (~p V ~q) mentioned in question 5

    Boolean not_p_or_q[4];

    cal.cal_negation(p_or_q, not_p_or_q);
    cout << "Expression: " << "~(p V q)" << endl;
    cal.print_table( P, Q, not_p_or_q);

    Boolean not_p_and_not_q[4];
    cal.cal_conjunction(not_p, not_q, not_p_and_not_q);
    cout << "Expression: " << "(~p ^ ~q)" << endl;
    cal.print_table( P, Q, not_p_and_not_q );

    bool equal_1 = true;
    for (int i=0; i<4; i++){
        if ( not_p_or_q[i] != not_p_and_not_q[i] ){
            equal_1 = false;
            break;
        }
    }
    if (equal_1){
        cout << "The expressions are equal" << endl;
    }else{
        cout << "The expressions are not equal" << endl;
    }

    cout << "===============================================" << endl << endl;

    //Evaluate ~(p ^ q) and ~p V ~q mentioned in question 5

    cout << "(b)" << endl;

    Boolean not_p_and_q[4];

    cal.cal_negation(p_and_q, not_p_and_q);
    cout << "Expression: " << "~(p ^ q)" << endl;
    cal.print_table( P, Q, not_p_and_q);

    cout << "Expression: " << "~p V ~q" << endl;
    cal.print_table( P, Q, not_p_or_not_q);

    bool equal_2 = true;
    for (int i=0; i<4; i++){
        if ( not_p_and_q[i] != not_p_or_not_q[i] ){
            equal_2 = false;
            break;
        }
    }
    if (equal_2){
        cout << "The expressions are equal" << endl;
    }else{
        cout << "The expressions are not equal" << endl;
    }

    cout << "===============================================" << endl << endl;

    cout << "(c)" << endl;

    Boolean not_not_p[4];
    cal.cal_negation(not_p, not_not_p);
    cout << "Expression: " << "~(~p))" << endl;
    cal.print_table(P,Q, not_not_p);

    cout << "Expression: " << "p" << endl;
    cal.print_table(P,Q, P);
    
    bool equal_3 = true;
    for (int i=0; i<4; i++){
        if ( not_not_p[i] != P[i] ){
            equal_3 = false;
            break;
        }
    }
    if (equal_3){
        cout << "The expressions are equal" << endl;
    }else{
        cout << "The expressions are not equal" << endl;
    }

	return 0;
}