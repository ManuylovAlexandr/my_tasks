package battleship;

public class EmptySea extends Ship {

    /**
     * constructor
     */
    EmptySea() {
        length = 1;
    }

    /**
     * @param row
     * @param column
     * @return false always
     */
    @Override
    boolean shootAt(int row, int column) {
        hit[0] = true;
        return false;
    }

    /**
     * @return false always
     */
    @Override
    boolean isSunk() {
        return false;
    }

    /**
     * @return "-" if place is hit, "." otherwise
     */
    @Override
    public String toString() {
        if (hit[0]) return "-";
        else return ".";
    }
}
