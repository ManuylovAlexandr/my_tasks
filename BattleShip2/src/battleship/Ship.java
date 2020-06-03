package battleship;

public class Ship {

    private int bowRow;
    private int bowColumn;
    int length;
    private boolean horizontal;
    public boolean[] hit = new boolean[4];

    /**
     * getter
     *
     * @return length
     */
    int getLength() {
        return 1;
    }

    /**
     * getter
     *
     * @return bow row
     */
    public int getBowRow() {
        return bowRow;
    }

    /**
     * getter
     *
     * @return bow column
     */
    public int getBowColumn() {
        return bowColumn;
    }

    /**
     * @return horizontal orientation
     */
    public boolean isHorizontal() {
        return horizontal;
    }

    /**
     * set bow row
     *
     * @param row
     */
    private void setBowRow(int row) {
        bowRow = row;
    }

    /**
     * set bow column
     *
     * @param column
     */
    private void setBowColumn(int column) {
        bowColumn = column;
    }

    /**
     * set horizontal orientation
     *
     * @param horizontal
     */
    private void setHorizontal(boolean horizontal) {
        this.horizontal = horizontal;
    }

    /**
     * Says what kind of ship.
     *
     * @return string with ship type
     */
    public String getShipType() {
        return "abc";
    }

    /**
     * Returns true if it is okay to put a ship of this length with its bow in this location, with the given orientation, and returns false otherwise.
     *
     * @param row
     * @param column
     * @param horizontal
     * @param ocean
     * @return Returns true if it is okay to put a ship in this location, and returns false otherwise.
     */
    boolean okToPlaceShipAt(int row, int column, boolean horizontal, Ocean ocean) {
        //будем считать что числа приходят 0-9
        if (horizontal) {
            if (column + this.length - 1 > 9) return false;

            for (int i = Math.max(0, row - 1); i < Math.min(10, row + 2); i++) {
                for (int j = Math.max(0, column - 1); j < Math.min(10, column + this.length + 1); j++) {
                    if (ocean.isOccupied(i, j)) return false;
                }
            }

            return true;
        } else {
            if (row + this.length - 1 > 9) return false;

            for (int i = Math.max(0, row - 1); i < Math.min(10, row + this.length + 1); i++) {
                for (int j = Math.max(0, column - 1); j < Math.min(10, column + 2); j++) {
                    if (ocean.isOccupied(i, j)) return false;
                }
            }
            return true;
        }
    }

    /**
     * Puts the ship in the ocean.
     *
     * @param row
     * @param column
     * @param horizontal
     * @param ocean
     */
    void placeShipAt(int row, int column, boolean horizontal, Ocean ocean) {
        setBowRow(row);
        setBowColumn(column);
        setHorizontal(horizontal);
        if (horizontal) {
            for (int i = bowColumn; i < bowColumn + length; i++) {
                ocean.ships[bowRow][i] = this;
            }
        } else {
            for (int i = bowRow; i < bowRow + length; i++) {
                ocean.ships[i][bowColumn] = this;
            }
        }
    }

    /**
     * If a part of the ship occupies the given row and column, and the ship hasn't been sunk, mark that part of the ship as "hit" and return true, otherwise return false.
     *
     * @param row
     * @param column
     * @return true if ship hit, otherwise return false
     */
    boolean shootAt(int row, int column) {
        if (this.isSunk()) return false;
        if (horizontal) {
            for (int i = bowColumn; i < bowColumn + length; i++) {
                if (row == bowRow && column == i) {
                    hit[i - bowColumn] = true;
                    return true;
                }
            }
        } else {
            for (int i = bowRow; i < bowRow + length; i++) {
                if (row == i && column == bowColumn) {
                    hit[i - bowRow] = true;
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * @return true if every part of the ship has been hit, false otherwise.
     */
    public boolean isSunk() {
        for (int i = 0; i < hit.length; i++) {
            if (!hit[i]) {
                return false;
            }
        }
        return true;
    }
}
