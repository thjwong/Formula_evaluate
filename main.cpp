/**************************
  evaluate roman formula 
***************************/
#include <iostream.h> 
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

#define	FILENAME 		"Formula.txt"
#define FILENAME_LEN 	80
char	dat_filename[FILENAME_LEN];
FILE	*f_ptr;


/****************
1*3,2*3,3*6,4*2,
5*2,6*6,7*6,
*****************/

char operand[3]={'+','-','='};

//typedef vector<int> SELF;

int minusStick(int number){
	switch(number){
	case 1:
		return 0;
	case 2:
		return 1;
	case 3:
		return 2;
	case 4:
		return 5;
	case 5:
		return 0;
	case 6:
		return 5;
	case 7:
		return 6;
	case 8:
		return 7;
	case 9:
		return 10;
	case 10:
		return 0;
	case 11:
		return 10;
	case 12:
		return 11;
	case 13:
		return 12;
	default:
		printf("%d so strange when minus!!!\n", number);
		return 0;
	}
}

int add[1]={0};
int add1[2]  = {2,0};
int add2[2]  = {3,0};
int add3[1]  = {0};
int add4[1]  = {0};
int add5[3]  = {4,6,0};
int add6[2]  = {7,0};
int add7[2]  = {8,0};
int add8[1]  = {0};
int add9[1]  = {0};
int add10[3]  = {9,11,0};
int add11[2]  = {12,0};
int add12[2]  = {13,0};
int add13[1]  = {0};


int *addStick(int number){

	switch(number){
	case 1:
		return add1;
	case 2:
		return add2;
	case 3:
		return add3;
	case 4:
		return add4;
	case 5:
		return add5;
	case 6:
		return add6;
	case 7:
		return add7;
	case 8:
		return add8;
	case 9:
		return add9;
	case 10:
		return add10;
	case 11:
		return add11;
	case 12:
		return add12;
	case 13:
		return add13;
	default:
		printf("%d so strange when add!!!\n", number);
		return add;
	}
}

int self1[1] = {0};
int self2[1] = {0};
int self3[1] = {0};
int self4[3] = {6,9,0};
int self5[2] = {10,0};
int self6[3] = {4,11,0};
int self7[2] = {12,0};
int self8[2] = {13,0};
int self9[3] = {4,11,0};
int self10[2] = {5,0};
int self11[3] = {6,9,0};
int self12[2] = {7,0};
int self13[2] = {8,0};

int* selfStick(int number){
	//SELF self;
	switch(number){
	case 1:
		//self.push_back(0); 
		return self1;
	case 2:
		//self.push_back(0); 
		return self2;
	case 3:
		//self.push_back(0); 
		return self3;
	case 4:
		//self.push_back(6); 
		//self.push_back(9); 
		//self.push_back(0); 
		return self4;
	case 5:
		//self.push_back(10); 
		//self.push_back(0); 
		return self5;
	case 6:
		//self.push_back(4); 
		//self.push_back(11);
		//self.push_back(0); 
		return self6;
	case 7:
		//self.push_back(12); 
		//self.push_back(0); 
		return self7;
	case 8:
		//self.push_back(13); 
		//self.push_back(0); 
		return self8;
	case 9:
		//self.push_back(4); 
		//self.push_back(11); 
		//self.push_back(0); 
		return self9;
	case 10:
		//self.push_back(5); 
		//self.push_back(0); 
		return self10;
	case 11:
		//self.push_back(6); 
		//self.push_back(9); 
		//self.push_back(0); 
		return self11;
	case 12:
		//self.push_back(7); 
		//self.push_back(0); 
		return self12;
	case 13:
		//self.push_back(8); 
		//self.push_back(0); 
		return self13;
	default:
		//self.push_back(0);
		int self[1]={0};
		printf("so strange when self!!!");
		return self;
	}
}


// calculate whether the formula right
int evaluation(int num1, int opr1, int num2, int opr2, int num3) {
	if (operand[opr1] != '=' && operand[opr2] != '='){
		return 1;
	}else if (operand[opr1] == '=' && operand[opr2] == '='){
		if (num1 == num2 && num2 == num3) return 0;
		else return 1;
	}else if (operand[opr1] == '=' && operand[opr2] == '+') {
		if ((num2 + num3) == num1) return 0;
		else return 1;
	}else if (operand[opr1] == '=' && operand[opr2] == '-') {
		if ((num2 - num3) == num1) return 0;
		else return 1;
	}else if (operand[opr1] == '+' && operand[opr2] == '=') {
		if ((num1 + num2) == num3) return 0;
		else return 1;
	}else if (operand[opr1] == '-' && operand[opr2] == '=') {
		if ((num1 - num2) == num3) return 0;
		else return 1;
	}else{
		return 1;
	}
}	


