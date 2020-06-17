import React, {Component} from "react";
import style from "./Footer.module.css";


class Footer extends Component {
    constructor(props) {
        super(props);
    }

    render() {
        return (
            <div className={style.Wrapper}>
                <div className={style.Items}>
                    <Item text="Вариант кухни"/>
                    <Item text="Размеры"/>
                    <Item text="Сенсор"/>
                    <Item text="Питающий кабель"/>
                    <Item text="Блок питания"/>
                    <Item text="Цвет свечения"/>
                    <Item text="Монтаж"/>
                    <Item text="Корзина"/>
                </div>
            </div>
        );
    }
}

function Item(props) {
    return (
        <div className={style.Item}>
            {props.text}
        </div>
    )
}

export default Footer;