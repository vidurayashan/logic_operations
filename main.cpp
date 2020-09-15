#include <iostream>
#include "mylib.h"

using namespace std;

int main(){
	
	Boolean P [4];
    Boolean Q [4];

    /*
    There are FOUR possibilities for p and q to be in.
    P and Q arrays will contain all the possibilities P and Q can have. Note P[i] will be in the same state as Q[i] for 0 <= i <= 4
    */
	P[0].value = F;
	P[1].value = F;
	P[2].value = T;
	P[3].value = T;

    Q[0].value = F;
	Q[1].value = T;
	Q[2].value = F;
	Q[3].value = T;
	
	mylib cal;
	
	Boolean p_and_q[4];
    Boolean p_or_q[4];
    Boolean not_p[4];
    Boolean not_q[4];
    Boolean Xor[4];
    Boolean not_p_or_not_q[4];
    Boolean answer_1[4];
    
    cout << "Expression: " << "p ^ q" << endl;
    for (int i=0; i<4; i++){
    	p_and_q[i] = cal.conjunction(P[i], Q[i]);
	}
	cal.print_table( P, Q, p_and_q);
	
	for (int i=0; i<4; i++){
    	p_or_q[i] = cal.disjunction(P[i], Q[i]);
	}
    cout << "Expression: " << "p V q" << endl;
    cal.print_table( P, Q, p_or_q);
	
	for (int i=0; i<4; i++){
    	not_p[i] = !P[i];
	}
	cout << "Expression: " << "~p" << endl;
    cal.print_table( P, Q, not_p);
	
	for (int i=0; i<4; i++){
    	Xor[i] = cal.xjunction(P[i], Q[i]);
	}
	cout << "Expression: " << "xor(p)" << endl;
    cal.print_table( P, Q, Xor);
	
	for (int i=0; i<4; i++){
    	not_q[i] = !Q[i];
	}
    
    cout << "===============================================" << endl << endl;

    /*
    Showing that (p ^ q) V (~p V ~q) is a tautology
    */
	for (int i=0; i<4; i++){
    	not_p_or_not_q[i] = cal.disjunction(not_p[i], not_q[i]);
	}
    cout << "Expression: " << "(~p V ~q)" << endl;
    cal.print_table( P, Q, not_p_or_not_q);
	
	for (int i=0; i<4; i++){
    	answer_1[i] = cal.disjunction(p_and_q[i], not_p_or_not_q[i]);
	}
    cout << "Expression: " << "(p ^ q) V (~p V ~q)" << endl;
    cal.print_table( P, Q, answer_1);

    bool ans_1_tautology = true;
    for (int i=0; i<4; i++){
        if ( answer_1[i].value == F ){
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

    /*
    Showing that ~p V p is a tautology
    */
    
    Boolean answer_2[4];
    for (int i=0; i<4; i++){
    	answer_2[i] = cal.disjunction(P[i], not_p[i]);
	}
    cout << "Expression: " << "p V ~p" << endl;
    cal.print_table( P, Q, answer_2);

    bool ans_2_tautology = true;
    for (int i=0; i<4; i++){
        if ( answer_2[i].value == F ){
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

    /*
    Evaluate ~(p V q) and  (~p V ~q) mentioned in question 5
    */

    Boolean not_p_or_q[4];
    
    for (int i=0; i<4; i++){
    	not_p_or_q[i] = !p_or_q[i];
	}
    cout << "Expression: " << "~(p V q)" << endl;
    cal.print_table( P, Q, not_p_or_q);


    Boolean not_p_and_not_q[4];
    
    for (int i=0; i<4; i++){
    	not_p_and_not_q[i] = cal.conjunction( not_p[i], not_q[i] );
	}
    cout << "Expression: " << "(~p ^ ~q)" << endl;
    cal.print_table( P, Q, not_p_and_not_q );

    bool equal_1 = true;
    for (int i=0; i<4; i++){
        if ( not_p_or_q[i].value != not_p_and_not_q[i].value ){
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

    /*
    Evaluate ~(p ^ q) and ~p V ~q mentioned in question 5
    */

    cout << "(b)" << endl;

    Boolean not_p_and_q[4];
	
	for (int i=0; i<4; i++){
    	not_p_and_q[i] = !p_and_q[i];
	}
    cout << "Expression: " << "~(p ^ q)" << endl;
    cal.print_table( P, Q, not_p_and_q);

    cout << "Expression: " << "~p V ~q" << endl;
    cal.print_table( P, Q, not_p_or_not_q);

    bool equal_2 = true;
    for (int i=0; i<4; i++){
        if ( not_p_and_q[i].value != not_p_or_not_q[i].value ){
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
    for (int i=0; i<4; i++){
    	not_not_p[i] = !not_p[i];
	}
    cout << "Expression: " << "~(~p))" << endl;
    cal.print_table(P,Q, not_not_p);

    cout << "Expression: " << "p" << endl;
    cal.print_table(P,Q, P);
    
    bool equal_3 = true;
    for (int i=0; i<4; i++){
        if ( not_not_p[i].value != P[i].value ){
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

