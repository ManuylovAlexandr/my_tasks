import style from "./Info.module.css"
import React, {Component} from "react";

class Info extends Component {

    Handler() {
        document.getElementById("information").style.display = "none";
    }

    render() {
        return (
            <div className={style.Info} style={{display: "none"}} id="information">
                <div className={style.Back} onClick={this.Handler}>Вернуться</div>
                <div className={style.Text}>Text info Text info Text info Text info Text info Text info Text info Text
                    info
                </div>
            </div>
        );
    }
}

export default Info;