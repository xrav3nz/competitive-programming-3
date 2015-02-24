import java.io.*;
import java.util.*;

class Main {

	public static void main (String[] args) {

		MyScanner sc = new MyScanner("input.in");
		out = new PrintWriter(new BufferedOutputStream(System.out));

		GregorianCalendar cal;
		int add = 0, day = 0, month = 0, year = 0;

		while (true) {
			add = sc.nextInt();
			day = sc.nextInt();
			month = sc.nextInt();
			year = sc.nextInt();

			if (add == 0 && day == 0 && month == 0 && year == 0)
				break;

			// java.util.GregorianCalendar counts month from 0 to 11
			cal = new GregorianCalendar(year, month - 1, day);
			cal.add(GregorianCalendar.DAY_OF_MONTH, add);
			out.println(cal.get(GregorianCalendar.DAY_OF_MONTH) + " " + (cal.get(GregorianCalendar.MONTH) + 1) + " " + cal.get(GregorianCalendar.YEAR));
		}

		out.close();
	}

	
	public static PrintWriter out;
	
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;
	
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public MyScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					System.err.println("An IOException was caught!");
	                e.printStackTrace();
				}
			}
			return st.nextToken();
		}
	
		int nextInt() {
			return Integer.parseInt(next());
		}
	
		long nextLong() {
			return Long.parseLong(next());
		}
	
		double nextDouble() {
			return Double.parseDouble(next());
		}
	
		String nextLine(){
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}