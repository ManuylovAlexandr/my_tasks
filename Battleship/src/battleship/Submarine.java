package battleship;

public class Submarine extends Ship {

    /**
     * constructor
     */
    Submarine() {
        length = 1;
        for (int i = 0; i < length; i++) {
            hit[i] = false;
        }
        for (int i = length; i < hit.length; i++) {
            hit[i] = true;
        }
    }

    /**
     * @return string with type of ship
     */
    @Override
    String getShipType() {
        return "submarine ";
    }

    /**
     * @return "x" if ship is sunk, "S" otherwise
     */
    @Override
    public String toString() {
        if (isSunk()) return "x";
        else return "S";
    }
}
