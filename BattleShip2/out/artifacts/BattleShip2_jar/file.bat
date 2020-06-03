@echo off
set /p Input=Enter input javafx lib path: 
java --module-path "%Input%" --add-modules=javafx.controls,javafx.fxml -jar BattleShip2.jar