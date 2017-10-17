import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()) {
			double x = cin.nextDouble();
			int n = cin.nextInt();
			BigDecimal A = new BigDecimal(x+"").pow(n);
			String s = A.toPlainString();
			if(s.toCharArray()[0]=='0')
				System.out.println(s.substring(1));
			else System.out.println(s);
		}
	}
}