void loopForward(int num1, int opd2, int num3, int opd4, int num5){
	int formula[5]={num1, opd2, num3, opd4, num5};
	int tmp[5];
	int location, otherloc;
	int tmpGive, tmpTake;
	int result = 1;
	for(location = 0; location < 4; location++ ){
		if(location==1||location==3){
			//if "-" do nothing, if "+" or "=" -> "-"
			if(formula[location]==0||formula[location]==2){
				tmpGive = 1;

				for (otherloc = location + 1; otherloc < 5; otherloc++ ){
					if(otherloc==1||otherloc==3){
						if(formula[otherloc]==1){
							tmpTake=0;
							tmp[0] = formula[0];
							tmp[1] = formula[1];
							tmp[2] = formula[2];
							tmp[3] = formula[3];
							tmp[4] = formula[4];
							tmp[location] = tmpGive;
							tmp[otherloc] = tmpTake;
							// check correctness
							result = evaluation(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
							// if correct print
							if (result == 0){
								fprintf(f_ptr,"%d and %d loop forward %d %c %d %c %d is correct!\n", location+1, otherloc+1, tmp[0], operand[tmp[1]], tmp[2], operand[tmp[3]], tmp[4]);
								// reset value
								result = 1;
							}
							tmpTake=2;
							tmp[0] = formula[0];
							tmp[1] = formula[1];
							tmp[2] = formula[2];
							tmp[3] = formula[3];
							tmp[4] = formula[4];
							tmp[location] = tmpGive;
							tmp[otherloc] = tmpTake;
							// check correctness
							result = evaluation(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
							// if correct print
							if (result == 0){
								fprintf(f_ptr,"%d and %d loop forward %d %c %d %c %d is correct!\n", location+1, otherloc+1, tmp[0], operand[tmp[1]], tmp[2], operand[tmp[3]], tmp[4]);
								// reset value
								result = 1;
							}
						}
					}
					else{
						int* tmpAdd = addStick(formula[otherloc]);
						int a=0;
						while(tmpAdd[a]!=0){
							tmpTake = tmpAdd[a];
							tmp[0] = formula[0];
							tmp[1] = formula[1];
							tmp[2] = formula[2];
							tmp[3] = formula[3];
							tmp[4] = formula[4];
							tmp[location] = tmpGive;
							tmp[otherloc] = tmpTake;
							// check correctness
							result = evaluation(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
							// if correct print
							if (result == 0){
								fprintf(f_ptr,"%d and %d loop forward %d %c %d %c %d is correct!\n", location+1, otherloc+1, tmp[0], operand[tmp[1]], tmp[2], operand[tmp[3]], tmp[4]);
							// reset value
								result = 1;
							}
							a++;
						}
					}
				}

			}	// if sign "-", no need to do minus and skip
		}
		else if(location==0||location==2){
			// printf("going to minus %d\n", formula[location]);
			tmpGive = minusStick(formula[location]);
			if(tmpGive != 0){
				
				for (otherloc = location + 1; otherloc < 5; otherloc++ ){
					if(otherloc==1||otherloc==3){
						if(formula[otherloc]==1){
							tmpTake=0;
							tmp[0] = formula[0];
							tmp[1] = formula[1];
							tmp[2] = formula[2];
							tmp[3] = formula[3];
							tmp[4] = formula[4];
							tmp[location] = tmpGive;
							tmp[otherloc] = tmpTake;
							// check correctness
							result = evaluation(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
							// if correct print
							if (result == 0){
								fprintf(f_ptr,"%d and %d loop forward %d %c %d %c %d is correct!\n", location+1, otherloc+1, tmp[0], operand[tmp[1]], tmp[2], operand[tmp[3]], tmp[4]);
								// reset value
								result = 1;
							}
							tmpTake=2;
							tmp[0] = formula[0];
							tmp[1] = formula[1];
							tmp[2] = formula[2];
							tmp[3] = formula[3];
							tmp[4] = formula[4];
							tmp[location] = tmpGive;
							tmp[otherloc] = tmpTake;
							// check correctness
							result = evaluation(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
							// if correct print
							if (result == 0){
								fprintf(f_ptr,"%d and %d loop forward %d %c %d %c %d is correct!\n", location+1, otherloc+1, tmp[0], operand[tmp[1]], tmp[2], operand[tmp[3]], tmp[4]);
								// reset value
								result = 1;
							}
						}
					}
					else{
						int* tmpAdd = addStick(formula[otherloc]);
						int a=0;
						while(tmpAdd[a]!=0){
							tmpTake = tmpAdd[a];
							tmp[0] = formula[0];
							tmp[1] = formula[1];
							tmp[2] = formula[2];
							tmp[3] = formula[3];
							tmp[4] = formula[4];
							tmp[location] = tmpGive;
							tmp[otherloc] = tmpTake;
							// check correctness
							result = evaluation(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
							// if correct print
							if (result == 0){
								fprintf(f_ptr,"%d and %d loop forward %d %c %d %c %d is correct!\n", location+1, otherloc+1, tmp[0], operand[tmp[1]], tmp[2], operand[tmp[3]], tmp[4]);
							// reset value
								result = 1;
							}
							a++;
						}
					}
				}

			}// no need to do minus and skip
		}
	}
	return;
}



void loopBackward(int num1, int opd2, int num3, int opd4, int num5){
	int formula[5]={num1, opd2, num3, opd4, num5};
	int tmp[5];
	int location, otherloc;
	int tmpGive, tmpTake;
	int result = 1;
	for(location = 4; location>0; location-- ){
		if(location==1||location==3){
			//if "-" do nothing, if "+" or "=" -> "-"
			if(formula[location]==0||formula[location]==2){
				tmpGive = 1;

				for (otherloc=location-1; otherloc>=0; otherloc-- ){
					if(otherloc==1||otherloc==3){
						if(formula[otherloc]==1){
							tmpTake=0;
							tmp[0] = formula[0];
							tmp[1] = formula[1];
							tmp[2] = formula[2];
							tmp[3] = formula[3];
							tmp[4] = formula[4];
							tmp[location] = tmpGive;
							tmp[otherloc] = tmpTake;
							// check correctness
							result = evaluation(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
							// if correct print
							if (result == 0){
								fprintf(f_ptr,"%d and %d loop backward %d %c %d %c %d is correct!\n", location+1, otherloc+1, tmp[0], operand[tmp[1]], tmp[2], operand[tmp[3]], tmp[4]);
								// reset value
								result = 1;
							}
							tmpTake=2;
							tmp[0] = formula[0];
							tmp[1] = formula[1];
							tmp[2] = formula[2];
							tmp[3] = formula[3];
							tmp[4] = formula[4];
							tmp[location] = tmpGive;
							tmp[otherloc] = tmpTake;
							// check correctness
							result = evaluation(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
							// if correct print
							if (result == 0){
								fprintf(f_ptr,"%d and %d loop backward %d %c %d %c %d is correct!\n", location+1, otherloc+1, tmp[0], operand[tmp[1]], tmp[2], operand[tmp[3]], tmp[4]);
								// reset value
								result = 1;
							}
						}
					}
					else{
						int* tmpAdd = addStick(formula[otherloc]);
						int a=0;
						while(tmpAdd[a]!=0){
							tmpTake = tmpAdd[a];
							tmp[0] = formula[0];
							tmp[1] = formula[1];
							tmp[2] = formula[2];
							tmp[3] = formula[3];
							tmp[4] = formula[4];
							tmp[location] = tmpGive;
							tmp[otherloc] = tmpTake;
							// check correctness
							result = evaluation(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
							// if correct print
							if (result == 0){
								fprintf(f_ptr,"%d and %d loop backward %d %c %d %c %d is correct!\n", location+1, otherloc+1, tmp[0], operand[tmp[1]], tmp[2], operand[tmp[3]], tmp[4]);
							// reset value
								result = 1;
							}
							a++;
						}
					}
				}

			}	// if sign "-", no need to do minus and skip
		}
		else if(location==0||location==2){
			// printf("going to minus %d\n", formula[location]);
			tmpGive = minusStick(formula[location]);
			if(tmpGive != 0){
				
				for (otherloc=location-1; otherloc>=0; otherloc-- ){
					if(otherloc==1||otherloc==3){
						if(formula[otherloc]==1){
							tmpTake=0;
							tmp[0] = formula[0];
							tmp[1] = formula[1];
							tmp[2] = formula[2];
							tmp[3] = formula[3];
							tmp[4] = formula[4];
							tmp[location] = tmpGive;
							tmp[otherloc] = tmpTake;
							// check correctness
							result = evaluation(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
							// if correct print
							if (result == 0){
								fprintf(f_ptr,"%d and %d loop backward %d %c %d %c %d is correct!\n", location+1, otherloc+1, tmp[0], operand[tmp[1]], tmp[2], operand[tmp[3]], tmp[4]);
								// reset value
								result = 1;
							}
							tmpTake=2;
							tmp[0] = formula[0];
							tmp[1] = formula[1];
							tmp[2] = formula[2];
							tmp[3] = formula[3];
							tmp[4] = formula[4];
							tmp[location] = tmpGive;
							tmp[otherloc] = tmpTake;
							// check correctness
							result = evaluation(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
							// if correct print
							if (result == 0){
								fprintf(f_ptr,"%d and %d loop backward %d %c %d %c %d is correct!\n", location+1, otherloc+1, tmp[0], operand[tmp[1]], tmp[2], operand[tmp[3]], tmp[4]);
								// reset value
								result = 1;
							}
						}
					}
					else{
						int* tmpAdd = addStick(formula[otherloc]);
						int a=0;
						while(tmpAdd[a]!=0){
							tmpTake = tmpAdd[a];
							tmp[0] = formula[0];
							tmp[1] = formula[1];
							tmp[2] = formula[2];
							tmp[3] = formula[3];
							tmp[4] = formula[4];
							tmp[location] = tmpGive;
							tmp[otherloc] = tmpTake;
							// check correctness
							result = evaluation(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
							// if correct print
							if (result == 0){
								fprintf(f_ptr,"%d and %d loop backward %d %c %d %c %d is correct!\n", location+1, otherloc+1, tmp[0], operand[tmp[1]], tmp[2], operand[tmp[3]], tmp[4]);
							// reset value
								result = 1;
							}
							a++;
						}
					}
				}

			}// no need to do minus and skip
		}
	}
	return;
}


void self(int num1, int opr1, int num2, int opr2, int num3) {
	int original, tmp;
	int result=1;
	//printf("the size of vector self 4 is : %d\n", selfStick(4).size();
	if(operand[opr1]=='=' || operand[opr2]=='='){

		//test location1 num1
		int i=0;
		original = num1;
		int* firstSelf=selfStick(original);
		while(firstSelf[i]!=0){
			tmp = firstSelf[i];
			// check correctness
			result = evaluation(tmp, opr1, num2, opr2, num3);
			// if correct print
			if (result == 0){
				fprintf(f_ptr,"1 moving self stick %d %c %d %c %d is correct!\n", tmp, operand[opr1], num2, operand[opr2], num3);
				// reset value
				result = 1;
			}
			i++;
		}

		//test location2 opr1
		original = opr1;
		if (operand[original] == '+' || operand[original] == '=') {
			if (operand[original] == '+') tmp = 2;
			else tmp = 0;
			// check correctness
			result = evaluation(num1, tmp, num2, opr2, num3);
			// if correct print
			if (result == 0)
				fprintf(f_ptr,"2 moving self stick %d %c %d %c %d is correct!\n", num1, operand[tmp], num2, operand[opr2], num3);
			// reset value
			result = 1;
		}

		//test location3 num2
		int j=0;
		original = num2;
		int* thirdSelf=selfStick(original);
		while(thirdSelf[j]!=0){
			tmp = thirdSelf[j];
			// check correctness
			result = evaluation(num1, opr1, tmp, opr2, num3);
			// if correct print
			if (result == 0){
				fprintf(f_ptr,"3 moving self stick %d %c %d %c %d is correct!\n", num1, operand[opr1], tmp, operand[opr2], num3);
				// reset value
				result = 1;
			}
			j++;
		}
		
		//test location4 opr2
		original = opr2;
		if (operand[original] == '+' || operand[original] == '=') {
			if (operand[original] == '+') tmp = 2;
			else tmp = 0;
			// check correctness
			result = evaluation(num1, opr1, num2, tmp, num3);
			// if correct print
			if (result == 0)
				fprintf(f_ptr,"4 moving self stick %d %c %d %c %d is correct!\n", num1, operand[opr1], num2, operand[tmp], num3);
			// reset value
			result = 1;
		}

		//test location5 num3
		int k=0;
		original = num3;
		int* fifthSelf=selfStick(original);
		while(fifthSelf[k]!=0){
			tmp = fifthSelf[k];
			// check correctness
			result = evaluation(num1, opr1, num2, opr2, tmp);
			// if correct print
			if (result == 0){
				fprintf(f_ptr,"5 moving self stick %d %c %d %c %d is correct!\n", num1, operand[opr1], num2, operand[opr2], tmp);
				// reset value
				result = 1;
			}
			k++;
		}
	}
	return;
}

/*
char* genFormula(int num1, int opd2, int num3, int opd4, int num5){
	char* formula;
	switch(num1){
	case 1:
		strcpy(formula, "I");
	case 2:
		strcpy(formula, "II");
	case 3:
		strcpy(formula, "III");
	case 4:
		strcpy(formula, "IV");
	case 5:
		strcpy(formula, "V");
	case 6:
		strcpy(formula, "VI");
	case 7:
		strcpy(formula, "VII");
	case 8:
		strcpy(formula, "VIII");
	case 9:
		strcpy(formula, "IX");
	case 10:
		strcpy(formula, "X");
	case 11:
		strcpy(formula, "XI");
	case 12:
		strcpy(formula, "XII");
	case 13:
		strcpy(formula, "VIII");
	default:
		printf("Strange Formula printed!!!\n");
	}
	switch(opd2){
	case 0:
		strcat(formula, "+");
	case 1:
		strcat(formula, "-");
	case 2:
		strcat(formula, "=");
	}
	switch(num3){
	case 1:
		strcat(formula, "I");
	case 2:
		strcat(formula, "II");
	case 3:
		strcat(formula, "III");
	case 4:
		strcat(formula, "IV");
	case 5:
		strcat(formula, "V");
	case 6:
		strcat(formula, "VI");
	case 7:
		strcat(formula, "VII");
	case 8:
		strcat(formula, "VIII");
	case 9:
		strcat(formula, "IX");
	case 10:
		strcat(formula, "X");
	case 11:
		strcat(formula, "XI");
	case 12:
		strcat(formula, "XII");
	case 13:
		strcat(formula, "VIII");
	default:
		printf("Strange Formula printed!!!\n");
	}
	switch(opd4){
	case 0:
		strcat(formula, "+");
	case 1:
		strcat(formula, "-");
	case 2:
		strcat(formula, "=");
	}
	// strcat(formula, operand[opd4]);
	switch(num5){
	case 1:
		strcat(formula, "I");
	case 2:
		strcat(formula, "II");
	case 3:
		strcat(formula, "III");
	case 4:
		strcat(formula, "IV");
	case 5:
		strcat(formula, "V");
	case 6:
		strcat(formula, "VI");
	case 7:
		strcat(formula, "VII");
	case 8:
		strcat(formula, "VIII");
	case 9:
		strcat(formula, "IX");
	case 10:
		strcat(formula, "X");
	case 11:
		strcat(formula, "XI");
	case 12:
		strcat(formula, "XII");
	case 13:
		strcat(formula, "VIII");
	default:
		printf("Strange Formula printed!!!\n");
	}
	return formula;
}
*/

void main(void){

	int location1, location2, location3, location4, location5;
	for (int a=0; a < FILENAME_LEN; a++) dat_filename[a] = '\0';

	// open data file
	strcpy(dat_filename, FILENAME);
	printf("file %s opening...\n", dat_filename);
	f_ptr = fopen(dat_filename, "w");


	for (location1 = 1; location1 <= 13; location1++) {
		for (location2 = 0; location2 < 3; location2++) {
			for (location3 = 1; location3 <= 13; location3++) {
				for (location4 = 0; location4 < 3; location4++) {
					for (location5 = 1; location5 <= 13; location5++) {

						// check once initially
						if(operand[location2]=='=' || operand[location4]=='='){
							fprintf(f_ptr,"\t The original message is: %d%c%d %c %d \n", location1, operand[location2], location3, operand[location4], location5);
							//fprintf(f_ptr,"\t The original message is: %s \n", genFormula(location1, location2, location3, location4, location5));
							if(evaluation( location1,  location2,  location3,  location4,  location5)==0){
								fprintf(f_ptr,"\t\t%d %c %d %c %d is correct!\n", location1, operand[location2], location3, operand[location4], location5);
							}
							else{
								//self changing position
								self(location1, location2, location3, location4, location5);

								// check add one forward
								loopForward(location1, location2, location3, location4, location5);
								
								// check add one backward
								loopBackward(location1, location2, location3, location4, location5);
							}

						}
					}
				}
			}
		}
	}
	// close file
	fclose(f_ptr);

}