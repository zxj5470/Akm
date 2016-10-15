import java.util.LinkedList;
public class StackAkm {
	//（2）
	static int Akm_2(int m, int n){
		LinkedList<Integer> forM=new LinkedList<Integer>();
		LinkedList<Integer> forN=new LinkedList<Integer>();
		int M=m, N = n;
		while (true){
			if (M == 0){
				if(!forM.isEmpty()){
					forM.pop();
					if(!forM.isEmpty()){M=forM.getFirst();}
					N=forN.pop();
					forN.push(++N);
				}
				else break;
			}
			//case m!=0&&n==0;
			else if (N == 0){
				M=forM.pop();
				N=forN.pop();
				forM.push(--M);
				forN.push(N = 1);
			}
			//case m!=0&&n!=0
			else {
				if (!forM.isEmpty()){
					M=forM.pop();
					N=forN.pop();
				}
					forM.push(--M);
					forM.push(++M);
					forN.push(--N);
			}
		}
		N=forN.pop();
		return N;
	}
	static int Akm_3(int m, int n){
		int M, N, result, top = -1;
		int Sm[]=new int[100000];
		int Sn[]=new int[100000];
		Sm[++top] = m;
		Sn[top] = n;
		while (true){
			M = Sm[top];
			N = Sn[top];
			top--;
			if (M == 0){
				result = N + 1;
				if (top != -1)Sn[top] = result;
				else break;
			}
			else if(N==0){
				Sm[++top] = M - 1;
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
	
	
	public static void main(String []args){
		long a=0,b=0;
		for(int i=0;i<20;i++){
		a=System.currentTimeMillis();
		Akm_3(3, 9);
		b=System.currentTimeMillis();
		System.out.println(b-a+"ms");
	}
	}
}
