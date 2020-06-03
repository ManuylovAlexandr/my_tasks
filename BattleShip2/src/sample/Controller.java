package sample;

import battleship.Ocean;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.GridPane;

public class Controller {
    @FXML
    public AnchorPane root;
    @FXML
    public GridPane battle_field;
    @FXML
    public TextArea InformArea;
    @FXML
    public TextArea LogArea;
    @FXML
    public TextField input;
    @FXML
    public Button input_btn;

    private Ocean ocean;
    private int shipsSunk, x, y;

    /**
     * метод вызывается после каждого выстрела для обновления информационной панели
     */
    private void updateInformationArea() {
        InformArea.setText("number of shots fired = " + ocean.getShotsFired() + '\n' +
                "number of ships sunk = " + ocean.getShipsSunk());
    }

    /**
     * метод вызова алерта с оповещением о неккоректном действии во время игры
     * @param text
     */
    private void showAlert(String text) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Message");
        alert.setHeaderText(null);
        alert.setContentText(text);
        alert.setHeight(200);
        alert.showAndWait();
    }

    /**
     * метод перерисовки поля после потопления корабля
     * необходим, так как требуется изменить цвет подбитых клеток с желтого на красный
     * @param row
     * @param column
     */
    private void redrawField(int row, int column) {
        LogArea.setText(LogArea.getText() + "You just sank a " + ocean.getShipArray()[row][column].getShipType() + '\n' + '\n');
        shipsSunk++;
        for (int i = 0; i < battle_field.getChildren().size(); i++) {
            int c = Integer.parseInt(battle_field.getChildren().get(i).idProperty().getValue().substring(0, 1));
            int r = Integer.parseInt(battle_field.getChildren().get(i).idProperty().getValue().substring(2));
            if (ocean.getShipArray()[r][c].isSunk())
                battle_field.getChildren().get(i).setStyle("-fx-background-color: red");
        }
    }

    /**
     * выстрел по клетке, обозначаемой кнопкой
     * @param btn
     */
    private void shoot(Button btn) {
        int column = Integer.parseInt(btn.idProperty().getValue().substring(0, 1));
        int row = Integer.parseInt(btn.idProperty().getValue().substring(2));
        if (!btn.getStyle().substring(22).equals("none")) {
            showAlert("You already shoot at this place!");
            return;
        }
        boolean isHit = ocean.shootAt(row, column);
        LogArea.setText(LogArea.getText() + "You just shot at row: " + row + " ,column: " + column + '\n');
        if (shipsSunk != ocean.getShipsSunk()) {
            redrawField(row, column);
        } else if (isHit) {
            btn.setStyle("-fx-background-color: yellow");
            LogArea.setText(LogArea.getText() + "You hit a ship" + '\n' + '\n');
        } else {
            btn.setStyle("-fx-background-color: grey");
            LogArea.setText(LogArea.getText() + "You miss" + '\n' + '\n');
        }
        updateInformationArea();
        if (ocean.isGameOver()) {
            for (int i = 0; i < battle_field.getChildren().size(); i++)
                battle_field.getChildren().get(i).setDisable(true);
            LogArea.setText(LogArea.getText() + "Game over \n You hit the ships " + ocean.getHitCount() + " times.");
        }
    }

    @FXML
    private void click(ActionEvent event) {
        shoot((Button) event.getSource());
    }

    /**
     * Начало игры, или обновление поля и начало игры
     * @param actionEvent
     */
    @FXML
    public void play(ActionEvent actionEvent) {
        input_btn.setDisable(false);
        ocean = new Ocean();
        shipsSunk = ocean.getShipsSunk();
        InformArea.setText("");
        LogArea.setText("");
        ocean.placeAllShipsRandomly();
        for (int i = 0; i < battle_field.getChildren().size(); i++) {
            battle_field.getChildren().get(i).setDisable(false);
            battle_field.getChildren().get(i).setStyle("-fx-background-color: none");
        }
        input.setOnKeyPressed(keyEvent -> {
            if (keyEvent.getCode() == KeyCode.ENTER) {
                shootBtnClick(new ActionEvent());
            }
        });
    }

    /**
     * нажатие на кнопку выстрела из текстовово поля
     * @param actionEvent
     */
    @FXML
    public void shootBtnClick(ActionEvent actionEvent) {
        if (parseInput(input.getText()))
            for (int i = 0; i < battle_field.getChildren().size(); i++)
                if (battle_field.getChildren().get(i).getId().equals(x + "_" + y) &&
                        !battle_field.getChildren().get(i).disableProperty().getValue())
                    shoot((Button) battle_field.getChildren().get(i));
    }

    /**
     * вспомогательный метод для определения корректности входной строки и ее парсинга
     * @param text
     * @return
     */
    private boolean parseInput(String text) {
        if (text.length() == 3 && text.substring(1, 2).equals(" ")) {
            try {
                x = Integer.parseInt(text.substring(0, 1));
                y = Integer.parseInt(text.substring(2));
                return true;
            } catch (Exception ex) {
                showAlert("Two values are expected separated by a space in the format <row> <column> " +
                        "where <row> and <column> must be integers from 0 to 9");
                return false;
            }
        }
        showAlert("Two values are expected separated by a space in the format <row> <column> " +
                "where <row> and <column> must be integers from 0 to 9");
        return false;
    }
}
