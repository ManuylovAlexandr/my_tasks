import style from "./Header.module.css";
import React, {Component} from "react";


class Header extends Component {
    constructor(props) {
        super(props);
    }

    render() {
        return (
            <div className={style.Wrapper}>
                <img src="./pics/logotip.jpg" className={style.Logo}/>
            </div>
        );
    }
}

export default Header;