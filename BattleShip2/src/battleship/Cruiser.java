package battleship;

public class Cruiser extends Ship {

    /**
     * constructor
     */
    Cruiser() {
        length = 3;
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
    public String getShipType() {
        return "cruiser";
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
