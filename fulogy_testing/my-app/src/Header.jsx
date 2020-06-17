import style from "./Header.module.css";
import React, {Component} from "react";
import logo from "./pics/logo.jpg";
import burger from "./pics/burger.png";
import close from "./pics/close.png";


class Header extends Component {
    constructor(props) {
        super(props);
    }

    render() {
        return (
            <div className={style.Wrapper}>
                <img src={logo} className={style.Logo} alt="logo"/>
                <DDMenu/>
            </div>
        );
    }
}

class DDMenu extends Component {
    constructor(props) {
        super(props);
        this.state = {
            itemsNames: ["Обучающее видео", "Оформеление заказа", "Оплата", "Доставка", "Гарантия", "Возврат", "Контакты", "Партнерам"],
            menuItemsList: []
        }
    }

    showDDMenu = event => {
        const dd = document.getElementById("Dropdown");
        if (dd.style.display === "none") {
            dd.style.display = "block";
            document.getElementById("MenuImage").src=close;
        } else {
            dd.style.display = "none";
            document.getElementById("MenuImage").src=burger;
        }
    };

    render() {
        this.state.menuItemsList = [];
        this.state.itemsNames.forEach((itemName) => {
            this.state.menuItemsList.push(<hr className={style.Separator}/>);
            this.state.menuItemsList.push(<div className={style.MenuItem}><p
                className={style.MenuItemText}>{itemName}</p></div>);
        });
        return (
            <div className={style.DDMenu}>
                <div className={style.MenuHead} onClick={this.showDDMenu}>
                    <img src={burger} alt="menu" id="MenuImage"/>
                </div>
                <div className={style.MenuBody} id="Dropdown" style={{display: "none"}}>
                    {this.state.menuItemsList}
                </div>
            </div>
        );
    }
}

export default Header;