import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.List;
import java.util.InputMismatchException;
import java.math.BigInteger;
import java.util.Iterator;
import java.io.*;
import java.util.Comparator;
import java.util.Arrays;
import java.util.Collection;

/**
 * Generated by Contest helper plug-in
 * Actual solution is at the bottom
 */
public class Main {
	public static void main(String[] args) {
		try {
			System.setIn(new FileInputStream("c.in"));
			System.setOut(new PrintStream(new FileOutputStream("c.out")));
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
		InputReader in = new StreamInputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		run(in, out);
	}

	public static void run(InputReader in, PrintWriter out) {
		Solver solver = new TaskC();
		int testCount = in.readInt();
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		Exit.exit(in, out);
	}
}

abstract class InputReader {
	private boolean finished = false;

	public abstract int read();

	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	private boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public void setFinished(boolean finished) {
		this.finished = finished;
	}

	public abstract void close();
}

class StreamInputReader extends InputReader {
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar, numChars;

	public StreamInputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public void close() {
		try {
			stream.close();
		} catch (IOException ignored) {
		}
	}
}

interface Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out);
}

class Exit {
	private Exit() {
	}

	public static void exit(InputReader in, PrintWriter out) {
		in.setFinished(true);
		in.close();
		out.close();
	}
}

class ReverseComparator<T extends Comparable<T>> implements Comparator<T> {
	public int compare(T o1, T o2) {
		return o2.compareTo(o1);
	}
}

class IOUtils {

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	}

class TaskC implements Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int inHand = in.readInt();
		int[] cardPoints = new int[inHand];
		int[] scorePoints = new int[inHand];
		int[] turnPoints = new int[inHand];
		IOUtils.readIntArrays(in, cardPoints, scorePoints, turnPoints);
		int inDeck = in.readInt();
		cardPoints = Arrays.copyOf(cardPoints, inHand + inDeck);
		scorePoints = Arrays.copyOf(scorePoints, inHand + inDeck);
		turnPoints = Arrays.copyOf(turnPoints, inHand + inDeck);
		for (int i = 0; i < inDeck; i++) {
			cardPoints[inHand + i] = in.readInt();
			scorePoints[inHand + i] = in.readInt();
			turnPoints[inHand + i] = in.readInt();
		}
		int time = 1;
		int index = inHand;
		int score = 0;
		PriorityQueue<Integer> noCards = new PriorityQueue<Integer>(inDeck + inHand, new ReverseComparator<Integer>());
		PriorityQueue<Integer> oneCard = new PriorityQueue<Integer>(inDeck + inHand, new ReverseComparator<Integer>());
		for (int i = 0; i < index; i++) {
			if (turnPoints[i] != 0) {
				time += turnPoints[i] - 1;
				if (cardPoints[i] != 0 && index != inDeck + inHand)
					index++;
				score += scorePoints[i];
			} else {
				if (cardPoints[i] == 0)
					noCards.add(scorePoints[i]);
				else
					oneCard.add(scorePoints[i]);
			}
		}
		int maxScore = score;
		while (time != 0) {
			int currentScore = score;
			List<Integer> top = new ArrayList<Integer>();
			for (int i = 0; i < time && !noCards.isEmpty(); i++) {
				int s = noCards.poll();
				currentScore += s;
				top.add(s);
			}
			noCards.addAll(top);
			maxScore = Math.max(maxScore, currentScore);
			if (oneCard.isEmpty())
				break;
			int s = oneCard.poll();
			score += s;
			time--;
			while (index < inDeck + inHand) {
				if (turnPoints[index] == 0) {
					if (cardPoints[index] == 0)
						noCards.add(scorePoints[index]);
					else
						oneCard.add(scorePoints[index]);
					index++;
					break;
				} else {
					score += scorePoints[index];
					time += turnPoints[index] - 1;
					index++;
					if (cardPoints[index - 1] == 0)
						break;
				}
			}
		}
		out.println("Case #" + testNumber + ": " + maxScore);
	}
}

