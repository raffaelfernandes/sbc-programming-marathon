public class Queen {
	private Position position;
	
	public Queen(Position position) {
		this.position = position;
	}

	public boolean[][] PossibleMoves() {
		boolean mat[][] = new boolean[8][8];
		Position p = new Position(0, 0);

		// Above
		p.setValues(position.getRow() - 1, position.getColumn());
		while (p.getRow() >= 0) {
			mat[p.getRow()][p.getColumn()] = true;
			p.setRow(p.getRow() - 1);
		}

		// Below
		p.setValues(position.getRow() + 1, position.getColumn());
		while (p.getRow() < 8) {
			mat[p.getRow()][p.getColumn()] = true;
			p.setRow(p.getRow() + 1);
		}

		// Left
		p.setValues(position.getRow(), position.getColumn() - 1);
		while (p.getColumn() >= 0) {
			mat[p.getRow()][p.getColumn()] = true;
			p.setColumn(p.getColumn() - 1);
		}

		// Right
		p.setValues(position.getRow(), position.getColumn() + 1);
		while (p.getColumn() < 8) {
			mat[p.getRow()][p.getColumn()] = true;
			p.setColumn(p.getColumn() + 1);
		}

		// Nw
		p.setValues(position.getRow() - 1, position.getColumn() - 1);
		while (p.getRow() >= 0 && p.getColumn() >= 0) {
			mat[p.getRow()][p.getColumn()] = true;
			p.setValues(p.getRow() - 1, p.getColumn() - 1);
		}

		// Ne
		p.setValues(position.getRow() - 1, position.getColumn() + 1);
		while (p.getRow() >= 0 && p.getColumn() < 8) {
			mat[p.getRow()][p.getColumn()] = true;
			p.setValues(p.getRow() - 1, p.getColumn() + 1);
		}

		// Se
		p.setValues(position.getRow() + 1, position.getColumn() + 1);
		while (p.getRow() < 8 && p.getColumn() < 8) {
			mat[p.getRow()][p.getColumn()] = true;
			p.setValues(p.getRow() + 1, p.getColumn() + 1);
		}

		// Sw
		p.setValues(position.getRow() + 1, position.getColumn() - 1);
		while (p.getRow() < 8 && p.getColumn() >= 0) {
			mat[p.getRow()][p.getColumn()] = true;
			p.setValues(p.getRow() + 1, p.getColumn() - 1);
		}
		
		return mat;
	}
}
