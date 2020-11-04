import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader;

public class FastIO{
	StringBuilder out;
    InputStreamReader sr;
    BufferedReader br; 
    String [] vals;
    int cnt;
    
    public FastIO() { //CONSTRUTOR
    	out = new StringBuilder();
        sr = new InputStreamReader(System.in);
        br = new BufferedReader(sr); 
        cnt = 0;
    }
    
    public String readLine() throws IOException { //LÊ UMA UMA LINHA DO INPUT E SALVA ELA (TAMBEM RETORNA ELA) OU RETORNA null SE A ENTRADA CHEGAR AO FIM
    	String aux = br.readLine(); 			  //ESSA FUNCAO EH OBRIGATORIA PARA USAR AS FUNCOES NEXT
    	if(aux == null) return null;
    	vals = aux.split(" ");
    	cnt = 0;
    	return aux;
    }
    
    public String next() { //RETORNA PROXIMA STRING DA STRING SALVA POR readLine()
    	return vals[cnt++].intern();
    }
    
    public int nextInt() { //RETORNA PROXIMO INTEIRO DA STRING SALVA POR readLine()
    	return Integer.parseInt(vals[cnt++]);
    }
    
    public void println() { //PRINTA TODO O OUTPUT SALVO (SÓ DEVE SER USADO UMA VEZ, NO FIM DO PROGRAMA) COM UM \n
    	System.out.println(out);
    }
    
    public void print() { //PRINTA TODO O OUTPUT SALVO (SÓ DEVE SER USADO UMA VEZ, NO FIM DO PROGRAMA)
    	System.out.print(out);
    }
    
    //!!!! PARA ADCIONAR ALGO A SER PRINTADO NO FINAL, USE A FUNCAO out.append(), O ARGUMENTO DA FUNCAO FUNCIONA IGUAL A System.out.println() 
    public static void main(String[] args) throws IOException {
    	FastIO IO = new FastIO();
    	// --QUESTÃO-- 
    	// LEIA DUAS LINHAS, CADA UMA COM UMA STRING E UM INTEIRO, SE AS STRINGS FOREM IGUAIS SOME OS INTEIROS, SE DIFERENTES SUBTRAIA OS INTEIROS
    	// INPUT
    	//
    	// Dale 1
    	// Dale 2
    	//
    	// OUTPUT
    	//
    	// 3
    	//
    	// INPUT
    	//
    	// Dale 1
    	// Bale 2
    	//
    	// OUTPUT
    	//
    	// -1
    	
    	IO.readLine();
    	String s1 = IO.next();
    	int i1 = IO.nextInt();
    	
    	IO.readLine();
    	String s2 = IO.next();
    	int i2 = IO.nextInt();
    	
    	IO.out.append("A resposta eh: ");
    	
    	if(s1 == s2) IO.out.append(i1 + i2);
    	else IO.out.append(i1 - i2);
		
    	IO.println();
	}
}
