import style from "./Main.module.css";
import React, {Component} from "react";
import kit1 from "./pics/kit1.png";
import kit2 from "./pics/kit2.png";
import kit3 from "./pics/kit3.png";
import tip from "./pics/tip.png";
import sqare from "./pics/sqare.png";


class MainPage extends Component {
    constructor(props) {
        super(props);
    }

    render() {
        return (
            <div className={style.Wrapper}>
                <PhotoBlock/>
                <InfoBlock/>
            </div>
        );
    }
}

class PhotoBlock extends Component {
    constructor(props) {
        super(props);
        this.Handler = this.Handler.bind(this);
        this.state = {
            tippedImage: 1,
            kit: kit1
        };
    }

    async Handler(event) {
        let kits = [kit1, kit2, kit3];
        const Id = Number(event.target.id.slice(-1));
        await this.setState({
            tippedImage: Id,
            kit: kits[Id - 1]
        });
        for (let i = 1; i < 4; i++) {
            if (this.state.tippedImage === i) {
                document.getElementById("sq" + i.toString()).style.opacity = "1";
            } else {
                document.getElementById("sq" + i.toString()).style.opacity = "0.5";
            }
        }
    };


    render() {
        return (
            <div className={style.PhotoBlock}>
                <img src={this.state.kit} alt="" className={style.Kitchen}/>
                <img src={sqare} alt="" className={style.Sq} style={{left: "300px"}} id="sq1" onClick={this.Handler}/>
                <img src={sqare} alt="" className={style.Sq} style={{left: "325px", opacity: "0.5"}} id="sq2"
                     onClick={this.Handler}/>
                <img src={sqare} alt="" className={style.Sq} style={{left: "350px", opacity: "0.5"}} id="sq3"
                     onClick={this.Handler}/>
            </div>
        );
    }
}

class InfoBlock extends Component {
    constructor(props) {
        super(props);
        this.state = {
            tippedImage: 1
        };
        this.Handler = this.Handler.bind(this);
    }

    async Handler(event) {
        const Id = Number(event.target.id.slice(-1));
        await this.setState({
            tippedImage: Id
        });
        for (let i = 1; i < 4; i++) {
            if (this.state.tippedImage === i) {
                document.getElementById(i.toString()).style.display = "block";
            } else {
                document.getElementById(i.toString()).style.display = "none";
            }
        }
    };

    ClickHandler() {
        document.getElementById("information").style.display = "block";
    }

    render() {
        return (
            <div className={style.InfoBlock}>
                <div className={style.InfoWrapper}>
                    <InfoItem name="Класс:" text="Standart" classname={style.InfoItemTextBorder}/>
                    <InfoItem name="Потребляемая мощность:" text="59 Вт." classname=""/>
                    <InfoItem name="Сила света:" text="3459 Люмен = 7,5 ламп накаливания по 40 Вт." classname=""/>
                    <InfoItem name="Гарантия:" text="3 года" classname=""/>
                    <InfoItem name="Монтаж:" text="Да" classname=""/>
                    <InfoItem name="Итого сумма:" text="2549 рублей" classname=""/>
                </div>
                <div className={style.LightColor}>
                    <div className={style.InfoButton} onClick={this.ClickHandler}>
                        i
                    </div>
                    <div className={style.ColorChoose}>
                        Выберете цвет свечения
                    </div>
                </div>
                <div className={style.ImageField}>
                    <div className={style.ImgWrapper} onClick={this.Handler} id="div1">
                        <img src={kit1} className={style.InfoImage} id="img1" alt=""/>
                        <span className={style.ImgText} id="span1">Теплый</span>
                        <img src={tip} className={style.Tip} alt="" id="1" style={{display: "block"}}/>
                    </div>
                    <div className={style.ImgWrapper} onClick={this.Handler} id="div2">
                        <img src={kit2} className={style.InfoImage} id="img2" alt=""/>
                        <span className={style.ImgText} id="span2">Дневной</span>
                        <img src={tip} className={style.Tip} alt="" id="2" style={{display: "none"}}/>
                    </div>
                    <div className={style.ImgWrapper} onClick={this.Handler} id="div3">
                        <img src={kit3} className={style.InfoImage} id="img3" alt=""/>
                        <span className={style.ImgText} id="span3">Холодный</span>
                        <img src={tip} className={style.Tip} alt="" id="3" style={{display: "none"}}/>
                    </div>
                </div>
            </div>
        );
    }
}

function InfoItem(props) {
    return (
        <div className={style.InfoItem}>
            <div className={style.InfoItemName}>
                {props.name}
            </div>
            <div className={style.InfoItemText}>
                <text className={props.classname}>{props.text}</text>
            </div>

        </div>
    );
}

export default MainPage;