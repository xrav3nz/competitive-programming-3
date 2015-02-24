import java.io.*;
import java.util.*;

class Main {

	public static void main (String[] args) {

		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		int n, input, year, day, month;
		GregorianCalendar cal;
		String sign;

		n = sc.nextInt();

		for (int i = 1; i <= n; ++i) {
			input = sc.nextInt();
			cal = new GregorianCalendar(input % 10000, input / 1000000 - 1, (input / 10000) % 100);
			cal.add(GregorianCalendar.WEEK_OF_MONTH, 40);
			year = cal.get(GregorianCalendar.YEAR);
			month = cal.get(GregorianCalendar.MONTH) + 1;
			day = cal.get(GregorianCalendar.DAY_OF_MONTH);
			sign = GetSign(month, day);
			out.format("%d %02d/%02d/%04d %s\n", i, month, day, year, sign);
		}

		out.close();
	}

	public static String GetSign (int month, int day) {
		switch (month) {
			case 1:
				if (day < 21)
					return "capricorn";
				return "aquarius";
			case 2:
				if (day < 20)
					return "aquarius";
				return "pisces";
			case 3:
				if (day < 21)
					return "pisces";
				return "aries";
			case 4:
				if (day < 21)
					return "aries";
				return "taurus";
			case 5:
				if (day < 22)
					return "taurus";
				return "gemini";
			case 6:
				if (day < 22)
					return "gemini";
				return "cancer";
			case 7:
				if (day < 23)
					return "cancer";
				return "leo";
			case 8:
				if (day < 22)
					return "leo";
				return "virgo";
			case 9:
				if (day < 24)
					return "virgo";
				return "libra";
			case 10:
				if (day < 24)
					return "libra";
				return "scorpio";
			case 11:
				if (day < 23)
					return "scorpio";
				return "sagittarius";
			default:
				if (day < 23)
					return "sagittarius";
				return "capricorn";
		}
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