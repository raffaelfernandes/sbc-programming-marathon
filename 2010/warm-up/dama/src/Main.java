import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int xSrc = 1, ySrc = 1, xTgt = 1, yTgt = 1;
		while (true) {
			xSrc = sc.nextInt();
			ySrc = sc.nextInt();
			xTgt = sc.nextInt();
			yTgt = sc.nextInt();
			if(xSrc == 0 && ySrc == 0 && xTgt == 0 && yTgt == 0){
				break;
			}

			boolean board[][] = new boolean[8][8];
			Position p = new Position(xSrc - 1, ySrc - 1);
			Queen queen = new Queen(p);
			board = queen.PossibleMoves();
			if (xSrc == xTgt && ySrc == yTgt) {
				System.out.println(0);
			} else {
				if (board[xTgt - 1][yTgt - 1] == true) {
					System.out.println(1);
				} else {
					System.out.println(2);
				}
			}
		}
		sc.close();
		return;
	}

}
