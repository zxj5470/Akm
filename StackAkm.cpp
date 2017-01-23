#include<iostream>
#include<ctime>
#include"LinkedStack.h"
using namespace std;
int Akm_1(int m, int n){
	if (m == 0)return n + 1;
	if (n == 0)return Akm_1(m - 1, 1);
	else return Akm_1(m - 1, Akm_1(m, n - 1));
}

int Akm_2(int m, int n){
	LinkedStack<int> forM;
	LinkedStack<int> forN;
	int M=m, N = n;
	while (true){
		if (M == 0){
			if (!forM.IsEmpty()){	
				forM.pop();
				forM.getTop(M);
				forN.Pop(N);
				forN.Push(++N);
			}
			else break;
		}
		//case m!=0&&n==0;
		else if (N == 0){
			forM.Pop(M);
			forN.Pop(N);
			forM.Push(--M);
			forN.Push(N = 1);
		}
		//case m!=0&&n!=0
		else {
			if (!forM.IsEmpty()){
				forM.Pop(M);
				forN.Pop(N);
			}
				forM.Push(--M);
				forM.Push(++M);
				forN.Push(--N);
		}
	}
	forN.Pop(N);
	forM.makeEmpty();
	forN.makeEmpty();
	return N;
}

int Akm_3(int m, int n){
	int M, N, result, top = -1;
	int Sm[100000], Sn[100000];
	Sm[++top] = m;
	Sn[top] = n;
	while (true){
		M = Sm[top];
		N = Sn[top];
		top--;
		if (M == 0){
			result = N + 1;
			if (top == -1){break;}
			else {
				Sn[top] = result;
			}
		}
		else if(N==0){
			top++;
			Sm[top] = M - 1;
			Sn[top] = 1;
		}
		else{
			Sm[++top] = M - 1;
			Sm[++top] = M;
			Sn[top] = N - 1;
		}
	}
	return result;
}
//

int main()
{
	//int a=0;
	long a, b;
	for (int i = 0; i < 20; i++){
		a = clock();
		Akm_3(3, 9);
		b= clock();
		cout << (b - a) << "ms" << endl;
	}
	return 0;
}
